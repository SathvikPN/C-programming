/* 
 * Basic Calculator using Queues and Stack
 * Add Subtract Multiply Divide Negate
 * Parse space delimited infix expression string
 * Convert to Postfix expression and evaluate
 * @SathvikPN project-to-learn-C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* maximum length of input string (including newline character) */
#define INPUT_MAX 2048

/* enable (1) or disable (0) parentheses checking in parsing strings */
#define PARSE_PARENS 0

/* boolean values */
// typedef enum{false, true} bool;

/* type of token */
enum token_type {
    OPERAND, /* number */
    OPERATOR, /* {+,-,*,/} */
#if PARSE_PARENS
	LPARENS, /* left parentheses ( */
	RPARENS /* right parentheses ) */
#endif 
}; 
/* USE-CASE
 * enum token_type type;  
 * type = OPERAND 
*/

/* operator identifiers (opcodes) */
enum op {
	ADD, /* a+b */
	SUBTRACT, /* a-b (binary) */ 
	MULTIPLY, /* a*b */
	DIVIDE, /* a/b */
	NEGATE /* -a (unary) */   
};
/* USE-CASE
 * enum op op_code; 
 * op_code = ADD 
 */

/* direction of evaluation (associativity) */
enum assoc {
	LEFT, /* left-to-right (+, binary -, *, /) */
	RIGHT /* right-to-left (unary -) */
};
/* Right associativity: a=b=c --> a=(b=c) */

/* number of operands for each operator type */
const unsigned int op_operands[] = {2, 2, 2, 2, 1};
/* op_operand[NEGATE] = 1 */

/* order-of-operations (precedence) (0 = evaluated last) */
const unsigned int op_precedences[] = {0, 0, 1, 1, 2};

/* evaluation direction (associativity) for each precedence level */
const enum assoc op_associativity[] = {LEFT, LEFT, RIGHT};

/* contains value of token */
union token_value {
	double operand; /* numeric value for operand */
	enum op op_code; /* opcode for operators */
};
/* USE-CASE
 * union token_value value;
 * value = ADD; (OR value=2)
 */

/* 
 * DATA-STRUCTURES for token, queue, stack ------------------------------------------
 */

/* data structure for token: linked-list node structure */
typedef struct s_expr_token {
    enum token_type type; /* type of token */
    union token_value value; /* numeric value or opcode */
    struct s_expr_token * linked_token; /* linked token in stack/queue */
} * p_expr_token;
/* 
 * p_expr_token is shorthand for 
 * "struct s_expr_token* <==> p_expr_token "
 */

/* data structure for queue */
struct token_queue {
	p_expr_token front; /* front of queue, where tokens are dequeued */
	p_expr_token back; /* back of queue, where tokens are added */
};

/* queue functions - enqueue and dequeue */
void enqueue(struct token_queue * pqueue, const p_expr_token ptoken);
p_expr_token dequeue(struct token_queue * pqueue);



/* stack functions - push and pop */
void push(p_expr_token * ptop, const p_expr_token ptoken);
p_expr_token pop(p_expr_token * ptop);



/* creates a new token in dynamic memory (using malloc()) */
p_expr_token new_token(const enum token_type type, const union token_value value);

/* constructs a queue of tokens in infix order from a space-delimited string */
struct token_queue expr_to_infix(char * str);



/* creates a queue of tokens in postfix order from a queue of tokens in infix order */
/* postcondition: returned queue contains all the tokens, and 
   pqueue_infix SHOULD BE EMPTY */
struct token_queue infix_to_postfix(struct token_queue * pqueue_infix);



/* evalutes the postfix expression stored in the queue */
/* postcondition: returned value is final answer, and 
   pqueue_postfix SHOULD BE EMPTY */
double evaluate_postfix(struct token_queue * pqueue_postfix);



/* handles evaluation process (calls above functions) for expression string str */
double evaluate(const char * str);



/* DRIVER CODE ------------------------------------------------------------------------------- */
int main()
{
    char input[INPUT_MAX]; 
    double ans;
    unsigned int len;

    do {
        printf("Enter arithmetic expression: ");
        fflush(stdout); /* https://stackoverflow.com/a/16781056 */

        /* see appendix */
        if(!fgets(input, INPUT_MAX, stdin))
        {
            puts("failed to read stdin. ABORTED");
            abort(); /* see abort() vs exit() */
        }

        len = strlen(input);

        /* remove trailing newline character */
		if (len > 0 && input[len-1] == '\n') 
        {
			input[len-1] = '\0';
			--len;
		}

        /* empty expression signals exit */
		if (len == 0) 
		{
            puts("read input string length is ZERO");
            break;
        }
        
		/* call evaluation functions */
		ans = evaluate(input);
		/* write result to stdout */
		printf("[INFIX] %s => %g [EVALUATED]\n", input, ans);

    } while(1);

    return 0;
}




/* FUNCTION DEFINITIONS -----------------------------------------*/

/* enqueue (add) token to end of queue
   input: pqueue - pointer to queue
          ptoken - token pointer to add
   postcondition: token added to end of queue */
void enqueue(struct token_queue * pqueue, const p_expr_token ptoken)
{
    ptoken->linked_token = NULL;
    if (pqueue->back)
        (pqueue->back)->linked_token = ptoken;
    else /* empty queue */
        pqueue->front = ptoken;
    pqueue->back = ptoken;
}

/* dequeue (remove) token from front of queue
   input: pointer to queue
   output: front token pointer (or NULL, if queue was empty)
   postcondition: token removed from queue */
p_expr_token dequeue(struct token_queue * pqueue)
{
    p_expr_token ptoken = pqueue->front;
    if(pqueue->front)
    {
        pqueue->front = (pqueue->front)->linked_token;
        /* if dequeued a single node queue */
        if(ptoken == pqueue->back)
            pqueue->back = NULL;
        
        /* detach dequeued token from queue */
        ptoken->linked_token = NULL;
    }
    return ptoken;
}

/* push (add) token to top of stack
   input: ptop - pointer to top token pointer of stack
          ptoken - token pointer to add
   postcondition: ptop points to the added token */
void push(p_expr_token * ptop, const p_expr_token ptoken)
{
    ptoken->linked_token = *ptop;
    *ptop = ptoken;
}

/* pop (remove) token from top of stack 
   input: pointer to top token pointer of stack
   output: top token pointer (or NULL, if stack was empty)
   postcondition: ptop points to next token in stack */
p_expr_token pop(p_expr_token * ptop)
{
    p_expr_token ptoken;
    ptoken = *ptop;
    if(*ptop)
    {
        *ptop = (*ptop)->linked_token;
        ptoken->linked_token = NULL;
    }
    return ptoken;
}

/* allocate new token on heap, with specified type and value; the token is initially
   un-linked (field "linked_token" == NULL) 
   note: token must be freed using free() after use */
p_expr_token new_token(const enum token_type type, const union token_value value)
{
    p_expr_token ptoken = (p_expr_token)malloc(sizeof(struct s_expr_token));
    ptoken->type = type;
    ptoken->value = value;
    ptoken->linked_token = NULL;
    return ptoken;
}

/* handles evaluation process (calls above functions) for expression string str */
/* returns the final answer */
double evaluate(const char * str)
{
    char * strbuffer; /* mutable buffer for string (modified in calls to strtok()) */
    double ans;
    struct token_queue queue_infix, queue_postfix;

	/* copy str into mutable buffer */
	strbuffer = strcpy((char *)malloc(strlen(str)+1),str);

	/* get queue of tokens in infix order from string buffer */
	queue_infix = expr_to_infix(strbuffer);

	/* get queue of tokens in postfix order from infix-ordered queue */
	queue_postfix = infix_to_postfix(&queue_infix);

	/* get answer from postfix-ordered queue */
	ans = evaluate_postfix(&queue_postfix);

	free(strbuffer); /* free memory from heap */
	return ans;
}



/* constructs a queue of tokens in infix order from a space-delimited string */
struct token_queue expr_to_infix(char * str) {
	struct token_queue queue_infix; /* queue with infix ordering */
	enum token_type type = OPERATOR;
	union token_value value;

	/* initialize the queue to empty */
	queue_infix.front = NULL;
	queue_infix.back = NULL;

	/* delimiter string for strtok() -- contains whitespace characters */
#define DELIMS_STR " \n\r\t"
	for (str = strtok(str, DELIMS_STR); str!=NULL; str = strtok(NULL, DELIMS_STR)) {
		/* parse token */
		if (strlen(str) == 1) { /* operators are all 1 character */
			switch (str[0]) {
			case '+':
				type = OPERATOR;
				value.op_code = ADD;
				break;
			case '-':
				/* check previous token to distinguish between
				   negate (unary) and subtract (binary) */
				if (type == OPERATOR)
					value.op_code = NEGATE; /* unary */
#if PARSE_PARENS
				else if (type == LPARENS)
					value.op_code = NEGATE; /* unary */
#endif
				else
					value.op_code = SUBTRACT; /* binary */
				type = OPERATOR;
				break;
			case '*':
				type = OPERATOR;
				value.op_code = MULTIPLY;
				break;
			case '/':
				type = OPERATOR;
				value.op_code = DIVIDE;
				break;
#if PARSE_PARENS
			case '(':
				type = LPARENS;
				break;
			case ')':
				type = RPARENS;
				break;
#endif
			default:
				/* not an operator */
				type = OPERAND;
				value.operand = strtod(str, NULL);
			}
		} else {
			type = OPERAND;
			value.operand = strtod(str, NULL);
		}
		/* add token with parsed type and value to end of queue */
		enqueue(&queue_infix, new_token(type, value));
	}
	return queue_infix;
}

/* creates a queue of tokens in postfix order from a queue of tokens in infix order */
/* postcondition: returned queue contains all the tokens, and 
   pqueue_infix SHOULD BE EMPTY */
struct token_queue infix_to_postfix(struct token_queue * pqueue_infix) 
{
	/* TODO: construct postfix-ordered queue from infix-ordered queue;
	   all tokens from infix queue should be added to postfix queue or freed */
    
    /* init output queue containing postfix expression */
    struct token_queue pqueue_postfix;
    pqueue_postfix.front = NULL;
    pqueue_postfix.back = NULL;

    /* init operator stack */
    p_expr_token* ptop;
    ptop = NULL;

    p_expr_token ptoken;
    int condition1, condition2;
    int precedence_top, precedence_token;

    while( ptoken = dequeue(pqueue_infix) )
    {
        /* process */
        if((ptoken->type) == OPERAND)
            enqueue(&pqueue_postfix, ptoken);
        
        else if ((ptoken->type) == OPERATOR)
        {
            precedence_top = op_precedences[((*ptop)->value).op_code];
            precedence_token = op_precedences[(ptoken->value).op_code];
            condition1 = (int)(precedence_top > precedence_token);
            condition2 = (int)((precedence_top==precedence_token) && op_associativity[precedence_top]);

            while(ptop && (condition1 || condition2))
            {
                p_expr_token ptop_op = pop(ptop);
                enqueue(&pqueue_postfix, ptop_op);
            }
            push(ptop, ptoken);
        }
    }

    while(ptoken = pop(ptop))
        enqueue(&pqueue_postfix, ptoken);

    /* clean up infix queue, no longer needed */
    // free(pqueue_infix);
    return pqueue_postfix;
}

/* evalutes the postfix expression stored in the queue */
/* postcondition: returned value is final answer, and pqueue_postfix should be empty */
double evaluate_postfix(struct token_queue * pqueue_postfix) {
	/* TODO: process postfix-ordered queue and return final answer;
	   all tokens from postfix-ordered queue is freed */

    /* init operator stack */
    p_expr_token* ptop;
    ptop = NULL;

    p_expr_token ptoken;
    while(ptoken = dequeue(pqueue_postfix))
    {
        if((ptoken->type) == OPERAND)
            push(ptop, ptoken);
        
        else if((ptoken->type) == OPERATOR)
        {
            // int operands_count = op_operands[OPERATOR];
            // int operands[operands_count];
            // for(int i=0; i<operands_count; i++)
            //     operands[i] = pop(ptop);
            
            double result;
            double operands[2];
            switch ((ptoken->value).op_code)
            {
            case ADD:
                /* IMPORTANT: ORDERING of popped elements for evaluation */
                operands[1] = ((pop(ptop))->value.operand);
                operands[0] = ((pop(ptop))->value.operand);
                result = operands[0] + operands[1];
                break;
            
            case SUBTRACT:
                operands[1] = ((pop(ptop))->value.operand);
                operands[0] = ((pop(ptop))->value.operand);
                result = operands[0] - operands[1];
                break;

            case MULTIPLY:
                operands[1] = ((pop(ptop))->value.operand);
                operands[0] = ((pop(ptop))->value.operand);
                result = operands[0] * operands[1];
                break;

            case DIVIDE:
                operands[1] = ((pop(ptop))->value.operand);
                operands[0] = ((pop(ptop))->value.operand);
                result = operands[0] / operands[1];
                break;

            case NEGATE:
                result = (-1) * ((pop(ptop))->value.operand);
            
            default:
                puts("Misconfigured opcode of Token");
                abort();
            }
        union token_value value;
        value.operand = result;
        p_expr_token ptoken_result = new_token(OPERAND, value);
        push(ptop, ptoken_result);
        }
    }
    // free(pqueue_postfix);
    return (*ptop)->value.operand;
}

/* QUICK REFERENCES -----------------------------------------
[1] fgets
    char *fgets(char *str, int n, FILE *stream) 
    reads a line from the specified stream and 
    stores it into the string pointed to by str. 
    It stops when either (n-1) characters are read, 
    the newline character is read, or 
    the end-of-file is reached, whichever comes first.
[2] strtok
    char *strtok(char *str, const char *delim) 
    breaks string str into a series of tokens using the delimiter 
    delim.
    The first call to strtok must pass the C string to tokenize, and subsequent calls must specify NULL as the first argument, which tells the function to continue tokenizing the string you passed in first.
    strtok() stores the pointer in static variable where did you last time left off , so on its 2nd call , when we pass the null , strtok() gets the pointer from the static variable.(multithreaded see strtok_r())

[3] strtod
    parse string to double and store pointer to rest of string in second param
*/

/* https://www.hackerrank.com/challenges/structuring-the-document/problem */
/* USE_CASE: 
[sample input]
2 
Learning C is fun.
Learning pointers is more fun.It is good to have pointers.
3               {loop counter}
1 2             {1_param_type: kth paragraph}
2 1 1           {2_param_type: kth sentence in mth paragraph}
3 1 1 1         {3_param_type: kth word in mth sentence in nth paragraph}

[sample output]
Learning pointers is more fun.It is good to have pointers.
Learning C is fun
Learning
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

/* User defined data structures -------------------------------------------------------------------*/
struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};


/* Utility Methods -------------------------------------------------------------------------------------------- */

void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++){
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
}

char** split_string(char* text, char delim)
{
    assert(text!=NULL);
    char **result = malloc(1);
    int len = 0;
    char *stoken = strtok(text, &delim);
    while(stoken)
    {
        len++;
        result = realloc(result, len * sizeof(char*));
        result[len-1] = stoken;
        stoken = strtok(NULL, &delim);
    }

    /* Null terminate */
    len++;
    result = realloc(result, len * sizeof(char*));
    result[len-1] = NULL;
    return result;
}


/* Process Doc --------------------------------------------------------------------------------------------------- */

struct document get_document(char* text) {
    struct document doc;
    char **ptokens = split_string(text, '\n');
    int plen = 0;
    while(ptokens[plen])
        plen++;
    
    doc.paragraph_count = plen;
    doc.data = malloc(plen * sizeof(struct paragraph));
    
    /* process paragraphs */
    for(int p=0; ptokens[p]!=NULL; p++)
    {
        struct paragraph para;
        char **stokens = split_string(ptokens[p], '.');
        int slen = 0;
        while(stokens[slen])
            slen++;
        
        para.sentence_count = slen;
        para.data = malloc(slen * sizeof(struct sentence));

        for(int s=0; stokens[s]!=NULL; s++)
        {
            struct sentence sen;
            char **wtokens = split_string(stokens[s], ' ');
            int wlen = 0;
            while(wtokens[wlen])
                wlen++;

            sen.word_count = wlen;
            sen.data = malloc(wlen * sizeof(struct word));

            for(int w=0; wtokens[w]!=NULL; w++)
            {
                struct word the_word;
                the_word.data = wtokens[w];
                sen.data[w] = the_word;
            }
            para.data[s] = sen;
        }

        doc.data[p] = para;
    }
    return doc;

}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[n-1].data[m-1].data[k-1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 
    return Doc.data[m-1].data[k-1];
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k-1];
}



/* IO Processing ---------------------------------------------------------------------------------------- */

char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

int main() 
{
    char* text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else{
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }     
}


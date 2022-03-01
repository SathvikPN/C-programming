/* Stack Implementation using linked list (dynamic memory allocation) */
#include<stdio.h>
#include<stdlib.h>

struct s_listnode
{
    int element;
    struct s_listnode *pnext;
};

struct s_listnode *stack_buffer = NULL; // start empty

/*  NULL <-- Node1 <-- Node2 <-- stack_buffer   */

void push(int elem)
{
    struct s_listnode *new_node = (struct s_listnode*)malloc(sizeof(struct s_listnode));
    new_node->element = elem;
    new_node->pnext = stack_buffer;
    stack_buffer = new_node;
}

int pop()
{
    if(stack_buffer)
    {
        struct s_listnode *pelem = stack_buffer;
        int elem = stack_buffer->element;
        stack_buffer = pelem->pnext;
        free(pelem); // remove node from the memory
        return elem;
    }
    else
    {
        return 0; /* or other special value */
    }
}

int main()
{
    push(1);
    push(2);
    push(3);
    printf("%d ", pop());
    printf("%d ", pop());
    return 0;
}


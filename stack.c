#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* pnext;
};

struct node* stack_top = NULL;
/* stack -> e1 -> e2 -> NULL */

void push(int data);
int pop();

int main()
{
    push(1);
    push(2);
    while(stack_top!=NULL)
        printf("%d ", pop());
    pop();
    return 0;
}

void push(int data)
{
    struct node* new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->pnext = stack_top;
    stack_top = new_node;
}

int pop()
{
    if (stack_top==NULL)
    {
        puts("pop() on empty stack");
        exit(1);
    }

    struct node* del_node = stack_top;
    stack_top = stack_top->pnext;

    int data = del_node->data;
    free(del_node);
    return data;
}
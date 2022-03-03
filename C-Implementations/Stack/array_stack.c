/* Stack Implementation using array buffer (static allocation) */
#include<stdio.h>
#include<stdlib.h>

#define BUFFER_SIZE 100

int stack_buffer[BUFFER_SIZE];
int itop=0; // end at zero. Initialised for empty stack

void push(int);
int pop();

int main()
{
    for(int i=1; i<=5; i++)
        push(i);
    
    printf("%d ", pop());
    printf("%d ", pop());
    printf("%d ", pop());
}

void push(int elem)
{
    stack_buffer[itop++] = elem;
    return;
}

int pop()
{
    if (itop>0)
        return stack_buffer[--itop];

    else
        return 0; // or other special value
}

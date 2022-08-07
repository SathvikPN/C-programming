#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* pnext;
};

/* (dequeue) e1->e2->e3->NULL */
struct node *front = NULL, *back = NULL;

void enqueue(int data);
int dequeue();

int main()
{
    enqueue(1);
    enqueue(2);
    printf("%d ", dequeue());
    printf("%d ", dequeue());
    enqueue(38);
    printf("%d ", dequeue());
    // printf("%d ", dequeue());
    return 0;
}

void enqueue(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->pnext = NULL;
    if(back)
    {
        back->pnext = new_node;
        back = new_node;
    }
    else
        front = back = new_node;
}

int dequeue()
{
    if(front==NULL)
    {
        puts("dequeue() on empty queue");
        exit(1);
    }

    int data = front->data;
    struct node* del_node = front;
    if(del_node->pnext == NULL)
        back = NULL;
    front = front->pnext;
    free(del_node);
    return data;
}
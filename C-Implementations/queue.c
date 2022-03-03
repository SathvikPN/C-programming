/* Queue Implementation using linked list (dynamic allocation) */
#include<stdio.h>
#include<stdlib.h>

struct s_listnode
{
    float element;
    struct s_listnode *pnext;
};

struct s_listnode *queue_buffer = NULL;  //start empty

struct s_listnode *prear = NULL;

/* queue_buffer <-- node1 <-- node2 <-- prear */
void enqueue(float elem)
{
    struct s_listnode *new_node = (struct s_listnode*)malloc(sizeof(struct s_listnode));
    new_node->element = elem;
    new_node->pnext = NULL; // at reat

    if (prear)
        prear->pnext = new_node;
    else
        queue_buffer = new_node;
    
    prear = new_node;
}

float dequeue()
{
    if(queue_buffer)
    {
        struct s_listnode *pelem = queue_buffer; // save reference to return 
        float elem = queue_buffer->element;
        queue_buffer = pelem->pnext;

        if(pelem==prear)
            prear = NULL;
        
        free(pelem); /* remove node from memory */
        return elem;
    }
    else
    {
        return 0; /* or other special value */
    }
}

/* Removing element doesn’t affect rear unless resulting
queue is empty */


int main()
{
    for(float i=1; i<=5; i++)
        enqueue(i);
    
    printf("%.1f \n", dequeue());
    printf("%.1f \n", dequeue());
    printf("%.1f \n", dequeue());
}

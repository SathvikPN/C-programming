#include <stdio.h>
#include <stdlib.h> /* malloc */
struct node
{
    int data;
    struct node* next;
};

struct node* head=NULL;
struct node* make_node(int data);
void display(struct node* head);

/* modify head pointer. so pass address of head pointer*/
struct node* addfront(int data, struct node** head); 
struct node* addback(int data, struct node** head); /* unmodified head. for pattern only*/

struct node* find(int data, struct node* head);


int main()
{
    int val=5;
    struct node* address;
    addfront(2, &head);
    addfront(3, &head);
    addback(1, &head);
    addback(5, &head);
    display(head);
    address = find(val, head);
    return 0;
}

struct node* make_node(int data)
{
    struct node* pnode = (struct node*)malloc(sizeof(struct node));
    if(pnode==NULL)
    {
        puts("Unable to make_node");
        exit(1);
    }
    pnode->data = data;
    pnode->next = NULL;
    return pnode;
}

struct node* addfront(int data, struct node** head)
{
    struct node* pnode = make_node(data);
    if(*head)
    {
        pnode->next = *head;
    }
    *head = pnode;
    return *head;
}

struct node* addback(int data, struct node** head_address)
{
    /* head is local copy of pointer */
    struct node* head = *(head_address);
    struct node* start = head;
    if(head==NULL)
        addfront(data, &head);
    while(head->next!=NULL)
        head = head->next;
    head->next = make_node(data);
    return start;
}



void display(struct node* head)
{
    /* head pointer passed by value ==> local copy */
    while(head)
    {
        printf("[%d] --> ", head->data);
        head = head->next;
    }
    puts("[NULL]\n");
    return;
}

struct node* find(int data, struct node* head)
{
    /* head pointer is local pointer */
    while(head)
    {
        if(head->data==data)
        {
            printf("[%d] found\n", head->data);
            return head;
        }
        head = head->next;
    }
    printf("[%d] NOT FOUND\n", data);
    return NULL;
}

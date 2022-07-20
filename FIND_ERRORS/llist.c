#include <stdio.h>
#include <stdlib.h> /* malloc */
struct node
{
    int data;
    struct node* next;
};

struct node* head=NULL;
void showlist(struct node* head);
struct node* make_node(int data);
struct node* addfront(int data);
void destructor(struct node*);

int main()
{
    addfront(5);
    addfront(4);
    addfront(3);
    showlist(head);
    destructor(head);
    if(head==NULL)
        puts("head null: OK");
    else
        puts("BUG: head is NOT_NULL (outside destructor)");

    return 0;
}

void destructor(struct node* head)
{
    puts("destroying list ...\n");
    while(head)
    {
        struct node* curr_node = head;
        head = head->next;
        free(curr_node);
    }
    if (head==NULL)
        puts("head is NULL (inside destructor)");
        
    /* BUG: global variable head is null. But not reflecting in main */
    head=NULL; 
}

/* returns pointer to newly formed node */
struct node* make_node(int data)
{
    struct node* pnode = (struct node*)malloc(sizeof(struct node));
    pnode->data = data;
    pnode->next = NULL;
    return pnode;
}

/* addfront node and returns new head. exits on failure for new node */
struct node* addfront(int data)
{
    struct node* pnode = make_node(data);
    if (pnode==NULL)
    {
        printf("Unable to addfront %d", data);
        exit(1);
    }
    if(head)
        pnode->next = head;
    head = pnode;
    return head;
}

void showlist(struct node* head)
{
    if(head==NULL)
    {
        puts("Empty list");
        return;
    }

    struct node* i = head;
    printf("List: ");
    while(i)
    {
        printf(" [%d] -->", i->data);
        i = i->next;
    }
    printf(" [NULL]\n");
}


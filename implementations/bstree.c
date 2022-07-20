/* Binary Search Tree */
#include <stdio.h>
#include <stdlib.h>

struct tnode
{
    int data;
    struct tnode* left;
    struct tnode* right;
};

/* make node and return node address */
struct tnode* talloc(int data)
{
    struct tnode* pnode = (struct tnode*)malloc(sizeof(struct tnode));
    if(pnode)
    {
        pnode->data = data;
        pnode->left = pnode->right = NULL;
    }
    return pnode; 
}

/* add node to BST */
struct tnode* addnode(int data, struct tnode* root)
{
    /* base case */
    if(root==NULL)
    {
        root = talloc(data);
        return root;
    }

    /* recursion */
    if (data < root->data)
        root->left = addnode(data, root->left);
    else
        root->right = addnode(data, root->right);

    return root;
}

void preorder(struct tnode* root)
{
    /* base case */
    if(!root)
        return;

    printf("%d, ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct tnode* root)
{
    /* base case */
    if(!root)
        return;
    inorder(root->left);
    printf("%d, ", root->data);
    inorder(root->right);
}

/* return count of nodes deleted */
int deltree(struct tnode* root)
{
    // if(!root)
    //     return 0;
    // if((root->left==NULL) && (root->right==NULL))
    // {
    //     free(root);
    //     return 1;
    // }
    
    // int leftcount=0, rightcount=0;
    // if(root->left)
    //     leftcount += deltree(root->left);
    // if(root->right)
    //     rightcount += deltree(root->right);
    // return 1+leftcount+rightcount;
    int count=0;
    if(!root)
        return count;
    count+=deltree(root->left);
    count+=deltree(root->right);
    free(root);
    return 1+count;
}

int main()
{
    int array[] = {3,1,0,2,8,6,5,9}; 
    int n = sizeof(array)==0 ? 0: sizeof(array)/sizeof(array[0]);
    struct tnode* root = NULL;

    /* readnodes */
    for(int i=0; i<n; i++)
        root = addnode(array[i], root);

    /* test preorder */
    puts("should print: 3,1,0,2,8,6,5,9");
    preorder(root); puts("");

    /* test inorder */
    puts("should print 0,1,2,3,5,6,8,9");
    inorder(root); puts("");

    /* test deltree */
    int count = deltree(root);
    root = NULL;
    puts("should print deleted nodes: 8");
    printf("deleted nodes: %d\n", count);

    return 0;
}

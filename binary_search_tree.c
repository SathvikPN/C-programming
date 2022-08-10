/* Binary Search Tree */
#include<stdio.h>
#include<stdlib.h>

struct tnode {
    int data;
    struct tnode* left;
    struct tnode* right;
};

struct tnode* talloc(int data);
struct tnode* addnode(struct tnode* root, int data);
void preorder(struct tnode* root); /* {ROOT, LEFT, RIGHT} */
void inorder(struct tnode* root); /* elements sorted */
int deltree(struct tnode* root); /* returns no. nodes deleted [postorder traversal] */

int main()
{
    struct tnode* root = NULL;
    int array[] = {3,1,0,2,8,6,5,9};
    int n = sizeof(array)==0 ? 0: sizeof(array)/sizeof(array[0]);
    for (int i=0; i<n; i++)
        root = addnode(root, array[i]);
    preorder(root); puts("[preorder]");
    inorder(root); puts("[inorder]");
    int del_nodes = deltree(root);
    printf("%d nodes deleted.", del_nodes);
    return 0;
}

struct tnode* talloc(int data)
{
    /* pointer to new tree node */
    struct tnode* pnew_tree_node = (struct tnode*)malloc(sizeof(struct tnode));
    if(pnew_tree_node==NULL)
    {
        puts("Unable to allocate memory for tree node");
        exit(1);
    }
    pnew_tree_node->data = data;
    pnew_tree_node->left = pnew_tree_node->right = NULL;
    return pnew_tree_node;
}

struct tnode* addnode(struct tnode* root, int data)
{
    struct tnode* pnode = talloc(data);
    if(!root || root->data == data)
        return pnode;
    
    /* if data belongs to left bst, addnode to left bst */
    if(data < root->data)
        root->left = addnode(root->left, data);
    else
        root->right = addnode(root->right, data);

    return root;
}

void preorder(struct tnode* root)
{
    if(!root)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct tnode* root)
{
    if(!root)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

/* postorder traversal */
int deltree(struct tnode* root)
{
    int nodes = 0;
    if(!root)
        return nodes;
    nodes = nodes + deltree(root->left);
    nodes = nodes + deltree(root->right);
    nodes = nodes + 1; free(root);
    return nodes;
}

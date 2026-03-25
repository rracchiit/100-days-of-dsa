#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* insert(struct node* root, int x)
{
    if(root == NULL)
    {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->left = newnode->right = NULL;
        return newnode;
    }

    if(x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

void inorder(struct node* root)
{
    if(root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    int n;
    scanf("%d", &n);

    struct node* root = NULL;

    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    inorder(root);

    return 0;
}
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

struct node* findLCA(struct node* root, int a, int b)
{
    if(root == NULL) return NULL;

    if(a < root->data && b < root->data)
        return findLCA(root->left, a, b);

    if(a > root->data && b > root->data)
        return findLCA(root->right, a, b);

    return root;
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

    int a, b;
    scanf("%d %d", &a, &b);

    struct node* lca = findLCA(root, a, b);

    if(lca != NULL)
        printf("%d", lca->data);

    return 0;
}
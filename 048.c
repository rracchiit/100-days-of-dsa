#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* build(int a[], int n, int i)
{
    if(i >= n || a[i] == -1)
        return NULL;

    struct node* root = (struct node*)malloc(sizeof(struct node));
    root->data = a[i];

    root->left = build(a, n, 2*i + 1);
    root->right = build(a, n, 2*i + 2);

    return root;
}

int countLeaf(struct node* root)
{
    if(root == NULL)
        return 0;

    if(root->left == NULL && root->right == NULL)
        return 1;

    return countLeaf(root->left) + countLeaf(root->right);
}

int main()
{
    int n;
    scanf("%d", &n);

    int a[100];

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    struct node* root = build(a, n, 0);

    printf("%d", countLeaf(root));

    return 0;
}
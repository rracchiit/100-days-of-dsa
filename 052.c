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

struct node* LCA(struct node* root, int a, int b)
{
    if(root == NULL)
        return NULL;

    if(root->data == a || root->data == b)
        return root;

    struct node* left = LCA(root->left, a, b);
    struct node* right = LCA(root->right, a, b);

    if(left && right)
        return root;

    return (left != NULL) ? left : right;
}

int main()
{
    int n;
    scanf("%d", &n);

    int a[100];
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    struct node* root = build(a, n, 0);

    int x, y;
    scanf("%d %d", &x, &y);

    struct node* ans = LCA(root, x, y);

    if(ans != NULL)
        printf("%d", ans->data);

    return 0;
}
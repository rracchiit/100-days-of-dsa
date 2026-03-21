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

void inorder(struct node* root)
{
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node* root)
{
    if(root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root)
{
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    int n;
    scanf("%d", &n);

    int a[100];

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    struct node* root = build(a, n, 0);

    inorder(root);
    printf("\n");

    preorder(root);
    printf("\n");

    postorder(root);

    return 0;
}
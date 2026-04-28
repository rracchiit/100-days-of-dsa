#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node
{
    int data;
    struct node *left, *right;
};

// build tree from level order
struct node* build(int a[], int n, int i)
{
    if(i >= n || a[i] == -1)
        return NULL;

    struct node* root = (struct node*)malloc(sizeof(struct node));
    root->data = a[i];

    root->left = build(a, n, 2*i+1);
    root->right = build(a, n, 2*i+2);

    return root;
}

int main()
{
    int n;
    scanf("%d", &n);

    int a[MAX];
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    struct node* root = build(a, n, 0);

    struct node* q[MAX];
    int front = 0, rear = 0;

    q[rear++] = root;

    int leftToRight = 1;

    while(front < rear)
    {
        int size = rear - front;
        int level[MAX];

        for(int i = 0; i < size; i++)
        {
            struct node* curr = q[front++];
            level[i] = curr->data;

            if(curr->left)
                q[rear++] = curr->left;

            if(curr->right)
                q[rear++] = curr->right;
        }

        if(leftToRight)
        {
            for(int i = 0; i < size; i++)
                printf("%d ", level[i]);
        }
        else
        {
            for(int i = size-1; i >= 0; i--)
                printf("%d ", level[i]);
        }

        leftToRight = !leftToRight;
    }

    return 0;
}
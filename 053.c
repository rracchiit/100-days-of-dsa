#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node
{
    int data;
    struct node *left, *right;
};

struct pair
{
    struct node* node;
    int hd;
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

    struct pair q[MAX];
    int front = 0, rear = 0;

    int map[200][MAX];   // store values
    int count[200] = {0};

    int offset = 100;    // to handle negative HD
    int min = 100, max = 100;

    q[rear++] = (struct pair){root, 0};

    while(front < rear)
    {
        struct pair p = q[front++];
        struct node* curr = p.node;
        int hd = p.hd;

        int idx = hd + offset;

        map[idx][count[idx]++] = curr->data;

        if(idx < min) min = idx;
        if(idx > max) max = idx;

        if(curr->left)
            q[rear++] = (struct pair){curr->left, hd-1};

        if(curr->right)
            q[rear++] = (struct pair){curr->right, hd+1};
    }

    // print vertical order
    for(int i = min; i <= max; i++)
    {
        for(int j = 0; j < count[i]; j++)
            printf("%d ", map[i][j]);
        printf("\n");
    }

    return 0;
}
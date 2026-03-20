#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

/* Create Node */
struct node* newNode(int val){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

/* Queue */
struct node* queue[1000];
int front = -1, rear = -1;

void enqueue(struct node* x){
    if(front == -1) front = 0;
    queue[++rear] = x;
}

struct node* dequeue(){
    return queue[front++];
}

int isEmpty(){
    return front > rear;
}

/* Build Tree from Level Order */
struct node* buildTree(int arr[], int n){

    if(n == 0 || arr[0] == -1) return NULL;

    struct node* root = newNode(arr[0]);
    enqueue(root);

    int i = 1;

    while(i < n){
        struct node* curr = dequeue();

        /* Left Child */
        if(i < n && arr[i] != -1){
            curr->left = newNode(arr[i]);
            enqueue(curr->left);
        }
        i++;

        /* Right Child */
        if(i < n && arr[i] != -1){
            curr->right = newNode(arr[i]);
            enqueue(curr->right);
        }
        i++;
    }

    return root;
}

/* Inorder Traversal */
void inorder(struct node* root){
    if(root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main(){

    int n;
    scanf("%d", &n);

    int arr[1000];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct node* root = buildTree(arr, n);

    inorder(root);

    return 0;
}

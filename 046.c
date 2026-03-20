#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

/* Queue */
struct node* queue[100];
int front = -1, rear = -1;

void enqueue(struct node* x){
    if(front == -1) front = 0;
    queue[++rear] = x;
}

struct node* dequeue(){
    return queue[front++];
}

int isEmpty(){
    return (front > rear);
}

/* Level Order Function */
void levelOrder(struct node* root){
    if(root == NULL) return;

    enqueue(root);

    while(!isEmpty()){
        struct node* temp = dequeue();
        printf("%d ", temp->data);

        if(temp->left) enqueue(temp->left);
        if(temp->right) enqueue(temp->right);
    }
}

/* Create Node */
struct node* newNode(int val){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

int main(){

    /* Creating Tree

            1
           / \
          2   3
         / \
        4   5

    */

    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Level Order Traversal:\n");
    levelOrder(root);

    return 0;
}
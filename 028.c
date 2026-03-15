#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    int n;
    scanf("%d", &n);

    struct node *head = NULL, *temp = NULL, *newnode;

    // create circular list
    for(int i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    if(temp != NULL)
        temp->next = head;   // make circular

    // traversal
    if(head != NULL)
    {
        struct node *ptr = head;
        do
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        } 
        while(ptr != head);
    }

    return 0;
}
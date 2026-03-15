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

    // create list
    for(int i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL)
            head = temp = newnode;
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    int k;
    scanf("%d", &k);

    if(head == NULL || k == 0)
    {
        temp = head;
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }

    // find length and last node
    int len = 1;
    temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
        len++;
    }

    // make circular
    temp->next = head;

    k = k % len;
    int steps = len - k;

    struct node *newtail = head;
    for(int i = 1; i < steps; i++)
        newtail = newtail->next;

    head = newtail->next;
    newtail->next = NULL;

    // print rotated list
    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
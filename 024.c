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

    int key;
    scanf("%d", &key);

    struct node *curr = head, *prev = NULL;

    while(curr != NULL)
    {
        if(curr->data == key)
        {
            if(prev == NULL)          // delete head
                head = curr->next;
            else
                prev->next = curr->next;

            free(curr);
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    // print list
    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
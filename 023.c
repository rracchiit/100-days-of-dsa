#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* createList(int n)
{
    struct node *head = NULL, *temp = NULL, *newnode;

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
    return head;
}

struct node* merge(struct node *a, struct node *b)
{
    struct node dummy;
    struct node *tail = &dummy;
    dummy.next = NULL;

    while(a != NULL && b != NULL)
    {
        if(a->data <= b->data)
        {
            tail->next = a;
            a = a->next;
        }
        else
        {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }

    if(a != NULL)
        tail->next = a;
    else
        tail->next = b;

    return dummy.next;
}

int main()
{
    int n, m;

    scanf("%d", &n);
    struct node *list1 = createList(n);

    scanf("%d", &m);
    struct node *list2 = createList(m);

    struct node *merged = merge(list1, list2);

    while(merged != NULL)
    {
        printf("%d ", merged->data);
        merged = merged->next;
    }

    return 0;
}
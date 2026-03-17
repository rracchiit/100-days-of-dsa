#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node
{
    int data;
    struct node *next;
};

void push(struct node **top, int x)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = *top;
    *top = newnode;
}

int pop(struct node **top)
{
    struct node *temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

int main()
{
    char postfix[200];
    fgets(postfix, sizeof(postfix), stdin);

    struct node *top = NULL;

    char *token = strtok(postfix, " \n");

    while(token != NULL)
    {
        if(isdigit(token[0]) || 
           (token[0] == '-' && isdigit(token[1])))   // number
        {
            push(&top, atoi(token));
        }
        else   // operator
        {
            int b = pop(&top);
            int a = pop(&top);
            int res;

            if(token[0] == '+') res = a + b;
            else if(token[0] == '-') res = a - b;
            else if(token[0] == '*') res = a * b;
            else if(token[0] == '/') res = a / b;

            push(&top, res);
        }

        token = strtok(NULL, " \n");
    }

    printf("%d", pop(&top));

    return 0;
}
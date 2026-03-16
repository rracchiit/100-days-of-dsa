#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int stack[100];
    int top = -1;

    // push n elements
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &stack[++top]);
    }

    int m;
    scanf("%d", &m);

    // pop m elements
    for(int i = 0; i < m; i++)
    {
        if(top != -1)
            top--;
    }

    // print remaining stack (top → bottom)
    while(top != -1)
    {
        printf("%d ", stack[top--]);
    }

    return 0;
}
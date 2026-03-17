#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int q[100];

    // enqueue n elements
    for(int i = 0; i < n; i++)
        scanf("%d", &q[i]);

    int front = 0;
    int rear = n - 1;
    int size = n;

    int m;
    scanf("%d", &m);

    // dequeue m times (circularly)
    front = (front + m) % n;

    // display queue from new front
    for(int i = 0; i < size; i++)
    {
        int idx = (front + i) % n;
        printf("%d ", q[idx]);
    }

    return 0;
}
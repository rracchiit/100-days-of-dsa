#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int a[100];

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int k;
    scanf("%d", &k);

    k = k % n;   // handle k > n

    int temp[100];

    // copy last k elements to start
    for(int i = 0; i < k; i++)
        temp[i] = a[n - k + i];

    // copy remaining elements
    for(int i = k; i < n; i++)
        temp[i] = a[i - k];

    // print rotated array
    for(int i = 0; i < n; i++)
        printf("%d ", temp[i]);

    return 0;
}
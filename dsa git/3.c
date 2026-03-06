//Implement linear search to find key k in an array. 
//Count and display the number of comparisons performed.
#include <stdio.h>
int main(){
    int n,k,comparisons=0;
    printf("enter the size of the array :\n");
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements of the array :\n");
    for(int i=0;i<n;i++ ){
        scanf("%d",&arr[i]);
    }
    printf("enter the key to be searched:\n");
    scanf("%d",&k);
    for(int i=0;i<n;i++){
        comparisons++;
        if(arr[i]==k){
            printf("Element found at position %d\n",i+1);
            printf("Number of comparisons: %d\n",comparisons);
            break;
        }
    }
    if(comparisons==n){
        printf("Element not found\n");
        printf("Number of comparisons: %d\n",comparisons);
    }
    return 0;
}
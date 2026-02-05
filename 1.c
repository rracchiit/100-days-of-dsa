#include <stdio.h>
//Write a C program to insert an element x at a given 1-based position pos in an array of n integers. 
//Shift existing elements to the right to make space.
int main(){
    int n,pos,x;
    int arr[n+1];
    printf("enter the size of the array :\n");
    scanf("%d",&n);
    printf("enter the elements of the array :\n");
    for(int i=0;i<n;i++ ){
        scanf("%d",&arr[i]);
    }
    printf("enter the position to insert the element in an array:\n");
    scanf("%d",&pos);
    printf("enter the element to be inserted:\n");
    scanf("%d",&x);

    for (int i=n;i>=pos;i--){
        arr[i]=arr[i-1];
    }
    arr[pos-1]=x;
    n=n+1;
    printf("The array after insertion is:\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
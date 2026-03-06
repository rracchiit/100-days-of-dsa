#include <stdio.h>
//Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. 
//Shift remaining elements to the left.
int main(){
int n,pos;
printf("enter the size of the array :\n");
scanf("%d",&n);
int arr[n];
printf("enter the elements of the array :\n");
for(int i=0;i<n;i++ ){
    scanf("%d",&arr[i]);
}
printf("enter the position to delete the element from an array:\n");
scanf("%d",&pos);
for (int i=pos-1;i<n-1;i++){
    arr[i]=arr[i+1];
}
n=n-1;
printf("The array after deletion is:\n");
for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
}

    return 0;
}
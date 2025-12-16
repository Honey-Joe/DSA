#include <stdio.h>

void main(){
    int i , j , n ;
    printf("Enter the size of the array : ");
    scanf("%d" , &n);

    int a[n];

    for(i=0; i < n ; i++){
        printf("Enter the elements : ");
        scanf("%d" , &a[i]);
    }

    for(i=0 ; i < n ; i++){
        printf("%d ", a[i]);
    }

    // reverse the array 
    for(int i = 0 ; i < n/2 ; i++){
        int temp = a[i];
        a[i] = a[n-1-i];
        a[n-1-i] = temp;
    }
    printf("\n");

    for(i=0 ; i < n ; i++){
        printf("%d ",a[i]);
    }

    
}
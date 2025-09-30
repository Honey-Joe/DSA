#include <stdio.h>



void main(){
    int i , j , n;
    printf("Enter the size of the array :");
    scanf("%d"  ,&n);

    int a[n];

    for(i=0 ; i < n ; i++){
        printf("Enter the elements :");
        scanf("%d" , &a[i]);
    }

    for(i=0 ; i < n ; i++){
        printf("%d " , a[i]);
    }
    //reverse the array 

    for(i = 0 ; i < n/ 2; i++){
        int temp = a[i];
        a[i] = a[n-i-1];
        a[n-i-1] = temp ;
    }

    printf("\n");
    for(i=0 ; i < n ; i++){
        printf("%d " , a[i]);
    }

    //second largest number 
    int large;
    int slarge;
    for( i = 0 ; i < n ; i ++){
        if(a[i]>large){
            // slarge = large;
            large  = a[i];
        }
        else if(a[i]>slarge && a[i]!=large){
            slarge=a[i];
            large = slarge;
        }
    }
    printf("The second largest number is %d" , slarge);


}
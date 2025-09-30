#include <stdio.h>

void main(){
    int i , j , n , size = 0 , appvar;
    // printf("Enter the number of elemements in an array");
    // scanf("%d",&n);
    // int a[n];
    int a[5] = {1,2,3,4,5};
    // for(i=0;i<5;i++){
    //     printf("Enter the elements:");
    //     scanf("%d",&a[i]);
    //     size++;
    // }
    // printf("The elements in the array");
    // for(i=0;i<5;i++){
    //     printf("%d \n", a[i]);
    // }
    int c[5];
    for(i=0 ; i< 5 ; i++){
        int next = -1;
        for(j = i +1 ; j < 5; j++){
            if(a[i]<a[j]){
                next = a[j];
                break;
            }
        }
        printf("%d " , next);
    }

    
}
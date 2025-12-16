#include <stdio.h>


void main(){
    int a[5]={4,2,3,5,1};

    for(int i = 1 ; i < 5 ; i++){
        int key = a[i];
        int j = i - 1;
        while(j>=0 && a[j]>key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
    for(int i = 0 ; i < 5 ; i++){
        printf("%d" , a[i]);
    }
}
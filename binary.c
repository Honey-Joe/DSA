#include<stdio.h>

int main(){
    int low = 0 , high = 9 , mid ;

    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int n;
    int flag = 0;
    printf("Enter a number to search:");
    scanf("%d", &n);
    while(low<=high){
        mid =( high + low ) /2;
        if (a[mid] == n){
            flag = 1;
            break;
        }else if(a[mid] > n){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }

    }
    if(flag == 1){
        printf("The searched elemement index %d \n" , mid);
    }else{
        printf("The element not found \n");
    }
    return 0;
}
#include <stdio.h>

#define MAX 100

void main(){
    int i , j , n , size = 0 , appvar;
    int a[MAX];
    printf("Enter the number of elemements in an array");
    scanf("%d",&n);
    // int a[n];
    for(i=0;i<n;i++){
        printf("Enter the elements:");
        scanf("%d",&a[i]);
        size++;
    }
    printf("The elements in the array");
    for(i=0;i<n;i++){
        printf("%d \n", a[i]);
    }
    // append in the array 
    printf("Enter the index and the element to append in the array");
    scanf("%d" , &appvar);
    a[size] = appvar;
    size++;

    printf("The elements in the array");
    for(i=0;i<size;i++){
        printf("%d \n", a[i]);
    }
    int search;
    printf("Enter the element to search");
    scanf("%d", &search);
    int flag = -1;
    for(i=0;i<size;i++){
        if(a[i]==search){
            flag = 1;
            break;
        }
    }
    if(flag<0){
        printf("The element is not found");
    }else{
        printf("The element is found");
    }

    //update the array 
    int index , update;
    printf("Enter the index and the element to update");
    scanf("%d %d", &index , &update);
    a[index] = update;

    printf("The updated array");
    for(i=0;i<size;i++){
        printf("%d \n", a[i]);
    }

    //sort the array
    int temp = 0;
    for(i=0;i<size;i++){
        for(j=i+1;j<size;j++){
            if(a[i]>a[i+1]){
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
    }

    printf("The sorted array \n");
    for(i=0;i<size;i++){
        printf("%d \n",a[i]);
    }
    int deleteIndex;
    //delete an elemenet in the array 
    printf("Enter the index of the element to be deleted: ");
    scanf("%d",&deleteIndex);
    int deletedElement = a[deleteIndex];

    for(i=deleteIndex ; i<size-1 ; i++){
        a[i] = a[i+1];
    }

    size--;

    printf("The updated array");
    for(i=0;i<size ; i++){
        printf("%d \n", a[i]);
    }

    









    
}
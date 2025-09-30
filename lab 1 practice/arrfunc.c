#include <stdio.h>
#define MAX 100

int i , j , a[MAX] , size = 0;

void printArray(int size){
    for(i=0;i<size;i++){
        printf("%d \n", a[i]);
    }
}
void appendArray(int value){
    a[size] = value;
    size++;
}

void deleteArray(int index){
    int deletedEle = a[index];
    for(i=index ; i<size-1; i++){
        a[i] = a[i+1];
    }
    size--;
}

void bubbleSort(int size){
    int temp;
    for(i=0 ; i<size-1 ; i++){
        for(j=0 ; j<size-i-1; j++){
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int linearSearch(int search){
    int flag = 0;
    for(i=0;i<size;i++){
        if(a[i] == search){
            flag = 1;
            break;
        }
    }
    return flag;
}


void main(){

    // int i , j , size ;
    printf("Enter the size of the array :");
    scanf("%d", &size);

    // printf('Enter the elements of the array :');

    for(i = 0 ; i< size  ; i++){
        printf("Enter the elements");
        scanf("%d" , &a[i]);
    }

    printf("The elements of the array are :");

    printArray(size);
    int value , index , search;

    printf("Enter the element to append:");
    scanf("%d" , &value);
    appendArray(value);
    // printf("%d", size);
    printf("Elements of the array after append");
    printArray(size);
    printf("Enter the index of the element to delete");
    scanf("%d", &index);
    deleteArray(index);
    printf("Elements of the array after deletion \n");
    printArray(size);

    printf("Sorted Array :");
    bubbleSort(size);

    printArray(size);
    
    printf("Enter the element to search");
    scanf("%d", &search);
    int flag = linearSearch(search);
    if(flag == 1){
        printf("The element is found");
    }else{
        printf("The element is not found");
    }

    
}
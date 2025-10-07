#include <stdio.h>
#define N 10
int queue[N];
int front = -1;
int rear = -1;



void enqueue(int x){
    if(rear == N-1){
        printf("Overflow");
    }else if(front == -1 && rear == -1){
        front = 0;
        rear = 0;
        queue[rear] = x;
    }else{
        rear++;
        queue[rear] = x;
    }
}

void dequeue(){
    if(front == -1 && rear == -1){
        printf("Underflow");
    }else if(front == rear){
        printf("The dequeued element %d", queue[front]);
        front = -1;
        rear = -1;
    }else{
        printf("The dequeued element %d", queue[front]);
        front++;
    }
}

void frontElement(){
    printf("The front element is : %d" , queue[front]);
}

void display(){
    for(int i = front ; i < rear +1 ; i++){
        printf("%d " , queue[i]);
    }
}

int main(){
    int choice;
    int x;
    while(1){
        printf("\nQueue Operation \n");
        printf("1. Enquque \n2. Dequeue\n3. Front \n4. Display\n5. Exit \n");
        printf("Enter your choice: ");
        scanf("%d" , &choice);
        switch(choice){
            case 1:
                printf("Enter an element to enqueue");
                scanf("%d",&x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                frontElement();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Terminated");
                return 0;
            default:
                printf("Invalid Choice");
                break;
        }
    }
}
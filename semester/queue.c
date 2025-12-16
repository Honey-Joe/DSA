#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int data){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = data;
    newnode->next = NULL;

    if(front == NULL){
        rear = front = newnode;
    }else{
        rear->next = newnode;
        rear = newnode;
    }

    printf("Enqueued Element : %d" , data);
}

void dequeue(){

    if(front == NULL){
        printf("Queue is empty");
    }

    struct node *temp = front;
    printf("Dequeued Element : %d" , temp->data);
    front = front->next;
    free(temp);

    if(front == NULL){
        rear = NULL;
    }
}

void main(){
    enqueue(10);
    enqueue(20);
    dequeue();

}
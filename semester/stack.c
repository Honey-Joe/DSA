#include <stdio.h> 
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;


struct node *push(int key){

    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    if(newnode == NULL){
        printf("Stack Overflow");
        return 0;
    }

    newnode->data = key;
    newnode->next = top;
    top = newnode;
}

struct node *pop(){
    if(top == NULL){
        printf("Stack Underflow");
        return 0;
    }

    struct node *temp = top;
    printf("The popped element is %d:" , temp->data);
    top = top->next;
    free(temp);
}

void display(){
    if(top == NULL){
        printf("Stack is empty");
    }

    struct node *temp = top;
    while(temp != NULL){
        printf("%d " , temp->data);
        temp = temp->next;
    }
}

int main(){
    push(10);
    push(20);
    push(30);
    pop();
    display();
    return 0;
}
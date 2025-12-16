#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char act[50];
    struct node *next;
};

struct node *top = NULL;

void push(char *action){

    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    if(newnode == NULL){
        printf("Stack is underflow");
    }

    strcpy(newnode->act , action);
    newnode->next = top;
    top = newnode;

    printf("The action performed : %s" , action);
}

void pop(){

    if(top == NULL){
        printf("The Stack is overflow");
    }
    struct node *temp = top;
    printf("The undone action is : %s" , temp->act);
    top = top->next;
    free(temp);
}

void display(){

    if(top == NULL){
        printf("The stack is empty");
    }

    struct node *temp = top;

    while(temp != NULL){
        printf("%s" , temp->act );
        temp = temp->next;
    }
}

void main(){

    push("Honey Joe");

    
    pop();
    display();
}
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node *create_node(int data){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

struct node *insertBeg(int key){
    struct node *newnode = create_node(key);
    newnode->next = head;
    head = newnode;
}

struct node *insertEnd(int key){
    struct node* newnode = create_node(key);

    if(head == NULL){
        head = newnode;
    }

    struct node *temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newnode;
}

struct node *insertPos(int pos , int key){
    if(pos == 1){
        insertBeg(key);
    }

    struct node *newnode = create_node(key);
    struct node *temp = head;

    for(int i = 1 ; i < pos - 1 && temp != NULL ; i++){
        temp = temp->next;
    }

    if(temp == NULL){
        printf("Invalid Position");
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

struct node *deleteBeg(){
    if(head == NULL){
        printf("List is empty ");
    }

    struct node *temp = head;
    head = head->next;
    free(temp);
}

struct node *deleteEnd(){
    if(head == NULL){
        printf("List is empty");
    }

    if(head->next == NULL){
        free(head);
        head = NULL;
    }

    struct node *temp = head;

    while(temp->next->next != NULL){
        temp = temp->next;
    }

    free(temp->next);

    temp->next = NULL;
}

struct node *deletePos(int pos){
    if(pos == 1){
        deleteBeg();
    }
    
    struct node *temp = head;

    for(int i = 1 ; i < pos - 1 && temp != NULL ; i++){
        temp = temp->next;
    }

    if(temp == NULL || temp->next == NULL){
        printf("Invalid Position");
    }

    struct node *del = temp->next;
    temp->next = del->next;
    free(temp);

}

void display() {
    struct node* temp = head;

    if (temp == NULL) {
        printf("List is empty!\n");
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void main(){
    insertBeg(10);
    insertEnd(20);
    insertPos(2,30);
    // deleteBeg();
    deleteEnd();
    display();
}

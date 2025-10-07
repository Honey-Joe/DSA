#include <stdio.h>
#define SIZE 10
#include <string.h>
char queue[SIZE][20];
int front = -1 ;
int rear  = -1;

void enqueue(char person[]){
    if(rear == SIZE - 1){
        printf("Queue is full \n");
    }else{
        if (front = -1) front =0;
        rear++;
        strcpy(queue[rear], person);
        printf("%s Joined in the queue \n", queue[rear]);
    }
}

void dequeue() {
    if (front == -1 || front > rear)
        printf("No one waiting.\n");
    else {
        printf("%s got ticket and left.\n", queue[front]);
        front++;
    }
}

void display(){
    if(front == -1 || front > rear){
        printf("The queue is empty \n");
    }else{
        printf("Waiting : ");
        for(int i = front ; i <= rear ; i++){
            printf("%s ", queue[i]);
        }
    }
}

int main() {
    char person[20];
    printf("Enter a name to wait in the queue");
    scanf("%s",person);
    enqueue(person);
    enqueue("Naveen");
    enqueue("Jai");
    dequeue();
    display();
    dequeue();
    display();
    return 0;
}
#include<stdio.h>

#define size 10
struct printer{
    int jobId;
    int pages;
}queue[size];
int front = -1;
int rear = -1;

void enqueue(int id , int pages){
    if(rear == size-1){
        printf("The Queue is full");
    }else if(front == -1 && rear == -1){
        front = 0;
        rear = 0;
        queue[rear].jobId = id;
        queue[rear].pages = pages;
        printf("Added Job %d (%d pages)", queue[rear].jobId, queue[rear].pages); 
    }else{
        rear ++;
        queue[rear].jobId = id;
        queue[rear].pages = pages;
        printf("Added Job %d (%d pages)", queue[rear].jobId, queue[rear].pages); 
    }
}

void dequeue(){
    if(rear == -1 && front == -1){
        printf("The queue is empty");
    }else if(rear == front){
        printf("Printing Jobs %d (%d pages) " , queue[front].jobId , queue[front].pages);
        front = -1;
        rear = -1;
    }else{
        printf("Printing Jobs %d (%d pages) " , queue[front].jobId , queue[front].pages);
        front ++;
    }
}

void display(){
    if(front == -1 || front > rear){
        printf("No pending jobs \n");
    }else{
        printf("Pending jobs:\n"); 
        for(int i = front ; i < rear +1 ; i++){
            printf("Jobs in queue %d (pages %d) ", queue[front].jobId , queue[front].pages);
        }
    }
}

int main() {
    enqueue(1, 5);
    enqueue(2, 10);
    dequeue();
    display();
    return 0;
}

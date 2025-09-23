#include <stdio.h>

#define MAX 100

int a[MAX] ;

int top = -1;

void isEmpty(){
    if(top==-1){
        printf("Stack is empty\n");
        return;
    }  
}

void isFull(){
    if(top==MAX-1){
        printf("Stack is full\n");
        return;
    }  
}

void push(int x){
    if(top==MAX-1){
        printf("Stack is full\n");
        return;
    }
    top++;
    a[top] = x;
    printf("Element %d pushed into the stack\n", x);
}

int pop(){
    if(top == -1){
        printf("Stack is empty\n");
        return -1;
    }
    int x = a[top];
    top --;
    return x;
}

int peek(){
    if(top == -1){
        printf("Stack is empty\n");
        return -1;
    }
    return a[top];
} 

void displayStack(){
    for(int i=0;i<=top ; i++){
        printf("%d ", a[i]);
    }
}

int main(){
    int size , element , choice ;

    // printf("Enter the capacity of the stack : ");
    // scanf("%d",&size);

    while(1){
        printf("\n 1.Push \n 2. Pop \n 3.Peek \n 4.Display \n 5.Exit \n");
        printf("Enter the choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter a element to push :");
                scanf("%d",&element);
                push(element);
                break;
            case 2:
                printf("The popped element %d ", pop());
                break;
            case 3:
                printf("The peek element %d ", peek());
                break;
            case 4:
                displayStack();
                break;
            case 5:
                printf("Program terminamted");
                return 0;
            default:
                printf("The choice is invalid");
                break;
        }
    }

}

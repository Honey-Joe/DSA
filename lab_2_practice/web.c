#include <stdio.h>
#include <string.h>

#define MAX 100

char a[MAX][50];
int top = -1;
void push(char url[]){
    if(top == MAX-1){
        printf("History is full you can't visit webpage");
        return;
    }
    top ++;
    strcpy(a[top] , url);
    printf("Visiting %s\n", url);
}

void pop(){
    if(top == -1){
        printf("No webpage to go back");
        return;
    }   
    printf("Going back from %s\n", a[top]);
    top--;
    if(top >=0 ){
        printf("The current page %s" , a[top]);
    }else{
        printf("No pages left");
    }
}

void peek(){
    if(top == -1){
        printf("No webpage visited");
        return;
    }
    printf("Current page is %s\n", a[top]);
}

void history(){
    if(top == -1){
        printf("No webpage visited");
        return;
    }
    printf("Webpage history : \n");
    for(int i=0;i<=top;i++){
        printf("%s\n", a[i]);
    }
}

int main(){
    int choice;
    char url[50];
    while(1){
        printf("1. Visit the webpage \n");
        printf("2. Go back \n");
        printf("3. Current website \n");
        printf("4. History \n");
        printf("5. Exit \n");
        printf("Enter a choice :");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the url: ");
                scanf("%s" , url);
                push(url);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                history();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }   
    }
}
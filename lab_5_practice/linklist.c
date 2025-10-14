#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *temp, *newnode;
int count = 0;

// Function to create initial list
void createList() {
    int choice = 1;
    while (choice) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
        count++;
        printf("Add more? (1/0): ");
        scanf("%d", &choice);
    }
}

// Insert at beginning
void insertAtStart() {
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data to insert at start: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
    count++;
}

// Insert at end
void insertAtEnd() {
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data to insert at end: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    count++;
}

// Insert at specific position
void insertAtPos() {
    int pos, i = 1;
    printf("Enter position to insert: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > count + 1) {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1) {
        insertAtStart();
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    temp = head;
    while (i < pos - 1) {
        temp = temp->next;
        i++;
    }

    newnode->next = temp->next;
    temp->next = newnode;
    count++;
}

// Delete from beginning
void deleteAtStart() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    temp = head;
    head = head->next;
    free(temp);
    count--;
    printf("Node deleted from start.\n");
}

// Delete from end
void deleteAtEnd() {
    struct node *prev;
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    temp = head;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
    count--;
    printf("Node deleted from end.\n");
}

// Delete from specific position
void deleteAtPos() {
    int pos, i = 1;
    struct node *nextnode;

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > count) {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1) {
        deleteAtStart();
        return;
    }

    temp = head;
    while (i < pos - 1) {
        temp = temp->next;
        i++;
    }

    nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);
    count--;
    printf("Node deleted from position %d.\n", pos);
}

// Display list
void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    temp = head;
    printf("\nLinked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main Function with Menu
int main() {
    int choice;
    createList();

    while (1) {
        printf("\n----- MENU -----\n");
        printf("1. Insert at Start\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Start\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertAtStart(); break;
            case 2: insertAtEnd(); break;
            case 3: insertAtPos(); break;
            case 4: deleteAtStart(); break;
            case 5: deleteAtEnd(); break;
            case 6: deleteAtPos(); break;
            case 7: display(); break;
            case 8: return 0; break;
            default : printf("Invalid Choice"); break;
        }
    }
}
            

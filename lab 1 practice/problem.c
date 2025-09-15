#include <stdio.h>

#define MAX_SIZE 1000

// Global variables
int arr[MAX_SIZE];
int size = 0;

// Function prototypes
void createArray(int capacity);
void insertElement(int index, int element);
void deleteElement(int index);
void appendElement(int element);
void displayArray();
int searchElement(int element);
int isEmpty();
int isFull();

// Create/Initialize array
void createArray(int capacity) {
    if (capacity > MAX_SIZE) {
        printf("Capacity too large! Maximum allowed: %d\n", MAX_SIZE);
        return;
    }
    size = 0;
    printf("Array created with capacity: %d\n", capacity);
}

// Insert element at specific index
void insertElement(int index, int element) {
    if (index < 0 || index > size) {
        printf("Invalid index! Index should be between 0 and %d\n", size);
        return;
    }
    
    if (size >= MAX_SIZE) {
        printf("Array is full! Cannot insert element.\n");
        return;
    }
    
    // Shift elements to the right
    for (int i = size; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    
    arr[index] = element;
    size++;
    printf("Element %d inserted at index %d successfully.\n", element, index);
}

// Delete element at specific index
void deleteElement(int index) {
    if (isEmpty()) {
        printf("Array is empty! Cannot delete element.\n");
        return;
    }
    
    if (index < 0 || index >= size) {
        printf("Invalid index! Index should be between 0 and %d\n", size - 1);
        return;
    }
    
    int deletedElement = arr[index];
    
    // Shift elements to the left
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }   
    
    size--;
    printf("Element %d deleted from index %d successfully.\n", deletedElement, index);
}

// Append element at the end of array
void appendElement(int element) {
    if (size >= MAX_SIZE) {
        printf("Array is full! Cannot append element.\n");
        return;
    }
    
    arr[size] = element;
    size++;
    printf("Element %d appended successfully.\n", element);
}

// Display all elements in array
void displayArray() {
    if (isEmpty()) {
        printf("Array is empty!\n");
        return;
    }
    
    printf("Array (Size: %d): [", size);
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// Search for an element in array
int searchElement(int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            printf("Element %d found at index %d.\n", element, i);
            return i;
        }
    }
    
    printf("Element %d not found in the array.\n", element);
    return -1;
}

// Check if array is empty
int isEmpty() {
    return (size == 0);
}

// Check if array is full
int isFull() {
    return (size >= MAX_SIZE);
}

// Main function to demonstrate all operations
int main() {
    int choice, element, index, capacity;
    
    printf("=== Simple Array Operations in C ===\n\n");
    
    // Initialize array
    printf("Enter the capacity for the array (max %d): ", MAX_SIZE);
    scanf("%d", &capacity);
    createArray(capacity);
    
    while (1) {
        printf("\n=== MENU ===\n");
        printf("1. Append Element\n");
        printf("2. Insert Element at Index\n");
        printf("3. Delete Element at Index\n");
        printf("4. Display Array\n");
        printf("5. Search Element\n");
        printf("6. Check if Empty\n");
        printf("7. Check if Full\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter element to append: ");
                scanf("%d", &element);
                appendElement(element);
                break;
                
            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter index (0 to %d): ", size);
                scanf("%d", &index);
                insertElement(index, element);
                break;
                
            case 3:
                if (isEmpty()) {
                    printf("Array is empty! Nothing to delete.\n");
                } else {
                    printf("Enter index to delete (0 to %d): ", size - 1);
                    scanf("%d", &index);
                    deleteElement(index);
                }
                break;
                
            case 4:
                displayArray();
                break;
                
            case 5:
                printf("Enter element to search: ");
                scanf("%d", &element);
                searchElement(element);
                break;
                
            case 6:
                if (isEmpty()) {
                    printf("Array is empty.\n");
                } else {
                    printf("Array is not empty. Current size: %d\n", size);
                }
                break;
                
            case 7:
                if (isFull()) {
                    printf("Array is full.\n");
                } else {
                    printf("Array is not full. Available space: %d\n", MAX_SIZE - size);
                }
                break;
                
            case 8:
                printf("Program terminated successfully.\n");
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
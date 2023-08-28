#include <stdio.h>

// Function to display the elements of the array
void display(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element at the end of the array
int insert(int arr[], int size, int element) {
    if (size >= 100) {
        printf("Array is full, cannot insert.\n");
        return size;
    }

    arr[size] = element;
    return size + 1;
}

// Function to delete an element from the array
int deleteElement(int arr[], int size, int element) {
    int found = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            for (int j = i; j < size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Element not found in the array.\n");
    } else {
        printf("Element deleted successfully.\n");
        return size - 1;
    }
}

int main() {
    int arr[100];
    int size = 0;
    int choice, element;

    do {
        printf("\nArray Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                size = insert(arr, size, element);
                break;
            case 2:
                printf("Enter element to delete: ");
                scanf("%d", &element);
                size = deleteElement(arr, size, element);
                break;
            case 3:
                display(arr, size);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}


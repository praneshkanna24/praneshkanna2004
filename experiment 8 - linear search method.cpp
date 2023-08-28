#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index where the target is found
        }
    }
    return -1; // Return -1 if target is not found
}

int main() {
    int arr[100];
    int size, target;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter array elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to search for: ");
    scanf("%d", &target);

    int index = linearSearch(arr, size, target);

    if (index != -1) {
        printf("%d found at index %d.\n", target, index);
    } else {
        printf("%d not found in the array.\n", target);
    }

    return 0;
}


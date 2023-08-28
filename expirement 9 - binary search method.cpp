#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Return the index where the target is found
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Return -1 if target is not found
}

int main() {
    int arr[100];
    int size, target;

    printf("Enter the size of the sorted array: ");
    scanf("%d", &size);

    printf("Enter sorted array elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to search for: ");
    scanf("%d", &target);

    int index = binarySearch(arr, 0, size - 1, target);

    if (index != -1) {
        printf("%d found at index %d.\n", target, index);
    } else {
        printf("%d not found in the array.\n", target);
    }

    return 0;
}


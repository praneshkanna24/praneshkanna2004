#include <stdio.h>

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int numbers[n];

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    printf("Odd/Even Results:\n");
    for (int i = 0; i < n; i++) {
        if (numbers[i] % 2 == 0) {
            printf("%d is even\n", numbers[i]);
        } else {
            printf("%d is odd\n", numbers[i]);
        }
    }

    return 0;
}


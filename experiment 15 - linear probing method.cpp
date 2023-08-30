#include <stdio.h>

#define SIZE 10 // Size of the hash table

int hash(int key) {
    return key % SIZE; // Simple hash function using modulo
}

void insert(int hashTable[], int key) {
    int index = hash(key);

    // Linear probing to find an empty slot
    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
    }

    hashTable[index] = key;
}

void display(int hashTable[]) {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d: %d\n", i, hashTable[i]);
    }
}

int main() {
    int hashTable[SIZE];
    
    // Initialize hash table with -1 (indicating empty slots)
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }

    int keys[] = {12, 25, 35, 45, 26, 19, 22, 10, 32};
    int numKeys = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < numKeys; i++) {
        insert(hashTable, keys[i]);
    }

    display(hashTable);

    return 0;
}


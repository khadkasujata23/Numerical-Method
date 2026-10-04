#include <stdio.h>
#include <stdlib.h>

#define SIZE 10  // Size of hash table
#define EMPTY -1 // Indicator for empty slot

int hashTable[SIZE];

// Hash function
int hash(int key) {
    return key % SIZE;
}

// Insert function using linear probing
void insert(int key) {
    int index = hash(key);
    int startIndex = index;

    while (hashTable[index] != EMPTY) {
        index = (index + 1) % SIZE; // Linear probing
        if (index == startIndex) {
            printf("Hash table is full. Cannot insert %d\n", key);
            return;
        }
    }

    hashTable[index] = key;
    printf("Inserted %d at index %d\n", key, index);
}

// Search function using linear probing
int search(int key) {
    int index = hash(key);
    int startIndex = index;

    while (hashTable[index] != EMPTY) {
        if (hashTable[index] == key)
            return index;
        index = (index + 1) % SIZE;
        if (index == startIndex)
            break; // Searched whole table
    }

    return -1; // Not found
}

// Display hash table
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != EMPTY)
            printf("Index %d: %d\n", i, hashTable[i]);
        else
            printf("Index %d: EMPTY\n", i);
    }
}

int main() {
    // Initialize hash table
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = EMPTY;

    int choice, key, result;

    while (1) {
        printf("\n1. Insert\n2. Search\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                result = search(key);
                if (result != -1)
                    printf("Key %d found at index %d\n", key, result);
                else
                    printf("Key %d not found in hash table\n", key);
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
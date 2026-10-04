#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define EMPTY -1

int hashTable[SIZE];

// Primary hash function
int h1(int key) {
    return key % SIZE;
}

// Secondary hash function
int h2(int key) {
    return 7 - (key % 7); // Example: SIZE = 10, 7 is a prime < SIZE
}

// Insert using double hashing
void insert(int key) {
    int index = h1(key);
    int step = h2(key);
    int i = 0, newIndex;

    while (i < SIZE) {
        newIndex = (index + i * step) % SIZE;
        if (hashTable[newIndex] == EMPTY) {
            hashTable[newIndex] = key;
            printf("Inserted %d at index %d\n", key, newIndex);
            return;
        }
        i++;
    }

    printf("Hash table is full. Cannot insert %d\n", key);
}

// Search using double hashing
int search(int key) {
    int index = h1(key);
    int step = h2(key);
    int i = 0, newIndex;

    while (i < SIZE) {
        newIndex = (index + i * step) % SIZE;
        if (hashTable[newIndex] == key)
            return newIndex;
        if (hashTable[newIndex] == EMPTY)
            return -1; // Key not found
        i++;
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
                    printf("Key %d not found\n", key);
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
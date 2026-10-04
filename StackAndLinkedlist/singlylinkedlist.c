#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Printing data of each node
void traverseNode(Node *node) {
    if(node == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Linked List Elements are:\n");
    while(node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Insert node at end
void insertNode(Node **head) {
    int value;
    printf("Enter value to insert: ");
    scanf("%d", &value);

    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if(*head == NULL) {
        *head = newNode;
        printf("Head node created\n");
        return;
    }

    Node *temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    printf("Node inserted\n");
}

// Insert node at head
void insertHeadNode(Node **head) {
    int value;
    printf("Enter value to insert: ");
    scanf("%d", &value);

    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if(*head == NULL) {
        *head = newNode;
        printf("Head node created\n");
        return;
    }

    newNode->next = *head;
    *head = newNode;

    printf("Node inserted successfully!\n");
}

// Insert node at index
void insertNodeAtIndex(Node **head) {
    traverseNode(*head);

    int index, i, data;
    printf("Enter the index to insert at: ");
    scanf("%d", &index);

    printf("Enter the data to insert: ");
    scanf("%d", &data);

    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    Node *temp = *head;

    for(i = 0; i < index - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Invalid index\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node inserted at index %d successfully!\n", index);
}

// Search node
void searchNode(Node *head) {
    int value;
    printf("Enter value to search: ");
    scanf("%d", &value);

    int position = 1;
    Node *temp = head;

    while(temp != NULL) {
        if(temp->data == value) {
            printf("Value %d found at position %d\n", value, position);
            return;
        }
        temp = temp->next;
        position++;
    }

    printf("Value not found\n");
}

// Delete last node
void deleteNode(Node **head) {

    if(*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Node deleted\n");
        return;
    }

    Node *temp = *head;
    Node *prev = NULL;

    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);

    printf("Node deleted\n");
}

// Delete head node
void deleteHeadNode(Node **head) {

    if(*head == NULL) {
        printf("List empty\n");
        return;
    }

    Node *temp = *head;
    *head = temp->next;

    free(temp);

    printf("Head node deleted\n");
}

// Free memory
void freeNodes(Node *head) {

    Node *temp;

    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {

    int choice;
    Node *head = NULL;

    do {

        printf("\n1. Insert Node (At end)\n");
        printf("2. Insert Node (At Head)\n");
        printf("3. Display Nodes\n");
        printf("4. Delete Node (At end)\n");
        printf("5. Delete Node (At first)\n");
        printf("6. Insert Node (via index)\n");
        printf("7. Search Node\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                insertNode(&head);
                break;

            case 2:
                insertHeadNode(&head);
                break;

            case 3:
                traverseNode(head);
                break;

            case 4:
                deleteNode(&head);
                break;

            case 5:
                deleteHeadNode(&head);
                break;

            case 6:
                insertNodeAtIndex(&head);
                break;

            case 7:
                searchNode(head);
                break;

            case 8:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 8);

    freeNodes(head);

    return 0;
}
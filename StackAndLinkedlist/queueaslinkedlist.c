#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

// Enqueue operation
void enqueue(int x)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = x;
    newnode->next = NULL;

    if(front == NULL && rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }

    printf("Inserted element: %d\n", x);
}

// Dequeue operation
void dequeue()
{
    struct node *temp;

    if(front == NULL)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        temp = front;
        printf("Deleted element: %d\n", front->data);
        front = front->next;
        free(temp);
    }
}

// Display operation
void display()
{
    struct node *temp;

    if(front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        temp = front;
        printf("Queue elements are:\n");

        while(temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    int choice, value;

    do
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d",&value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 4);

    return 0;
}
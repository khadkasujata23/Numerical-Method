#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

// Push operation
void push(int x)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = x;
    newnode->next = top;
    top = newnode;

    printf("Element inserted: %d\n", x);
}

// Pop operation
void pop()
{
    struct node *temp;

    if(top == NULL)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        temp = top;
        printf("Deleted element: %d\n", top->data);
        top = top->next;
        free(temp);
    }
}

// Display operation
void display()
{
    struct node *temp;

    if(top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        temp = top;
        printf("Stack elements are:\n");

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
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d",&value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice");
        }

    } while(choice!=4);

    return 0;
}
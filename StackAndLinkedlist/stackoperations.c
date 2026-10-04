#include<stdio.h>
#define MAX 5
int stack[MAX], top=-1;

void push(){
    int x;
    if(top==MAX-1)
        printf("Stack Overflow");
    else{
        printf("Enter value: ");
        scanf("%d",&x);
        stack[++top]=x;
    }
}

void pop(){
    if(top==-1)
        printf("Stack Underflow");
    else
        printf("Deleted: %d",stack[top--]);
}

void display(){
    if(top==-1)
        printf("Stack is empty");
    else{
        for(int i=top;i>=0;i--)
            printf("%d ",stack[i]);
    }
}

int main(){
    int ch;
    do{
        printf("\n1.Push 2.Pop 3.Display 4.Exit\n");
        scanf("%d",&ch);
        if(ch==1) push();
        else if(ch==2) pop();
        else if(ch==3) display();
    }while(ch!=4);
}

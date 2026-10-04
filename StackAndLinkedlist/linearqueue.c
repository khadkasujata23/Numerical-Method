#include<stdio.h>
#define MAX 5
int q[MAX], f=-1, r=-1;

void enqueue(){
    int x;
    if(r==MAX-1) printf("Overflow");
    else{
        printf("Enter value: ");
        scanf("%d",&x);
        if(f==-1) f=0;
        q[++r]=x;
    }
}

void dequeue(){
    if(f==-1||f>r) printf("Underflow");
    else printf("Deleted %d",q[f++]);
}

void display(){
    for(int i=f;i<=r;i++)
        printf("%d ",q[i]);
}

int main(){
    int ch;
    do{
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
        scanf("%d",&ch);
        if(ch==1) enqueue();
        else if(ch==2) dequeue();
        else if(ch==3) display();
    }while(ch!=4);
}

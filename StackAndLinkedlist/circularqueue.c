#include<stdio.h>
#define MAX 5
int q[MAX], f=0, r=0, count=0;

void enqueue(){
    int x;
    if(count==MAX) printf("Full");
    else{
        printf("Enter value: ");
        scanf("%d",&x);
        q[r]=x;
        r=(r+1)%MAX;
        count++;
    }
}

void dequeue(){
    if(count==0) printf("Empty");
    else{
        printf("Deleted %d",q[f]);
        f=(f+1)%MAX;
        count--;
    }
}

void display(){
    int i,idx=f;
    for(i=0;i<count;i++){
        printf("%d ",q[idx]);
        idx=(idx+1)%MAX;
    }
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

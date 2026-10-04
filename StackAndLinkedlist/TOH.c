#include<stdio.h>
void toh(int n,char s,char a,char d){
    if(n==1){
        printf("\nMove %c to %c",s,d);
        return;
    }
    toh(n-1,s,d,a);
    toh(1,s,a,d);
    toh(n-1,a,s,d);
}
int main(){
    int n;
    scanf("%d",&n);
    toh(n,'A','B','C');
}

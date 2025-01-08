#include<stdio.h>
#define max 5
int stack[max];
int top=-1;

void push(int data){
    if(top==max-1){
        printf("Stack overflow\n");
        return;
    }
    top=top+1;
    stack[top]=data;
}

int pop(){
    if(top==-1){
        printf("Stack underflow\n");
        return 1;
    }
    int x=stack[top];
    top=top-1;
    return x;
}

void display(){
    if(top==-1){
        printf("Stack is empty\n");
        return ;
    }
    for(int i=0;i<=top;i++){
        printf("%d ",stack[i]);
    }
}

int main(){
    push(1);
    push(2);
    push(3);
    pop();
    pop();
    pop();
    // pop();

    display();
    return 0;
}
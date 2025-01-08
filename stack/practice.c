#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 100

typedef struct stack{
    int top;
    int data[MAX];
}stack;

void intiate(stack* s){
    s->top=-1;
}
bool isstackfull(stack* s){
    return s->top==MAX-1;
}

bool isEmpty(stack* s){
    return s->top=-1;
}
void push(stack* s,int data){
    if(isstackfull(s)){
        printf("Stack overflow");
    }
    s->data[++(s->top)]=data;
}
void pop(stack* s){
    if(isEmpty(s)){
        printf("Stack underflow");
    }
    s->data[(s->top)--];
}


int peek(stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1; // return an invalid value
    }
    return s->data[s->top];
}

int main(){
    stack s;

    intiate(&s);
    push(&s,1);
    push(&s,2);
    push(&s,3);
    push(&s,4);
    push(&s,5);

    printf("%d",peek(&s));

}
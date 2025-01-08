#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* top=NULL;

node* createNode(int data){
    node* newNode=(node*)malloc(sizeof(node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void push(int data){
    node* newnode = createNode(data);
    if(top==NULL){
        top=newnode;
        return;
    }
    else{
        newnode->next=top;
        top=newnode;
    }
}


int pop(){
    if(top==NULL){
        printf("Stack is empty");
        return 0;
    }
    int x= top->data;
    top=top->next;
    return x;
}

void display(node* top){
    if(top==NULL){
        printf("Stack is empty");
    }
    if(top->next==NULL){
        printf("%d ",top->data);
        return;
    }
    display(top->next);
    printf("%d ",top->data);
}

int main(){
    push(1);
    push(2);
    push(3);
    display(top);
    printf("\n");
    printf("%d is deleted\n",pop());
    return 0;
}
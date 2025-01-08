#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* font=NULL;
node* rear=NULL;

node* createNode(int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void enqueue(int data){
    node* newnode=createNode(data);
    if(font==NULL){
        font=rear=newnode;
        return;
    }
    // newnode->next=rear
    rear->next=newnode;
    rear=rear->next;
}

int dequeue(){
    if(font==NULL){
        printf("Queue is empty\n");
        return 0;
    }
    int x=font->data;
    font=font->next;
    return x;

}

void display(){
    if(font==NULL){
        printf("Queue is empty\n");
        return;
    }
    node* temp=font;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}


int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    display();
    printf("\n");
    dequeue();
    display();
    return 0;

}
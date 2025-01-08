#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;

node* createnode(int data){
    node *new = (node*)malloc(sizeof(node));
    new->data=data;
    new->next=NULL;
    return new;
}
void insert_at_begin(node **head, int data){
    node *newnode = createnode(data);
    newnode->next=*head;
    *head=newnode;
}
void print(node *head){
    node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main(){

    node *head=NULL;
    insert_at_begin(&head,1);
    insert_at_begin(&head,2);
    insert_at_begin(&head,3);
    insert_at_begin(&head,4);
    insert_at_begin(&head,4);
    insert_at_begin(&head,5);

    print(head);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
node* createNew(int data){
    node *new = (node*)malloc(sizeof(node));
    new->data = data;
    new->next = NULL;
    return new;
}
void insertAtend(node **head,int data){
    node *temp = *head;

    if (temp == NULL) {  
        *head = createNew(data);
        return;
    }
    while(temp->next!=NULL){
        temp = temp->next;
    }
    node *new =  createNew(data);
    temp->next=new;
}
void print(node *head){
    node *temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("null\n");
}
int main(){

    node *head=NULL;
    insertAtend(&head,1);
    insertAtend(&head,2);
    insertAtend(&head,3);
    insertAtend(&head,4);
    insertAtend(&head,4);
    insertAtend(&head,5);

    print(head);
    return 0;
}
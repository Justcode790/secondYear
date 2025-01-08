#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *createNew (int data){
    node *new = (node*)malloc(sizeof(node));
    new->data=data;
    new->next=NULL;
    return new;
}

void insert_at_begin(node **head, int data){
    node *newnode = createNew(data);
    newnode->next=*head;
    *head=newnode;
}

void insert_Before_pos(node **head, int data , int key){
    if(*head==NULL){
        return;
    }
    if((*head)->data==key){
        insert_at_begin(head,data);
        return;
    }

    node *prepos = *head;
    node *pos = (*head)->next;
    while(pos!=NULL){
        if(pos->data==key){
            node *newNode = createNew(data);
            newNode->next=pos;
            prepos->next=newNode;
            return;
        }
        prepos=pos;
        pos=pos->next;
    }
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
    insert_at_begin(&head, 1);
    insert_at_begin(&head, 2);
    insert_at_begin(&head, 3);
    insert_at_begin(&head, 4);
    insert_at_begin(&head, 5);

    printf("Original List: ");
    print(head);

    insert_Before_pos(&head, 6, 5);
    printf("After Insertion: ");
    print(head);
    return 0;
}
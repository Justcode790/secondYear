#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;

node *createNode(int data){
    node *newN=(node*)malloc(sizeof(node));
    newN->data=data;
    newN->next=NULL;
    return newN;
}
void end(node **head,int data){
    node *pos = *head;
    if (pos == NULL){
        *head = createNode(data);
        return;
    }
    while(pos->next!=NULL){
        pos=pos->next;
    }
    node *new = createNode(data);
    pos->next=new;

}

void print(node **head){
    node *temp = *head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main(){
    node *head=NULL;
    int data;
    printf("Enter data and enter -1 to exit: ");
    scanf("%d",&data);
    while(data!=-1){
    printf("Enter data and enter -1 to exit: ");
        end(&head,data);
        scanf("%d",&data);
    }
    print(&head);

    return 0;
}
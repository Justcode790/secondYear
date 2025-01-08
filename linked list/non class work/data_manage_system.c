#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;

node* createNode(int data){
    node *new = (node*)malloc(sizeof(node));
    new->data=data;
    new->next=NULL;
    return new;
}
void insert_At_end(node **head,int data){
    node *temp = *head;
    if (temp == NULL) {  
        *head = createNode(data);
        return;
    }
    while(temp->next!=NULL){
        temp = temp->next;
    }
    node *new =  createNode(data);
    temp->next=new;
}


void insert_at_begin(node **head, int data){
    node *newnode = createNode(data);
    newnode->next=*head;
    *head=newnode;
}

void insert_at_before_pos(node **head, int data, int index){
    int flag=1;
    node *new = createNode(data);
    node *prepos = *head;
    node *pos =(*head)->next;
    while(flag<=index-1){
        pos=pos->next;
        flag++;
    }
    new->next=prepos->next;
    prepos->next= new;
}

void insert_at_after_pos(node **head, int data, int index){
    int flag=1;
    node *new = createNode(data);
    node *pos = *head;
    while(flag<=index-1){
        pos=pos->next;
        flag++;
    }
    new->next=pos->next;
    pos->next= new;
}

void delete_node(node **head, int key){
    node * pos= *head;
    node *prepos = NULL;
    if(pos!=NULL && pos->data==key){
        *head =pos->next;
        // free(pos);
        return;
    }
    
    while(pos!=NULL){
        if(pos->data==key){
            prepos->next=pos->next;
            return;
        }
        prepos=pos;
        pos=pos->next;
    }
    if(pos==NULL){
        return;
    }
}
void display(node *head){
    node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void create(node **head) {
    int data;
    printf("Enter number and -1 to exit: ");
    scanf("%d", &data);
    
    while (data != -1) {
        insert_At_end(head, data);
        printf("Enter number and -1 to exit: ");
        scanf("%d", &data);
    } 
}

void display_menu(){
    printf("\n1:create\n");
    printf("2:Display\n");
    printf("3:Insert at beginning\n");
    printf("4:Insert at end\n");
    printf("5:Insert at before pos\n");
    printf("6:Insert at after pos\n");
    printf("7:delete\n");
}
int main(){
    node *head =NULL;
    int n;
    while (1) {
        display_menu();
        printf("Enter the Number to perform operation: ");
        scanf("%d", &n);

        switch (n) {
            case 1:
                create(&head);
                break;
            case 2:
            printf("Here is your output which you hava entered: ");
                display(head);
                break;
            case 3:
                printf("Enter number to insert at the beginning: ");
                int dataB;
                scanf("%d", &dataB);
                insert_at_begin(&head, dataB);
                break;
            case 4:
                printf("Enter number to insert at the end: ");
                int dataE;
                scanf("%d", &dataE);
                insert_At_end(&head, dataE);
                break;
            case 5:

                printf("Enter the number you want to insert: ");
                int dataBeforePos,index;
                scanf("%d",&dataBeforePos);
                printf("enter index before which you want to insert: ");
                scanf("%d",&index);
                insert_at_before_pos(&head,dataBeforePos,index);
                break;
            case 6:
                printf("Enter the number you want to insert: ");
                int dataAfterPos,index1;
                scanf("%d",&dataAfterPos);
                printf("enter index after which you want to insert: ");
                scanf("%d",&index1);
                insert_at_after_pos(&head,dataAfterPos,index1);
                break;
            case 7:
                printf("enter number after which you want to delete: ");
                int key;
                scanf("%d",&key);
                delete_node(&head,key);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
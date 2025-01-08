#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node* head;

void Create() {
    struct node* newnode;
    cout << "Enter data: -1 for end: ";
    int value;
    cin >> value;

    while(value != -1) {
        newnode = (struct node*) malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            ptr = head;
        } else {
            ptr->next = newnode;
            ptr = ptr->next;
        }

        cout << "Enter data: -1 for end: ";
        cin >> value;
    }
}

void Display(){
    ptr = head;
    if(ptr == NULL){
        cout<<"The List is Empty:"<<endl;
        return;
    }
    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr = ptr-> next;
    }
    cout<<endl;
}

int main(){
    int choice;
    do{
        printf("1. create:\n");
        printf("2. display:\n");
        printf("3. exit\n");
        
        printf("Enter the choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                Create();
                break;
            case 2:
                Display();
                break;
        }
    }while(choice != 3);

}
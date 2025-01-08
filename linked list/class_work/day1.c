#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node* createnode(int data) {
    node* new = (node*)malloc(sizeof(node));
    new->data = data;
    new->next = NULL;
    return new;
}

void insertAtbegin(node **head, int data) {
    node* new = createnode(data);
    new->next = *head;
    *head = new;
}

void insertAtend(node **head, int data) {
    node* new = createnode(data);
    if (*head == NULL) {
        *head = new;
        return;
    }
    node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new;
}

void insertAtmidAfterKey(node **head, int data, int key) {
    node* new = createnode(data);
    node* temp = *head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp != NULL) {
        new->next = temp->next;
        temp->next = new;
    } else {
        printf("Key not found.\n");
    }
}

void insertAtbeforeKey(node **head, int data, int key) {
    node* new = createnode(data);
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if ((*head)->data == key) {
        new->next = *head;
        *head = new;
        return;
    }
    node* preTemp = *head;
    node* temp = (*head)->next;
    while (temp != NULL && temp->data != key) {
        preTemp = temp;
        temp = temp->next;
    }
    if (temp != NULL) {
        new->next = temp;
        preTemp->next = new;
    } else {
        printf("Key not found.\n");
    }
}

void print(node *head) {
    node* temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    node *head = NULL;
    int choice, data, key;

    do {
        printf("\n1: Add data continuously (-1 to stop)\n");
        printf("2: Display\n");
        printf("3: Add at the beginning\n");
        printf("4: Add at the end\n");
        printf("5: Add before any element\n");
        printf("6: Add after any element\n");
        printf("7: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to add continuously (-1 to stop): \n");
                while (1) {
                    scanf("%d", &data);
                    if (data == -1) break;
                    insertAtend(&head, data); // Adding at the end
                }
                break;
            case 2:
                print(head);
                break;
            case 3:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtbegin(&head, data);
                break;
            case 4:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtend(&head, data);
                break;
            case 5:
                printf("Enter data and key (insert before key): ");
                scanf("%d %d", &data, &key);
                insertAtbeforeKey(&head, data, key);
                break;
            case 6:
                printf("Enter data and key (insert after key): ");
                scanf("%d %d", &data, &key);
                insertAtmidAfterKey(&head, data, key);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 7);

    return 0;
}

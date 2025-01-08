#include <stdio.h>
#include <stdbool.h>
#define MAX 100

typedef struct {
    int top;
    int arr[MAX];
} stack;

void initialise(stack* a) {
    a->top = -1;
}

bool isempty(stack a) {
    return a.top == -1;
}

bool isfull(stack a) {
    return a.top == MAX - 1;
}

void push(stack* a, int data) {
    if (isfull(*a)) {  
        printf("Stack is full\n");
    } else {
        a->top = a->top + 1;
        a->arr[a->top] = data;
    }
}

int pop(stack* a) {
    if (isempty(*a)) {  
        printf("Stack is empty\n");
        return -1;  
    } else {
        int x = a->arr[a->top];
        a->top--;
        return x; 
    }
}

void display(stack a) {
    if (isempty(a)) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = 0; i <= a.top; i++) { 
        printf("%d ", a.arr[i]);
    }
    printf("\n");
}

int main() {
    stack a;
    initialise(&a);  
    int choice;
    do {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int data;
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(&a, data);
                break;
            }
            case 2: {
                int po = pop(&a);  
                if (po != -1) {
                    printf("%d is popped up\n", po);
                }
                break;
            }
            case 3:
                display(a);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

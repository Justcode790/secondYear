#include<stdio.h>
#define MAX 20

int arr[MAX];
int front = -1;
int rear = -1;

void enqueue(int data) {
    if (rear == MAX - 1) {
        printf("Overflow\n");
    } else {
        if (front == -1) front = 0;  
        rear++;
        arr[rear] = data;
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Underflow\n");
    } else {
        printf("%d is removed\n", arr[front]);
        front++;
        if (front > rear) {
            front = rear = -1;  
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        for (int i = front; i <= rear; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    do {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int data;
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            }
            case 2: {
                dequeue();
                break;
            }
            case 3:
                display();
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

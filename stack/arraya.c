#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int top;
    int items[MAX];
} Stack;

// Initialize the stack
void initStack(Stack* s) {
    s->top = -1;
}

// Check if the stack is empty
bool isEmpty(Stack* s) {
    return s->top == -1;
}

// Check if the stack is full
bool isFull(Stack* s) {
    return s->top == MAX - 1;
}

// Push an element onto the stack
void push(Stack* s, int item) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        return;
    }
    printf("%d ",s->top);
    s->items[++(s->top)] = item;
}

// Pop an element from the stack
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return -1; // return an invalid value
    }
    return s->items[(s->top)--];
}

// Peek at the top element
int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1; // return an invalid value
    }
    return s->items[s->top];
}

// Example usage
int main() {
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top element: %d\n", peek(&s));
    printf("Popped element: %d\n", pop(&s));
    printf("Top element after pop: %d\n", peek(&s));

    return 0;
}
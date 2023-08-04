#include <stdio.h>

#define MAX_SIZE 100

// Stack data structure
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// Initialize an empty stack
void init(Stack* stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Check if the stack is full
int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Push an element onto the stack
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->top++;
    stack->data[stack->top] = value;
}

// Pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1; // Return some sentinel value to indicate failure
    }
    int value = stack->data[stack->top];
    stack->top--;
    return value;
}

// Peek the top element of the stack without removing it
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1; // Return some sentinel value to indicate failure
    }
    return stack->data[stack->top];
}

int main() {
    Stack myStack;
    init(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    printf("Top element: %d\n", peek(&myStack));

    printf("Popping elements: ");
    while (!isEmpty(&myStack)) {
        printf("%d ", pop(&myStack));
    }
    printf("\n");

    return 0;
}


#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int top;
    int array[MAX_SIZE];
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

int is_empty(Stack *stack) {
    return stack->top == -1;
}

int is_full(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, int item) {
    if (is_full(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
}

int pop(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->array[stack->top--];
}

int peek(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->array[stack->top];
}

int main() {
	int i;
    Stack stack;
    initialize(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    printf("Stack: ");
    for ( i = 0; i <= stack.top; ++i) {
        printf("%d ", stack.array[i]);
    }
    printf("\n");

    printf("Top element: %d\n", peek(&stack));

    printf("Popped element: %d\n", pop(&stack));

    printf("Stack: ");
    for ( i = 0; i <= stack.top; ++i) {
        printf("%d ", stack.array[i]);
    }
    printf("\n");

    return 0;
}

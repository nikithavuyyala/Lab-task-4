#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    int stack[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

void push(Stack *s, int num) {
    s->stack[++(s->top)] = num;
}

int pop(Stack *s) {
    return s->stack[(s->top)--];
}

int evaluatePostfix(const char *postfix) {
    Stack operandStack;
    initStack(&operandStack);
    int i = 0;
    while (postfix[i] != '\0') {
        char c = postfix[i];
        if (isdigit(c)) {
            push(&operandStack, c - '0'); // Convert char to int
        } else if (c == ' ') {
            // Ignore whitespace
        } else {
            // Operator
            int operand2 = pop(&operandStack);
            int operand1 = pop(&operandStack);
            switch (c) {
                case '+':
                    push(&operandStack, operand1 + operand2);
                    break;
                case '-':
                    push(&operandStack, operand1 - operand2);
                    break;
                case '*':
                    push(&operandStack, operand1 * operand2);
                    break;
                case '/':
                    push(&operandStack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator\n");
                    exit(EXIT_FAILURE);
            }
        }
        i++;
    }
    return pop(&operandStack);
}

int main() {
    char postfix[MAX_SIZE];
    printf("Enter postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);
    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);
    return 0;
}

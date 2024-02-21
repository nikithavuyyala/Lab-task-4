#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char stack[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

void push(Stack *s, char c) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->stack[++(s->top)] = c;
}

char pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->stack[(s->top)--];
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void infixToPostfix(char *infix, char *postfix) {
    Stack operatorStack;
    initStack(&operatorStack);
    int i, j = 0;
    for (i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(&operatorStack, c);
        } else if (c == ')') {
            while (operatorStack.top != -1 && operatorStack.stack[operatorStack.top] != '(') {
                postfix[j++] = pop(&operatorStack);
            }
            pop(&operatorStack);  // Discard the '('
        } else {
            while (operatorStack.top != -1 && precedence(operatorStack.stack[operatorStack.top]) >= precedence(c)) {
                postfix[j++] = pop(&operatorStack);
            }
            push(&operatorStack, c);
        }
    }
    while (operatorStack.top != -1) {
        postfix[j++] = pop(&operatorStack);
    }
    postfix[j] = '\0';  // Null-terminate the postfix string
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    printf("Enter infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0'; // Remove newline character if present
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}

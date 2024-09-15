#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 // Maximum size of stack

// Stack structure
typedef struct Stack {
    char arr[MAX];
    int top;
} Stack;

// Initialize the stack
void init(Stack *s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Check if stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Push to stack
void push(Stack *s, char val) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++(s->top)] = val;
}

// Pop from stack
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return s->arr[(s->top)--];
}

// Check if the characters are matching pairs
int isMatchingPair(char left, char right) {
    return (left == '(' && right == ')') ||
           (left == '{' && right == '}') ||
           (left == '[' && right == ']');
}

// Function to check if the parentheses are balanced
int isBalanced(char *exp) {
    Stack stack;
    init(&stack);
    int i;

    // Traverse the expression
    for (i = 0; exp[i] != '\0'; i++) {
        // If the character is an opening parenthesis, push it onto the stack
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(&stack, exp[i]);
        }
        // If the character is a closing parenthesis
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            // If stack is empty or the top element doesn't match the closing parenthesis
            if (isEmpty(&stack) || !isMatchingPair(pop(&stack), exp[i])) {
                return 0; // Not balanced
            }
        }
    }

    // If the stack is empty at the end, the expression is balanced
    return isEmpty(&stack);
}

int main() {
    char expression[MAX];
    printf("Enter an expression: ");
    fgets(expression, MAX, stdin);

    // Remove newline character from input if present
    expression[strcspn(expression, "\n")] = 0;

    if (isBalanced(expression)) {
        printf("The expression is balanced.\n");
    } else {
        printf("The expression is not balanced.\n");
    }

    return 0;
}

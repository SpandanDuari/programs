#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100 // Maximum size of stack

// Stack structure
typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;

// Initialize stack
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
void push(Stack *s, int val) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++(s->top)] = val;
}

// Pop from stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

// Evaluate the postfix expression
int evaluatePostfix(char *exp) {
    Stack stack;
    init(&stack);
    int i;

    // Scan all characters in the expression
    for (i = 0; exp[i]; i++) {
        // Skip whitespace
        if (isspace(exp[i]))
            continue;

        // If the character is a digit, push it to the stack
        if (isdigit(exp[i])) {
            int num = 0;
            // To handle multi-digit numbers
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            i--; // As the loop will increment i one extra time
            push(&stack, num);
        }
        // If the character is an operator, pop two elements and apply the operator
        else {
            int val1 = pop(&stack);
            int val2 = pop(&stack);
            switch (exp[i]) {
                case '+': push(&stack, val2 + val1); break;
                case '-': push(&stack, val2 - val1); break;
                case '*': push(&stack, val2 * val1); break;
                case '/': push(&stack, val2 / val1); break;
                default: 
                    printf("Invalid operator encountered: %c\n", exp[i]);
                    return -1;
            }
        }
    }
    return pop(&stack);
}

int main() {
    char expression[MAX];
    printf("Enter a postfix expression: ");
    fgets(expression, MAX, stdin);

    int result = evaluatePostfix(expression);
    printf("The result is: %d\n", result);
    
    return 0;
}

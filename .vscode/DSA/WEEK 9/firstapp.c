#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Define a structure for Stack
struct Stack {
    int items[MAX];
    int top;
};

// Function to initialize a stack
void initStack(struct Stack* s) {
    s->top = -1;
}

// Function to check if the stack is full
int isFull(struct Stack* s) {
    return s->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
    } else {
        s->items[++s->top] = value;
    }
}

// Function to pop an element from the stack
int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return s->items[s->top--];
    }
}

// Function to return the top element of the stack
int peek(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return s->items[s->top];
    }
}

// 1. Application: Balanced Parentheses Checking
int isBalanced(char* expr) {
    struct Stack s;
    initStack(&s);
    for (int i = 0; i < strlen(expr); i++) {
        if (expr[i] == '(') {
            push(&s, expr[i]);
        } else if (expr[i] == ')') {
            if (isEmpty(&s)) {
                return 0; // Unbalanced
            } else {
                pop(&s);
            }
        }
    }
    return isEmpty(&s); // Returns 1 if balanced, 0 if not
}

// 2. Application: Postfix Expression Evaluation
int evaluatePostfix(char* expr) {
    struct Stack s;
    initStack(&s);
    for (int i = 0; i < strlen(expr); i++) {
        if (isdigit(expr[i])) {
            // Push operand to stack
            push(&s, expr[i] - '0');
        } else {
            // Pop two operands and apply operator
            int val1 = pop(&s);
            int val2 = pop(&s);
            switch (expr[i]) {
                case '+': push(&s, val2 + val1); break;
                case '-': push(&s, val2 - val1); break;
                case '*': push(&s, val2 * val1); break;
                case '/': push(&s, val2 / val1); break;
            }
        }
    }
    return pop(&s); // Result is the last item in the stack
}

// 3. Stack Operations Example (Push, Pop, Peek)
void stackOperationsExample() {
    struct Stack s;
    initStack(&s);

    // Pushing elements
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    // Display top element
    printf("Top element is %d\n", peek(&s));

    // Pop element
    printf("Popped element is %d\n", pop(&s));

    // Display top element after pop
    printf("Top element after pop is %d\n", peek(&s));
}

int main() {
    // 1. Check for Balanced Parentheses
    char expr1[] = "(1+2)*(3+(4/2))";
    if (isBalanced(expr1)) {
        printf("Expression is balanced.\n");
    } else {
        printf("Expression is not balanced.\n");
    }

    // 2. Evaluate Postfix Expression
    char postfix[] = "231*+9-";
    printf("Postfix expression evaluation result: %d\n", evaluatePostfix(postfix));

    // 3. Demonstrate Stack Operations
    stackOperationsExample();

    return 0;
}

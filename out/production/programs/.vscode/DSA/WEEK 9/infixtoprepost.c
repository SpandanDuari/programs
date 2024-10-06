#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack structure for characters
struct Stack {
    int top;
    char items[MAX];
};

// Initialize stack
void initStack(struct Stack* s) {
    s->top = -1;
}

// Check if the stack is empty
int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// Check if the stack is full
int isFull(struct Stack* s) {
    return s->top == MAX - 1;
}

// Push an element onto the stack
void push(struct Stack* s, char value) {
    if (!isFull(s)) {
        s->items[++s->top] = value;
    } else {
        printf("Stack Overflow\n");
    }
}

// Pop an element from the stack
char pop(struct Stack* s) {
    if (!isEmpty(s)) {
        return s->items[s->top--];
    } else {
        printf("Stack Underflow\n");
        return '\0';
    }
}

// Peek at the top element of the stack
char peek(struct Stack* s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    } else {
        return '\0';
    }
}

// Function to check if the character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to get the precedence of an operator
int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

// Function to check associativity of operators
int isRightAssociative(char op) {
    return op == '^';
}

// 1. Infix to Postfix Conversion
void infixToPostfix(char* infix, char* postfix) {
    struct Stack s;
    initStack(&s);
    int i, k = 0;

    for (i = 0; i < strlen(infix); i++) {
        char c = infix[i];

        // If the character is an operand, add it to the result
        if (isalnum(c)) {
            postfix[k++] = c;
        }
        // If the character is '(', push it to the stack
        else if (c == '(') {
            push(&s, c);
        }
        // If the character is ')', pop and output from the stack until '(' is found
        else if (c == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[k++] = pop(&s);
            }
            pop(&s);  // Remove '(' from the stack
        }
        // If the character is an operator
        else if (isOperator(c)) {
            while (!isEmpty(&s) && precedence(peek(&s)) > precedence(c) ||
                   (precedence(peek(&s)) == precedence(c) && !isRightAssociative(c))) {
                postfix[k++] = pop(&s);
            }
            push(&s, c);
        }
    }

    // Pop all the operators from the stack
    while (!isEmpty(&s)) {
        postfix[k++] = pop(&s);
    }
    postfix[k] = '\0';
}

// 2. Reverse a string
void reverse(char* exp) {
    int n = strlen(exp);
    for (int i = 0; i < n / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[n - i - 1];
        exp[n - i - 1] = temp;
    }
}

// 3. Infix to Prefix Conversion
void infixToPrefix(char* infix, char* prefix) {
    // Reverse the infix expression
    reverse(infix);

    // Replace '(' with ')' and vice versa
    for (int i = 0; i < strlen(infix); i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    // Convert the modified infix to postfix
    char postfix[MAX];
    infixToPostfix(infix, postfix);

    // Reverse the postfix expression to get the prefix
    reverse(postfix);
    strcpy(prefix, postfix);
}

int main() {
    char infix[MAX], postfix[MAX], prefix[MAX];

    // Input Infix Expression
    printf("Enter infix expression: ");
    scanf("%s", infix);

    // Convert to Postfix
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    // Convert to Prefix
    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);

    return 0;
}

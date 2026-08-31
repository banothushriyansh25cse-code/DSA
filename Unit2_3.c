#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push an operator onto stack
void push(char ch) {
    stack[++top] = ch;
}

// Pop an operator from stack
char pop() {
    return stack[top--];
}

// Return precedence of operator
int precedence(char ch) {
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;

    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i, j = 0;
    char ch;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for (i = 0; i < strlen(infix); i++) {
        ch = infix[i];

        // If operand, add directly to postfix
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }

        // If opening parenthesis, push onto stack
        else if (ch == '(') {
            push(ch);
        }

        // If closing parenthesis
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();  // Remove '('
        }

        // If operator
        else {
            while (top != -1 &&
                   stack[top] != '(' &&
                   (precedence(stack[top]) > precedence(ch) ||
                   (precedence(stack[top]) == precedence(ch) && ch != '^'))) {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
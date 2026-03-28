#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = ch;
    }
}

char pop() {
    if (top == -1) {
        return '\0';
    } else {
        return stack[top--];
    }
}


int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')')
        return 1;
    if (open == '{' && close == '}')
        return 1;
    if (open == '[' && close == ']')
        return 1;
    return 0;
}


int isBalanced(char expr[]) {
    int i;
    char ch;

    for (i = 0; i < strlen(expr); i++) {
        char current = expr[i];

        
        if (current == '(' || current == '{' || current == '[') {
            push(current);
        }

        
        else if (current == ')' || current == '}' || current == ']') {
            ch = pop();

            if (ch == '\0' || !isMatchingPair(ch, current)) {
                return 0; 
            }
        }
    }

    return (top == -1);
}


int main() {
    char expr[MAX];

    printf("Enter expression: ");
    scanf("%s", expr);

    if (isBalanced(expr)) {
        printf("Balanced Expression\n");
    } else {
        printf("Not Balanced Expression\n");
    }

    return 0;
}
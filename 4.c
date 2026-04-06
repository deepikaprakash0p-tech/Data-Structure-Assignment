#include <stdio.h>

char stack[100];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int match(char a, char b) {
    return (a == '(' && b == ')') ||
           (a == '{' && b == '}') ||
           (a == '[' && b == ']');
}

int main() {
    char exp[100];
    printf("Enter expression: ");
    scanf("%s", exp);

    for (int i = 0; exp[i]; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1 || !match(pop(), exp[i])) {
                printf("Invalid Expression\n");
                return 0;
            }
        }
    }

    if (top == -1)
        printf("Valid Expression\n");
    else
        printf("Invalid Expression\n");

    return 0;
}
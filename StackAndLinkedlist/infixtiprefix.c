#include <stdio.h>
#include <string.h>
#define MAX 50

char stack[MAX];
int top = -1;

/* Push operation */
void push(char x) {
    if (top < MAX - 1)
        stack[++top] = x;
}

/* Pop operation */
char pop() {
    if (top == -1)
        return '\0';
    return stack[top--];
}

/* Operator priority */
int priority(char x) {
    if (x == '^') return 3;
    if (x == '*' || x == '/' || x == '%') return 2;
    if (x == '+' || x == '-') return 1;
    return 0;
}

/* Reverse string */
void reverse(char s[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

/* Check operand */
int isOperand(char ch) {
    if ((ch >= 'A' && ch <= 'Z') ||
        (ch >= 'a' && ch <= 'z') ||
        (ch >= '0' && ch <= '9'))
        return 1;
    return 0;
}

int main() {
    char infix[MAX], prefix[MAX];
    int i, j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    /* Step 1: Reverse infix */
    reverse(infix);

    /* Step 2: Change brackets */
    for (i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    /* Step 3: Infix to Postfix */
    for (i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isOperand(ch)) {
            prefix[j++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(')
                prefix[j++] = pop();
            pop();   // remove '('
        }
        else {  // operator
            while (top != -1 &&
                   priority(stack[top]) > priority(ch)) {
                prefix[j++] = pop();
            }
            push(ch);
        }
    }

    /* Pop remaining operators */
    while (top != -1)
        prefix[j++] = pop();

    prefix[j] = '\0';

    /* Step 4: Reverse postfix to get prefix */
    reverse(prefix);

    printf("Prefix Expression: %s\n", prefix);

    return 0;
}

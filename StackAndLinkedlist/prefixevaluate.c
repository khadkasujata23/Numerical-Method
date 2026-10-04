#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

char stack[50];
int top = -1;

int valStack[50];
int vtop = -1;

/* Stack operations */
void push(char x) { stack[++top] = x; }
char pop() { return stack[top--]; }

void pushVal(int x) { valStack[++vtop] = x; }
int popVal() { return valStack[vtop--]; }

/* Priority */
int priority(char x) {
    if (x == '^') return 3;
    if (x == '*' || x == '/') return 2;
    if (x == '+' || x == '-') return 1;
    return 0;
}

/* Reverse string */
void reverse(char exp[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(exp) - 1; i < j; i++, j--) {
        temp = exp[i];
        exp[i] = exp[j];
        exp[j] = temp;
    }
}

/* Infix to Prefix */
void infixToPrefix(char infix[], char prefix[]) {
    int i, k = 0;

    reverse(infix);

    for (i = 0; infix[i] != '\0'; i++) {
        if (isdigit(infix[i])) {
            prefix[k++] = infix[i];
        }
        else if (infix[i] == ')') {
            push(infix[i]);
        }
        else if (infix[i] == '(') {
            while (stack[top] != ')')
                prefix[k++] = pop();
            pop();
        }
        else {
            while (top != -1 && priority(stack[top]) > priority(infix[i]))
                prefix[k++] = pop();
            push(infix[i]);
        }
    }

    while (top != -1)
        prefix[k++] = pop();

    prefix[k] = '\0';
    reverse(prefix);
}

/* Evaluate Prefix */
int evaluatePrefix(char prefix[]) {
    int i, len = strlen(prefix);

    for (i = len - 1; i >= 0; i--) {
        if (isdigit(prefix[i])) {
            pushVal(prefix[i] - '0');
        } else {
            int a = popVal();
            int b = popVal();

            switch (prefix[i]) {
                case '+': pushVal(a + b); break;
                case '-': pushVal(a - b); break;
                case '*': pushVal(a * b); break;
                case '/': pushVal(a / b); break;
                case '^': pushVal(pow(a, b)); break;
            }
        }
    }
    return popVal();
}

int main() {
    char infix[50], prefix[50];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);
    printf("Result = %d", evaluatePrefix(prefix));

    return 0;
}

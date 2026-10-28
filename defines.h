#include<ctype.h>
#include<ctype.h>
#ifndef DEFINES_H
#define DEFINES_H

#define MAX 100
extern char stack[MAX];
extern int top;
#endif
void push(char ch)
{
    if (top < MAX - 1)
        stack[++top] = ch;
}

char pop(void)
{
    if (top >= 0)
        return stack[top--];

    return '\0';
}

int precedence(char op)
{
    switch (op)
    {
        case '^': return 3;
        case '*':
        case '/':
        case '%': return 2;
        case '+':
        case '-': return 1;
        default:  return 0;
    }
}
int isOperator(char ch)
{
    return ch == '+' || ch == '-' ||
           ch == '*' || ch == '/' ||
           ch == '%' || ch == '^';
}

int infixToPostfix(const char infix[], char postfix[])
{
    int i, j = 0;
    char ch;

    top = -1;

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        if (isspace((unsigned char)ch))
            continue;

        // Add operands directly to postfix
        if (isalnum((unsigned char)ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();

            if (top == -1)
                return 0;

            pop();  // Remove '('
        }
        else if (isOperator(ch))
        {
            while (top != -1 && stack[top] != '(' &&
                   (precedence(stack[top]) > precedence(ch) ||
                   (precedence(stack[top]) == precedence(ch)
                    && ch != '^')))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }
        else
        {
            return 0;  // Invalid character
        }
    }

    while (top != -1)
    {
        if (stack[top] == '(')
            return 0;  // Unmatched opening parenthesis

        postfix[j++] = pop();
    }

    postfix[j] = '\0';
    return 1;
}



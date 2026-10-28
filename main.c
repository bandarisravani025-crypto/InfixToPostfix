#include<stdio.h>
#include<string.h>
#include"defines.h"
#include"declaration.c"
#define MAX 100
char stack[MAX];
int top=-1;
int main()
{
    char infix[MAX];
    char postfix[MAX];
    printf("INFIX TO POSTFIX CONVERSION\n");
    printf("Enter an infix expression: ");

    if (fgets(infix, sizeof(infix), stdin) == NULL)
        return 1;

    infix[strcspn(infix, "\n")] = '\0';

    if (infixToPostfix(infix, postfix))
    {
        printf("Infix Expression   : %s\n", infix);
        printf("Postfix Expression : %s\n", postfix);
    }
    else
    {
        printf("Invalid expression!\n");
    }

    return 0;
}

void push(char ch);
char pop(void);
int precedence(char op);
int isOperator(char ch);
int infixToPostfix(const char infix[], char postfix[]);

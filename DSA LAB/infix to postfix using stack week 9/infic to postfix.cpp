#include <iostream>
using namespace std;

char stack[100];
int top = -1;

// PUSH
void push(char x)
{
    top++;
    stack[top] = x;
}

// POP
char pop()
{
    return stack[top--];
}

// PRIORITY FUNCTION
int priority(char x)
{
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if(x == '^')
        return 3;
    return 0;
}

int main()
{
    char infix[100], postfix[100];
    int i = 0, j = 0;

    cout << "Enter infix expression: ";
    cin >> infix;

    while(infix[i] != '\0')
    {
        char ch = infix[i];

        // If operand → directly add to postfix
        if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        {
            postfix[j++] = ch;
        }

        // If '(' → push
        else if(ch == '(')
        {
            push(ch);
        }

        // If ')' → pop until '('
        else if(ch == ')')
        {
            while(stack[top] != '(')
                postfix[j++] = pop();

            pop(); // remove '('
        }

        // If operator
        else
        {
            while(top != -1 && priority(stack[top]) >= priority(ch))
                postfix[j++] = pop();

            push(ch);
        }

        i++;
    }

    // Pop remaining operators
    while(top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';

    cout << "Postfix: " << postfix;

    return 0;
}
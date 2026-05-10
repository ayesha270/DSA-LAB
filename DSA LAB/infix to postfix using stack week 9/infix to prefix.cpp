#include <iostream>
#include <cstring>
using namespace std;

/* ---------- STACK ---------- */

char stack[100];
int top = -1;

/* ---------- PUSH ---------- */

void push(char ch)
{
    stack[++top] = ch;
}

/* ---------- POP ---------- */

char pop()
{
    return stack[top--];
}

/* ---------- PEEK ---------- */

char peek()
{
    return stack[top];
}

/* ---------- PRECEDENCE ---------- */

int precedence(char ch)
{
    if(ch == '^')
        return 3;

    if(ch == '*' || ch == '/')
        return 2;

    if(ch == '+' || ch == '-')
        return 1;

    return 0;
}

/* ---------- REVERSE STRING ---------- */

void reverse(char exp[])
{
    int len = strlen(exp);

    for(int i=0;i<len/2;i++)
    {
        char temp = exp[i];
        exp[i] = exp[len-i-1];
        exp[len-i-1] = temp;
    }
}

/* ---------- INFIX TO PREFIX ---------- */

void infixToPrefix(char infix[])
{
    char prefix[100];
    int k = 0;

    // STEP 1: reverse infix
    reverse(infix);

    // STEP 2: swap brackets
    for(int i=0; infix[i] != '\0'; i++)
    {
        if(infix[i] == '(')
            infix[i] = ')';

        else if(infix[i] == ')')
            infix[i] = '(';
    }

    // STEP 3: infix → postfix
    for(int i=0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];

        // operand
        if((ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z') ||
           (ch >= '0' && ch <= '9'))
        {
            prefix[k++] = ch;
        }

        // opening bracket
        else if(ch == '(')
        {
            push(ch);
        }

        // closing bracket
        else if(ch == ')')
        {
            while(peek() != '(')
                prefix[k++] = pop();

            pop(); // remove '('
        }

        // operator
        else
        {
            while(top != -1 &&
                  precedence(peek()) >= precedence(ch))
            {
                prefix[k++] = pop();
            }

            push(ch);
        }
    }

    // pop remaining operators
    while(top != -1)
        prefix[k++] = pop();

    prefix[k] = '\0';

    // STEP 4: reverse postfix → prefix
    reverse(prefix);

    cout << "Prefix = " << prefix;
}

/* ---------- MAIN ---------- */

int main()
{
    char infix[100];

    cout << "Enter infix expression: ";
    cin >> infix;

    infixToPrefix(infix);

    return 0;
}
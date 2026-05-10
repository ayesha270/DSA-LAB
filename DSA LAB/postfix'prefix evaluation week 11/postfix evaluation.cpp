#include <iostream>
#include <cmath>
using namespace std;

/* ---------- STACK ---------- */

int stack[100];
int top = -1;

/* ---------- PUSH ---------- */

void push(int x)
{
    stack[++top] = x;
}

/* ---------- POP ---------- */

int pop()
{
    return stack[top--];
}

/* ---------- MAIN ---------- */

int main()
{
    char postfix[100];

    cout << "Enter postfix expression: ";
    cin >> postfix;

    int i = 0;

    while(postfix[i] != '\0')
    {
        char ch = postfix[i];

        // operand
        if(ch >= '0' && ch <= '9')
        {
            push(ch - '0');
        }

        // operator
        else
        {
            int val2 = pop();
            int val1 = pop();

            switch(ch)
            {
                case '+':
                    push(val1 + val2);
                    break;

                case '-':
                    push(val1 - val2);
                    break;

                case '*':
                    push(val1 * val2);
                    break;

                case '/':
                    push(val1 / val2);
                    break;

                case '^':
                    push(pow(val1, val2));
                    break;
            }
        }

        i++;
    }

    cout << "Result = " << pop();

    return 0;
}
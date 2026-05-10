#include <iostream>
#include <cmath>
#include <cstring>
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
    char prefix[100];

    cout << "Enter prefix expression: ";
    cin >> prefix;

    int len = strlen(prefix);

    // Traverse from RIGHT to LEFT
    for(int i = len-1; i >= 0; i--)
    {
        char ch = prefix[i];

        // operand
        if(ch >= '0' && ch <= '9')
        {
            push(ch - '0');
        }

        // operator
        else
        {
            int val1 = pop();
            int val2 = pop();

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
    }

    cout << "Result = " << pop();

    return 0;
}
#include <iostream>
#include <cmath>
using namespace std;

/* ---------- TREE NODE ---------- */
struct Node
{
    char data;
    Node* left;
    Node* right;
};

/* ---------- STACKS ---------- */
int valStack[100];     // for evaluation
Node* nodeStack[100]; // for tree

int top1 = -1; // value stack top
int top2 = -1; // node stack top

/* ---------- PUSH/POP VALUE ---------- */
void pushVal(int x)
{
    valStack[++top1] = x;
}

int popVal()
{
    return valStack[top1--];
}

/* ---------- PUSH/POP NODE ---------- */
void pushNode(Node* x)
{
    nodeStack[++top2] = x;
}

Node* popNode()
{
    return nodeStack[top2--];
}

/* ---------- CREATE NODE ---------- */
Node* createNode(char x)
{
    Node* temp = new Node;
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

/* ---------- INORDER (CHECK TREE) ---------- */
void inorder(Node* root)
{
    if(root)
    {
        inorder(root->left);
        cout << root->data;
        inorder(root->right);
    }
}

/* ---------- MAIN ---------- */
int main()
{
    char postfix[100];
    cout << "Enter postfix: ";
    cin >> postfix;

    int i = 0;

    while(postfix[i] != '\0')
    {
        char ch = postfix[i];

        // OPERAND
        if(ch >= '0' && ch <= '9')
        {
            // evaluation
            pushVal(ch - '0');

            // tree
            pushNode(createNode(ch));
        }
        else
        {
            /* ----- EVALUATION ----- */
            int val2 = popVal();
            int val1 = popVal();
            int result;

            switch(ch)
            {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                case '^': result = pow(val1, val2); break;
            }

            pushVal(result);

            /* ----- TREE ----- */
            Node* right = popNode();
            Node* left = popNode();

            Node* op = createNode(ch);
            op->left = left;
            op->right = right;

            pushNode(op);
        }

        i++;
    }

    cout << "\nResult = " << popVal();

    Node* root = popNode();

    cout << "\nInorder Expression: ";
    inorder(root);

    return 0;
}
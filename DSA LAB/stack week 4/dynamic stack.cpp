#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* top = NULL;

// Push
void push(int value) {
    node* newNode = new node;

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    cout << value << " pushed\n";
}

// Pop
void pop() {
    if (top == NULL) {
        cout << "Stack Underflow!\n";
        return;
    }

    node* temp = top;
    cout << top->data << " popped\n";

    top = top->next;
    delete temp;
}

// Peek
void peek() {
    if (top == NULL) {
        cout << "Stack is empty\n";
        return;
    }

    cout << "Top element: " << top->data << endl;
}

int main() {

    push(10);
    push(20);
    push(30);

    pop();
    peek();

    return 0;
}

#include <iostream>
using namespace std;

int stack[5];   // Stack array
int top = 0;    // Top starts from 0
int size = 5;   // Maximum size

// Push function
void push(int value) {
    if (top == 5) {
        cout << "Stack Overflow!\n";
        return;
    }

    stack[top] = value;
    top++;
    cout << value << " pushed\n";
}

// Pop function
void pop() {
    if (top == 0) {
        cout << "Stack Underflow!\n";
        return;
    }

    top--;
    cout << stack[top] << " popped\n";
}

// Peek function
void peek() {
    if (top == 0) {
        cout << "Stack is empty\n";
        return;
    }

    cout << "Top element: " << stack[top - 1] << endl;
}

// Display function
void display() {
    if (top == 0) {
        cout << "Stack is empty\n";
        return;
    }

    cout << "Stack elements: ";
    for (int i = top - 1; i >= 0; i--) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main() {
    push(10);
    push(20);
    push(30);

    display();

    pop();

    peek();

    return 0;
}

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Pointers for front and rear
Node* front = NULL;
Node* rear = NULL;

// Check if queue is empty
bool isEmpty() {
    return front == NULL;
}

// Enqueue an element
void enqueue(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty()) {
        front = rear = newNode; // first element
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

// Dequeue an element
int dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    Node* temp = front;
    int value = temp->data;
    front = front->next;
    delete temp;

    // If queue becomes empty
    if (front == NULL) {
        rear = NULL;
    }
    return value;
}

// Display the queue
void display() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }
    Node* temp = front;
    cout << "Queue: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display(); // Queue: 10 20 30

    cout << "Dequeued: " << dequeue() << endl; // 10
    display(); // Queue: 20 30

    enqueue(40);
    enqueue(50);
    display(); // Queue: 20 30 40 50

    cout << "Dequeued: " << dequeue() << endl; // 20
    display(); // Queue: 30 40 50

    return 0;
}

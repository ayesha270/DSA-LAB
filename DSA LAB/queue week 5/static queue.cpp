#include <iostream>
using namespace std;

int queue[100];       // fixed array
int front = 0;
int rear = 0;
int queueSize;        // renamed from 'size' to 'queueSize'

// Check if empty
bool isEmpty() { return front == rear; }

// Check if full
bool isFull() { return (rear + 1) % queueSize == front; }

// Enqueue
void enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full!\n";
        return;
    }
    queue[rear] = value;
    rear = (rear + 1) % queueSize;
}

// Dequeue
int dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty!\n";
        return -1;
    }
    int value = queue[front];
    front = (front + 1) % queueSize;
    return value;
}

// Display
void display() {
    int i = front;
    cout << "Queue: ";
    while (i != rear) {
        cout << queue[i] << " ";
        i = (i + 1) % queueSize;
    }
    cout << endl;
}

int main() {
    cout << "Enter queue size (max 99): ";
    cin >> queueSize;
    if (queueSize <= 0 || queueSize >= 100) {
        cout << "Invalid size!\n";
        return 1;
    }

    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    cout << "Dequeued: " << dequeue() << endl;
    display();

    enqueue(40);
    enqueue(50);
    display();

    enqueue(60);  // Should show "Queue is full!"
    display();

    return 0;
}

#include <iostream>
#include<stdlib.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* list = NULL;

void insert(int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;

    if(list == NULL)
        list = temp;
    else {
        Node* curr = list;
        while(curr->next != NULL)
            curr = curr->next;
        curr->next = temp;
    }
}

// Recursive Forward Traversal
void traverseForward(Node* head) {
    if(head == NULL)
        return;

    cout << head->data << " ";
    traverseForward(head->next);
}

// Recursive Backward Traversal
void traverseBackward(Node* head) {
    if(head == NULL)
        return;

    traverseBackward(head->next);
    cout << head->data << " ";
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);

    cout << "Forward Traversal (Recursion): ";
    traverseForward(list);

    cout << "\nBackward Traversal (Recursion): ";
    traverseBackward(list);

    return 0;
}

#include <iostream>
#include <stdlib.h>
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

void display() {
    if(list == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* curr = list;
    while(curr != NULL) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

void search(int key) {
    Node* curr = list;
    int pos = 1;

    while(curr != NULL) {
        if(curr->data == key) {
            cout << "Element " << key << " found at position " << pos << endl;
            return;
        }
        curr = curr->next;
        pos++;
    }
    cout << "Element " << key << " not found in the list" << endl;
}

void deleteNode(int key) {
    if(list == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    // If first node is to be deleted
    if(list->data == key) {
        Node* temp = list;
        list = list->next;
        free(temp);
        cout << "Element " << key << " deleted" << endl;
        return;
    }

    Node* curr = list;
    Node* prev = NULL;

    while(curr != NULL && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if(curr == NULL) {
        cout << "Element " << key << " not found" << endl;
        return;
    }

    prev->next = curr->next;
    free(curr);
    cout << "Element " << key << " deleted" << endl;
}

int main() {
    int ch, val;

    while(true) {
        cout << "\n1. Insert";
        cout << "\n2. Display";
        cout << "\n3. Search";
        cout << "\n4. Delete";
        cout << "\n5. Exit\n";
        cin >> ch;

        if(ch == 1) {
            cout << "Enter value: ";
            cin >> val;
            insert(val);
        }
        else if(ch == 2) {
            display();
        }
        else if(ch == 3) {
            cout << "Enter value to search: ";
            cin >> val;
            search(val);
        }
        else if(ch == 4) {
            cout << "Enter value to delete: ";
            cin >> val;
            deleteNode(val);
        }
        else if(ch == 5) {
            break;
        }
        else {
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}



            
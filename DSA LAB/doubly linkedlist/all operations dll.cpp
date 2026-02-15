#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

/* INSERT AT END */
void insert(int value) {
    Node* temp = new Node();
    temp->data = value;
    temp->next = NULL;
    temp->prev = NULL;

    if (head == NULL) {
        head = temp;
        return;
    }

    Node* curr = head;
    while (curr->next != NULL)
        curr = curr->next;

    curr->next = temp;
    temp->prev = curr;
}

/* DISPLAY */
void display() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* curr = head;
    cout << "NULL <-> ";
    while (curr != NULL) {
        cout << curr->data << " <-> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

/* SEARCH */
void search(int key) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* curr = head;
    int pos = 1;

    while (curr != NULL) {
        if (curr->data == key) {
            cout << "Element " << key << " found at position " << pos << endl;
            return;
        }
        curr = curr->next;
        pos++;
    }

    cout << "Element " << key << " not found" << endl;
}

/* DELETE */
void deleteNode(int key) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* curr = head;

    // If head node is to be deleted
    if (head->data == key) {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        delete curr;
        cout << "Element deleted" << endl;
        return;
    }

    while (curr != NULL && curr->data != key)
        curr = curr->next;

    if (curr == NULL) {
        cout << "Element not found" << endl;
        return;
    }

    curr->prev->next = curr->next;
    if (curr->next != NULL)
        curr->next->prev = curr->prev;

    delete curr;
    cout << "Element deleted" << endl;
}

int main() {
    int ch, val;

    while (true) {
        cout << "\n1. Insert";
        cout << "\n2. Display";
        cout << "\n3. Search";
        cout << "\n4. Delete";
        cout << "\n5. Exit\n";
        cin >> ch;

        if (ch == 1) {
            cout << "Enter value: ";
            cin >> val;
            insert(val);
        }
        else if (ch == 2) {
            display();
        }
        else if (ch == 3) {
            cout << "Enter value to search: ";
            cin >> val;
            search(val);
        }
        else if (ch == 4) {
            cout << "Enter value to delete: ";
            cin >> val;
            deleteNode(val);
        }
        else if (ch == 5) {
            break;
        }
        else {
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}

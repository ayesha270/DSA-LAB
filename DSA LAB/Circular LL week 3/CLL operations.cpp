#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* list = NULL;

/* INSERT AT END */
void insert(int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;

    if(list == NULL) {
        list = temp;
        temp->next = list;   // circular link
    } else {
        Node* curr = list;
        while(curr->next != list)
            curr = curr->next;

        curr->next = temp;
        temp->next = list;
    }
}

/* DISPLAY */
void display() {
    if(list == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* curr = list;
    do {
        cout << curr->data << " -> ";
        curr = curr->next;
    } while(curr != list);

    cout << "(back to head)" << endl;
}

/* SEARCH */
void search(int key) {
    if(list == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* curr = list;
    int pos = 1;

    do {
        if(curr->data == key) {
            cout << "Element " << key << " found at position " << pos << endl;
            return;
        }
        curr = curr->next;
        pos++;
    } while(curr != list);

    cout << "Element " << key << " not found" << endl;
}

/* DELETE */
void deleteNode(int key) {
    if(list == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* curr = list;
    Node* prev = NULL;

    // If only one node
    if(list->data == key && list->next == list) {
        free(list);
        list = NULL;
        cout << "Element deleted" << endl;
        return;
    }

    // If head node is to be deleted
    if(list->data == key) {
        Node* last = list;
        while(last->next != list)
            last = last->next;

        Node* temp = list;
        list = list->next;
        last->next = list;
        free(temp);
        cout << "Element deleted" << endl;
        return;
    }

    // Delete non-head node
    do {
        prev = curr;
        curr = curr->next;
    } while(curr != list && curr->data != key);

    if(curr == list) {
        cout << "Element not found" << endl;
        return;
    }

    prev->next = curr->next;
    free(curr);
    cout << "Element deleted" << endl;
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

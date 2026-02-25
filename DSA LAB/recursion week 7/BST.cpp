#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* Root = NULL;

// Insert function
Node* insert(Node* curr, int value)
{
    if(curr == NULL)
    {
        Node* temp = new Node();
        temp->data = value;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }

    if(value > curr->data)
        curr->right = insert(curr->right, value);
    else
        curr->left = insert(curr->left, value);

    return curr;
}

// PreOrder traversal
void PreOrder(Node* curr)
{
    if(curr != NULL)
    {
        cout << curr->data << " ";
        PreOrder(curr->left);
        PreOrder(curr->right);
    }
}

// 🔎 Search function
bool Search(Node* curr, int key)
{
    if(curr == NULL)
        return false;   // Not found

    if(curr->data == key)
        return true;    // Found

    if(key < curr->data)
        return Search(curr->left, key);
    else
        return Search(curr->right, key);
}

int main()
{
    Root = insert(Root, 50);
    insert(Root, 30);
    insert(Root, 70);
    insert(Root, 20);
    insert(Root, 40);
    insert(Root, 60);
    insert(Root, 80);

    cout << "PreOrder Traversal: ";
    PreOrder(Root);

    int key;
    cout << "\nEnter value to search: ";
    cin >> key;

    if(Search(Root, key))
        cout << "Value found in BST";
    else
        cout << "Value not found in BST";

    return 0;
}


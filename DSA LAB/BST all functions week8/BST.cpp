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
Node* DeleteNode(Node* curr, int key)
{
    if(curr == NULL)
        return curr;

    if(key < curr->data)
        curr->left = DeleteNode(curr->left, key);

    else if(key > curr->data)
        curr->right = DeleteNode(curr->right, key);

    else
    {
        // Case 1: No child
        if(curr->left == NULL && curr->right == NULL)
        {
            delete curr;
            return NULL;
        }
        // Case 2: One child
        else if(curr->left == NULL)
        {
            Node* temp = curr->right;
            delete curr;
            return temp;
        }
        else if(curr->right == NULL)
        {
            Node* temp = curr->left;
            delete curr;
            return temp;
        }
        // Case 3: Two children
        else
        {
            Node* temp = curr->right;
            while(temp->left != NULL)
                temp = temp->left;

            curr->data = temp->data;
            curr->right = DeleteNode(curr->right, temp->data);
        }
    }
    return curr;
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
    int delKey;
    cout<<"\nEnter value to delete:";
    cin>>delKey;
     Root = DeleteNode(Root, delKey);
     cout<<"Preorder after deletion";
     PreOrder(Root);

    return 0;
}

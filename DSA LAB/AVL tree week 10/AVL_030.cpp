#include<iostream>
using namespace std;

// ================= NODE =================
struct AVLNode {
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;
};

// ================= HELPERS =================
int height(AVLNode* n) {
    return (n == NULL) ? -1 : n->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

// ================= ROTATIONS =================

// LL
AVLNode* rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// RR
AVLNode* rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// LR
AVLNode* rotateLeftRight(AVLNode* node) {
    node->left = rotateLeft(node->left);
    return rotateRight(node);
}

// RL
AVLNode* rotateRightLeft(AVLNode* node) {
    node->right = rotateRight(node->right);
    return rotateLeft(node);
}

// ================= INSERT =================
AVLNode* insertAVL(AVLNode* node, int value) {
    if (node == NULL) {
        AVLNode* temp = new AVLNode;
        temp->data = value;
        temp->left = temp->right = NULL;
        temp->height = 0;
        return temp;
    }

    if (value < node->data) {
        node->left = insertAVL(node->left, value);
        if (height(node->left) - height(node->right) == 2) {
            if (value < node->left->data)
                node = rotateRight(node);       // LL
            else
                node = rotateLeftRight(node);   // LR
        }
    }
    else if (value > node->data) {
        node->right = insertAVL(node->right, value);
        if (height(node->right) - height(node->left) == 2) {
            if (value > node->right->data)
                node = rotateLeft(node);        // RR
            else
                node = rotateRightLeft(node);   // RL
        }
    }

    node->height = max(height(node->left), height(node->right)) + 1;
    return node;
}

// ================= DELETE =================
AVLNode* minValueNode(AVLNode* node) {
    AVLNode* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

AVLNode* deleteAVL(AVLNode* root, int key) {
    if (root == NULL) return root;

    if (key < root->data)
        root->left = deleteAVL(root->left, key);
    else if (key > root->data)
        root->right = deleteAVL(root->right, key);
    else {
        // node with one or no child
        if (root->left == NULL || root->right == NULL) {
            AVLNode* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                delete root;
                return NULL;
            } else {
                *root = *temp;
                delete temp;
            }
        }
        else {
            AVLNode* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteAVL(root->right, temp->data);
        }
    }

    if (root == NULL) return root;

    // update height
    root->height = max(height(root->left), height(root->right)) + 1;

    // balance
    int balance = height(root->left) - height(root->right);

    if (balance > 1) {
        if (height(root->left->left) >= height(root->left->right))
            return rotateRight(root);       // LL
        else
            return rotateLeftRight(root);   // LR
    }
    if (balance < -1) {
        if (height(root->right->right) >= height(root->right->left))
            return rotateLeft(root);        // RR
        else
            return rotateRightLeft(root);   // RL
    }

    return root;
}

// ================= TRAVERSALS =================
void inorder(AVLNode* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(AVLNode* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// ================= MAIN =================
int main() {
    AVLNode* root = NULL;

    int values[] = {120, 110, 150, 130, 140, 146, 136,
                    134, 138, 160, 154, 156, 132, 125, 128};
    int n = 15;

    // INSERTIONS
    for (int i = 0; i < n; i++) {
        root = insertAVL(root, values[i]);
    }

    cout << "Inorder (sorted): ";
    inorder(root);

    cout << "\nPreorder (structure): ";
    preorder(root);

    // DELETION EXAMPLES
    root = deleteAVL(root, 140);
    root = deleteAVL(root, 150);

    cout << "\n\nAfter deletions (140 & 150):";

    cout << "\nInorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    cout << endl;
    return 0;
}
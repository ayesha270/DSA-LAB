#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main()
{
    Node* table[10];

    // initialize
    for(int i=0;i<10;i++)
        table[i] = NULL;

    int keys[] = {23, 33, 43, 15};

    // insert
    for(int k=0;k<4;k++)
    {
        int key = keys[k];
        int index = key % 10;

        Node* temp = (Node*)malloc(sizeof(Node));
        temp->data = key;

        // insert at beginning
        temp->next = table[index];
        table[index] = temp;
    }

    // display
    for(int i=0;i<10;i++)
    {
        cout << i << " -> ";

        Node* curr = table[i];
        while(curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }

        cout << endl;
    }

    return 0;
}

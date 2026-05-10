#include <iostream>
using namespace std;

#define MAX 100

int heapArr[MAX];
int size = 0;

// Swap function
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Heapify up (for insertion)
void heapifyUp(int index) {
    while (index > 0 && heapArr[(index - 1) / 2] < heapArr[index]) {
        swap(heapArr[(index - 1) / 2], heapArr[index]); // parent index
        index = (index - 1) / 2;
    }
}

// Heapify down (for deletion)
void heapifyDown(int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heapArr[left] > heapArr[largest])
        largest = left;

    if (right < size && heapArr[right] > heapArr[largest])
        largest = right;

    if (largest != index) {
        swap(heapArr[index], heapArr[largest]);
        heapifyDown(largest);
    }
}

// Insert into heap
void insert(int value) {
    if (size == MAX) {
        cout << "Heap is full!\n";
        return;
    }

    heapArr[size] = value;
    heapifyUp(size);
    size++;
}

// Delete root
void deleteRoot() {
    if (size == 0) {
        cout << "Heap is empty!\n";
        return;
    }

    cout << "Deleted element: " << heapArr[0] << endl;

    heapArr[0] = heapArr[size - 1];
    size--;
    heapifyDown(0);
}

// Display level by level
void display() {
    if (size == 0) {
        cout << "Heap is empty!\n";
        return;
    }

    int count = 0;
    int levelElements = 1;

    for (int i = 0; i < size; i++) {
        cout << heapArr[i] << " ";
        count++;

        if (count == levelElements) {
            cout << endl;
            count = 0;
            levelElements *= 2;
        }
    }
    cout << endl;
}

// Heap sort
void heapSort() {
    if (size == 0) {
        cout << "Heap is empty!\n";
        return;
    }

    int temp[MAX];
    int originalSize = size;

    // Copy heap
    for (int i = 0; i < size; i++)
        temp[i] = heapArr[i];

    // Perform heap sort
    for (int i = size - 1; i >= 0; i--) {
        swap(heapArr[0], heapArr[i]);
        size--;
        heapifyDown(0);
    }

    cout << "Sorted elements: ";
    for (int i = 0; i < originalSize; i++)
        cout << heapArr[i] << " ";

    cout << endl;

    // Restore heap
    for (int i = 0; i < originalSize; i++)
        heapArr[i] = temp[i];

    size = originalSize;
}

// Main menu
int main() {
    int choice, value;

    while (true) {
        cout << "\n--- HEAP MENU ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete (Root)\n";
        cout << "3. Display Level-wise\n";
        cout << "4. Heap Sort\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insert(value);
                break;

            case 2:
                deleteRoot();
                break;

            case 3:
                display();
                break;

            case 4:
                heapSort();
                break;

            case 5:
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}
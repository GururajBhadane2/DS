// Set 15 - Monthly Product Sales Units using Array and Linked List
// Store the monthly sales units of N products
// using both an array and a linked list. Implement:
// a. Insert the sales figures in both structures
// b. Display the memory representation (index and nodes)
// c. Count how many products sold more than 500 units

#include <iostream>
using namespace std;

struct Node {
    int sales;
    Node* next;
};

int arr[100];
int arrSize = 0;
Node* head = NULL;

void insertSales() {
    int s;
    cout << "Enter monthly sales units: "; cin >> s;
    arr[arrSize++] = s;
    Node* newNode = new Node();
    newNode->sales = s;
    newNode->next = NULL;
    if (!head) head = newNode;
    else {
        Node* curr = head;
        while (curr->next) curr = curr->next;
        curr->next = newNode;
    }
    cout << "Sales figure recorded in both structures!\n";
}

void displayMemory() {
    cout << "\n--- Array Representation ---\n";
    for (int i = 0; i < arrSize; i++) cout << "Index [" << i << "] -> Sales: " << arr[i] << " units\n";
    cout << "\n--- Linked List Representation ---\n";
    Node* curr = head;
    int idx = 0;
    while (curr) {
        cout << "Node " << idx++ << " (" << curr << ") -> Sales: " << curr->sales << "\n";
        curr = curr->next;
    }
}

void countAbove500() {
    int count = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 500) count++;
    }
    cout << "Products sold more than 500 units: " << count << "\n";
}

int main() {
int ch;
    do {
        cout << "\n--- Set 15: Monthly Sales Units (Array & LL) ---\n";
        cout << "1. Insert Sales Figure\n2. Display Memory Representation\n3. Count Sales > 500 Units\n4. Exit\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1: insertSales(); break;
            case 2: displayMemory(); break;
            case 3: countAbove500(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (ch != 4);
    return 0;
}

// Title: Set 20 - Customer Account Balances using Array and Linked List
// Problem Statement:
//   Store the account balances of N customers
//   using both an array and a linked list. Implement:
//   a. Insert the balances in both structures
//   b. Display the memory representation (index and nodes)
//   c. Count how many customers have a balance above ₹50,000

#include <iostream>
using namespace std;

struct Node {
    double balance;
    Node* next;
};

double arr[100];
int arrSize = 0;
Node* head = NULL;

void insertBalance() {
    double b;
    cout << "Enter customer account balance: "; cin >> b;
    arr[arrSize++] = b;
    Node* newNode = new Node();
    newNode->balance = b;
    newNode->next = NULL;
    if (!head) head = newNode;
    else {
        Node* curr = head;
        while (curr->next) curr = curr->next;
        curr->next = newNode;
    }
    cout << "Balance stored in both structures!\n";
}

void displayMemory() {
    cout << "\n--- Array Representation ---\n";
    for (int i = 0; i < arrSize; i++) cout << "Index [" << i << "] -> Balance: Rs. " << arr[i] << "\n";
    cout << "\n--- Linked List Representation ---\n";
    Node* curr = head;
    int idx = 0;
    while (curr) {
        cout << "Node " << idx++ << " (" << curr << ") -> Balance: Rs. " << curr->balance << "\n";
        curr = curr->next;
    }
}

void countAbove50k() {
    int count = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 50000.0) count++;
    }
    cout << "Customers with balance > Rs. 50,000: " << count << "\n";
}

int main() {
int ch;
    do {
        cout << "\n--- Set 20: Account Balances (Array & LL) ---\n";
        cout << "1. Insert Balance\n2. Display Memory Representation\n3. Count Balance > 50,000\n4. Exit\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1: insertBalance(); break;
            case 2: displayMemory(); break;
            case 3: countAbove50k(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (ch != 4);
    return 0;
}

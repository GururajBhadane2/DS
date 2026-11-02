/*
================================================================================
Title: Set 05 - Books Issued Count using Array and Linked List
Problem Statement:
  Store the number of books issued by N members
  using both an array and a linked list. Implement:
  a. Insert the count in both structures
  b. Display the memory representation (index and nodes)
  c. Count how many members issued more than 5 books
================================================================================
*/

#include <iostream>
using namespace std;

struct Node {
    int count;
    Node* next;
};

int arr[100];
int arrSize = 0;
Node* head = NULL;

void insertCount() {
    int c;
    cout << "Enter number of books issued: "; cin >> c;
    arr[arrSize++] = c;
    Node* newNode = new Node();
    newNode->count = c;
    newNode->next = NULL;
    if (!head) head = newNode;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
    cout << "Count stored in both Array and Linked List!\n";
}

void displayMemory() {
    cout << "\n--- Array Representation ---\n";
    for (int i = 0; i < arrSize; i++) cout << "Index [" << i << "] -> Value: " << arr[i] << "\n";
    cout << "\n--- Linked List Representation ---\n";
    Node* temp = head;
    int idx = 0;
    while (temp) {
        cout << "Node " << idx++ << " (" << temp << ") -> Count: " << temp->count << "\n";
        temp = temp->next;
    }
}

void countAboveFive() {
    int total = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 5) total++;
    }
    cout << "Members who issued more than 5 books: " << total << "\n";
}

int main() {
        cout << "=====================================================\n";
    cout << "  SET 05: Books Issued Count using Array and Linked List\n";
    cout << "=====================================================\n";
int ch;
    do {
        cout << "\n--- Set 5: Books Issued Count (Array & LL) ---\n";
        cout << "1. Insert Count\n2. Display Memory Representation\n3. Count Members > 5 Books\n4. Exit\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1: insertCount(); break;
            case 2: displayMemory(); break;
            case 3: countAboveFive(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (ch != 4);
    return 0;
}

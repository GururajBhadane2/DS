/*
================================================================================
Title: Set 04 - Library Members Sorted by Member ID using Doubly Linked List
Problem Statement:
  Maintain a list of library members sorted
  by Member ID using a doubly linked list. Write
  functions to:
  a. Insert a member so that the list remains sorted
  b. Delete a member by Member ID
  c. Traverse forward and display all members
  d. Traverse backward and display all members in reverse order
================================================================================
*/

#include <iostream>
#include <string>
using namespace std;

struct Node {
    int id;
    string name;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void insertSorted() {
    Node* newNode = new Node();
    cout << "Enter Member ID: "; cin >> newNode->id;
    cout << "Enter Name: "; cin >> newNode->name;
    newNode->prev = newNode->next = NULL;

    if (!head || newNode->id < head->id) {
        newNode->next = head;
        if (head) head->prev = newNode;
        head = newNode;
    } else {
        Node* curr = head;
        while (curr->next && curr->next->id < newNode->id) curr = curr->next;
        newNode->next = curr->next;
        if (curr->next) curr->next->prev = newNode;
        curr->next = newNode;
        newNode->prev = curr;
    }
    cout << "Member inserted in sorted order!\n";
}

void deleteMember() {
    if (!head) { cout << "List is empty!\n"; return; }
    int id;
    cout << "Enter Member ID to delete: "; cin >> id;
    Node* curr = head;
    while (curr && curr->id != id) curr = curr->next;
    if (!curr) { cout << "Member ID not found!\n"; return; }
    if (curr == head) {
        head = head->next;
        if (head) head->prev = NULL;
    } else {
        curr->prev->next = curr->next;
        if (curr->next) curr->next->prev = curr->prev;
    }
    delete curr;
    cout << "Member deleted successfully!\n";
}

void traverseForward() {
    if (!head) { cout << "List is empty!\n"; return; }
    cout << "\n--- Forward Order ---\n";
    Node* temp = head;
    while (temp) {
        cout << "ID: " << temp->id << " | Name: " << temp->name << "\n";
        temp = temp->next;
    }
}

void traverseBackward() {
    if (!head) { cout << "List is empty!\n"; return; }
    cout << "\n--- Backward Order ---\n";
    Node* temp = head;
    while (temp->next) temp = temp->next;
    while (temp) {
        cout << "ID: " << temp->id << " | Name: " << temp->name << "\n";
        temp = temp->prev;
    }
}

int main() {
        cout << "=====================================================\n";
    cout << "  SET 04: Library Members Sorted by Member ID using Doubly Linked List\n";
    cout << "=====================================================\n";
int ch;
    do {
        cout << "\n--- Set 4: Sorted Library Members (DLL) ---\n";
        cout << "1. Insert Member (Sorted)\n2. Delete Member by ID\n3. Traverse Forward\n4. Traverse Backward\n5. Exit\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1: insertSorted(); break;
            case 2: deleteMember(); break;
            case 3: traverseForward(); break;
            case 4: traverseBackward(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (ch != 5);
    return 0;
}

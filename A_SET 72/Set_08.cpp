// Title: Set 08 - Patient Check-up Status: Middle Insert & Front Delete using SLL
// Problem Statement:
//   Using the same list, write functions to:
//   a. Insert a status at the middle of the list
//   b. Delete a status by day from the front
//   c. Calculate the total number of missed check-ups
//   d. Display the complete list

#include <iostream>
using namespace std;

struct Node {
    int day;
    char status;
    Node* next;
};

Node* head = NULL;

void insertMiddle() {
    Node* newNode = new Node();
    cout << "Enter Day: "; cin >> newNode->day;
    cout << "Enter Status (C/M): "; cin >> newNode->status;
    newNode->next = NULL;
    if (!head || !head->next) {
        newNode->next = head;
        head = newNode;
        cout << "Inserted as head!\n";
        return;
    }
    Node* slow = head;
    Node* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    newNode->next = slow->next;
    slow->next = newNode;
    cout << "Inserted at middle!\n";
}

void deleteFront() {
    if (!head) { cout << "List is empty!\n"; return; }
    Node* temp = head;
    head = head->next;
    cout << "Deleted Day " << temp->day << " from front.\n";
    delete temp;
}

void countMissed() {
    int count = 0;
    Node* temp = head;
    while (temp) {
        if (temp->status == 'M' || temp->status == 'm') count++;
        temp = temp->next;
    }
    cout << "Total Missed Check-ups: " << count << "\n";
}

void display() {
    if (!head) { cout << "List is empty!\n"; return; }
    cout << "\nDay\tStatus\n";
    Node* temp = head;
    while (temp) {
        cout << temp->day << "\t" << temp->status << "\n";
        temp = temp->next;
    }
}

int main() {
int ch;
    do {
        cout << "\n--- Set 8: Check-up Status (Middle Insert / Front Delete) ---\n";
        cout << "1. Insert Status at Middle\n2. Delete Status from Front\n3. Total Missed Check-ups\n4. Display Complete List\n5. Exit\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1: insertMiddle(); break;
            case 2: deleteFront(); break;
            case 3: countMissed(); break;
            case 4: display(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (ch != 5);
    return 0;
}

/*
================================================================================
Title: Set 02 - Daily Return Status of Issued Books using Singly Linked List
Problem Statement:
  Maintain the daily return status of issued
  books (R = Returned / N = Not returned) using a singly
  linked list. Write functions to:
  a. Insert a status (R/N) at the end of the list
  b. Update the status of a given day
  c. Calculate the total number of returned books
  d. Display the complete status list
================================================================================
*/

#include <iostream>
using namespace std;

struct Node {
    int day;
    char status; // 'R' = Returned, 'N' = Not returned
    Node* next;
};

Node* head = NULL;
int dayCount = 0;

void insertStatus() {
    Node* newNode = new Node();
    dayCount++;
    newNode->day = dayCount;
    cout << "Enter Return Status for Day " << dayCount << " (R/N): ";
    cin >> newNode->status;
    newNode->next = NULL;
    if (!head) head = newNode;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
    cout << "Status added for Day " << dayCount << "!\n";
}

void updateStatus() {
    int d;
    cout << "Enter Day to update: "; cin >> d;
    Node* temp = head;
    while (temp) {
        if (temp->day == d) {
            cout << "Enter new status (R/N): "; cin >> temp->status;
            cout << "Day " << d << " status updated!\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Day " << d << " not found!\n";
}

void calculateReturned() {
    int count = 0;
    Node* temp = head;
    while (temp) {
        if (temp->status == 'R' || temp->status == 'r') count++;
        temp = temp->next;
    }
    cout << "Total Returned Books: " << count << "\n";
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
        cout << "=====================================================\n";
    cout << "  SET 02: Daily Return Status of Issued Books using Singly Linked List\n";
    cout << "=====================================================\n";
int ch;
    do {
        cout << "\n--- Set 2: Daily Book Return Status (SLL) ---\n";
        cout << "1. Insert Status at End\n2. Update Status of Day\n3. Calculate Total Returned\n4. Display Complete List\n5. Exit\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1: insertStatus(); break;
            case 2: updateStatus(); break;
            case 3: calculateReturned(); break;
            case 4: display(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (ch != 5);
    return 0;
}

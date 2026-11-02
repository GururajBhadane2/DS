/*
================================================================================
Title: Set 07 - Patient Daily Check-up Status using Singly Linked List
Problem Statement:
  Maintain the daily check-up status of a patient
  (C = Completed / M = Missed) using a singly
  linked list. Write functions to:
  a. Insert a status at the end of the list
  b. Update the status of a given day
  c. Calculate the total number of completed check-ups
  d. Display the complete status list
================================================================================
*/

#include <iostream>
using namespace std;

struct Node {
    int day;
    char status; // 'C' = Completed, 'M' = Missed
    Node* next;
};

Node* head = NULL;
int dayCount = 0;

void insertStatus() {
    Node* newNode = new Node();
    dayCount++;
    newNode->day = dayCount;
    cout << "Enter Check-up Status for Day " << dayCount << " (C/M): ";
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
            cout << "Enter new status (C/M): "; cin >> temp->status;
            cout << "Day " << d << " updated!\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Day " << d << " not found!\n";
}

void countCompleted() {
    int count = 0;
    Node* temp = head;
    while (temp) {
        if (temp->status == 'C' || temp->status == 'c') count++;
        temp = temp->next;
    }
    cout << "Total Completed Check-ups: " << count << "\n";
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
    cout << "  SET 07: Patient Daily Check-up Status using Singly Linked List\n";
    cout << "=====================================================\n";
int ch;
    do {
        cout << "\n--- Set 7: Patient Check-up Status (SLL) ---\n";
        cout << "1. Insert Status at End\n2. Update Status of Day\n3. Total Completed Check-ups\n4. Display Complete List\n5. Exit\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1: insertStatus(); break;
            case 2: updateStatus(); break;
            case 3: countCompleted(); break;
            case 4: display(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (ch != 5);
    return 0;
}

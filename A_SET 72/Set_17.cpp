// Title: Set 17 - Daily Loan EMI Payment Status using Singly Linked List
// Problem Statement:
//   Maintain the daily EMI payment status of
//   a loan (P = Paid / D = Due) using a singly linked list.
//   Write functions to:
//   a. Insert a status at the end of the list
//   b. Update the status of a given day
//   c. Calculate the total number of paid EMIs
//   d. Display the complete status list

#include <iostream>
using namespace std;

struct Node {
    int day;
    char status; // 'P' = Paid, 'D' = Due
    Node* next;
};

Node* head = NULL;
int dayCount = 0;

void insertStatus() {
    Node* newNode = new Node();
    dayCount++;
    newNode->day = dayCount;
    cout << "Enter EMI Status for Day " << dayCount << " (P for Paid, D for Due): ";
    cin >> newNode->status;
    newNode->next = NULL;
    if (!head) head = newNode;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
    cout << "EMI Status added for Day " << dayCount << "!\n";
}

void updateStatus() {
    int d;
    cout << "Enter Day to update: "; cin >> d;
    Node* temp = head;
    while (temp) {
        if (temp->day == d) {
            cout << "Enter new status (P/D): "; cin >> temp->status;
            cout << "Day " << d << " updated successfully!\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Day " << d << " not found!\n";
}

void countPaid() {
    int count = 0;
    Node* temp = head;
    while (temp) {
        if (temp->status == 'P' || temp->status == 'p') count++;
        temp = temp->next;
    }
    cout << "Total Paid EMIs: " << count << "\n";
}

void display() {
    if (!head) { cout << "List is empty!\n"; return; }
    cout << "\nDay\tEMI Status\n";
    Node* temp = head;
    while (temp) {
        cout << temp->day << "\t" << temp->status << "\n";
        temp = temp->next;
    }
}

int main() {
int ch;
    do {
        cout << "\n--- Set 17: Daily EMI Status (SLL) ---\n";
        cout << "1. Insert Status at End\n2. Update Status of Day\n3. Calculate Total Paid EMIs\n4. Display Complete List\n5. Exit\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1: insertStatus(); break;
            case 2: updateStatus(); break;
            case 3: countPaid(); break;
            case 4: display(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (ch != 5);
    return 0;
}

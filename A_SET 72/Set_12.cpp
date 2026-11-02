// Title: Set 12 - Daily Product Stock Status using Singly Linked List
// Problem Statement:
//   Maintain the daily stock status of a product
//   (A = Available / O = Out of stock) using a singly
//   linked list. Write functions to:
//   a. Insert a status at the end of the list
//   b. Update the status of a given day
//   c. Calculate the total number of days the product was available
//   d. Display the complete status list

#include <iostream>
using namespace std;

struct Node {
    int day;
    char status; // 'A' = Available, 'O' = Out of stock
    Node* next;
};

Node* head = NULL;
int dayCount = 0;

void insertStatus() {
    Node* newNode = new Node();
    dayCount++;
    newNode->day = dayCount;
    cout << "Enter Status for Day " << dayCount << " (A for Available, O for Out of stock): ";
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
            cout << "Enter new status (A/O): "; cin >> temp->status;
            cout << "Day " << d << " updated successfully!\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Day " << d << " not found!\n";
}

void calculateAvailable() {
    int count = 0;
    Node* temp = head;
    while (temp) {
        if (temp->status == 'A' || temp->status == 'a') count++;
        temp = temp->next;
    }
    cout << "Total Days Product was Available: " << count << "\n";
}

void display() {
    if (!head) { cout << "List is empty!\n"; return; }
    cout << "\nDay\tStock Status\n";
    Node* temp = head;
    while (temp) {
        cout << temp->day << "\t" << temp->status << "\n";
        temp = temp->next;
    }
}

int main() {
int ch;
    do {
        cout << "\n--- Set 12: Daily Stock Status (SLL) ---\n";
        cout << "1. Insert Status at End\n2. Update Status of Day\n3. Calculate Total Available Days\n4. Display Complete List\n5. Exit\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1: insertStatus(); break;
            case 2: updateStatus(); break;
            case 3: calculateAvailable(); break;
            case 4: display(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (ch != 5);
    return 0;
}

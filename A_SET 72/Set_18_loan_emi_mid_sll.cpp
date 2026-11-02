// Title: Set 18 - Loan EMI Status: Middle Insert & Front Delete using SLL
// Problem Statement:
//   Using the same list, write functions to:
//   a. Insert a status at the middle of the list
//   b. Delete a status by day from the front
//   c. Calculate the total number of due EMIs
//   d. Display the complete list

#include <iostream>
using namespace std;

struct Node {
    int day;
    char status; // 'P' or 'D'
    Node* next;
};

Node* head = NULL;

void insertMiddle() {
    Node* newNode = new Node();
    cout << "Enter Day: "; cin >> newNode->day;
    cout << "Enter Status (P/D): "; cin >> newNode->status;
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

void countDue() {
    int count = 0;
    Node* temp = head;
    while (temp) {
        if (temp->status == 'D' || temp->status == 'd') count++;
        temp = temp->next;
    }
    cout << "Total Due EMIs: " << count << "\n";
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
        cout << "\n--- Set 18: EMI Status (Middle Insert / Front Delete) ---\n";
        cout << "1. Insert Status at Middle\n2. Delete Status from Front\n3. Calculate Total Due EMIs\n4. Display Complete List\n5. Exit\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1: insertMiddle(); break;
            case 2: deleteFront(); break;
            case 3: countDue(); break;
            case 4: display(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (ch != 5);
    return 0;
}

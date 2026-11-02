// Set 03 - Book Return Status: Middle Insert & Front Delete using SLL
// Maintain the same daily return status list.
// Write functions to:
// a. Insert a status at the middle of the list
// b. Delete a status by day from the front
// c. Calculate the total number of books not returned
// d. Display the complete list

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
    cout << "Enter Status (R/N): "; cin >> newNode->status;
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

void countNotReturned() {
    int count = 0;
    Node* temp = head;
    while (temp) {
        if (temp->status == 'N' || temp->status == 'n') count++;
        temp = temp->next;
    }
    cout << "Total Books Not Returned: " << count << "\n";
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
        cout << "\n--- Set 3: Book Return Status (Middle Insert / Front Delete) ---\n";
        cout << "1. Insert Status at Middle\n2. Delete Status from Front\n3. Calculate Total Not Returned\n4. Display Complete List\n5. Exit\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1: insertMiddle(); break;
            case 2: deleteFront(); break;
            case 3: countNotReturned(); break;
            case 4: display(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (ch != 5);
    return 0;
}

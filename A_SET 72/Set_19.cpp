// Set 19 - Loan Applicants Sorted by Application No using Doubly Linked List
// Maintain a list of loan applicants sorted
// by Application No using a doubly linked list. Write
// functions to:
// a. Insert an applicant so that the list remains sorted
// b. Delete an applicant by Application No
// c. Traverse forward and display all applicants
// d. Traverse backward and display all applicants in reverse order

#include <iostream>
#include <string>
using namespace std;

struct Node {
    int appNo;
    string name;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void insertSorted() {
    Node* newNode = new Node();
    cout << "Enter Application No: "; cin >> newNode->appNo;
    cout << "Enter Applicant Name: "; cin >> newNode->name;
    newNode->prev = newNode->next = NULL;

    if (!head || newNode->appNo < head->appNo) {
        newNode->next = head;
        if (head) head->prev = newNode;
        head = newNode;
    } else {
        Node* curr = head;
        while (curr->next && curr->next->appNo < newNode->appNo) curr = curr->next;
        newNode->next = curr->next;
        if (curr->next) curr->next->prev = newNode;
        curr->next = newNode;
        newNode->prev = curr;
    }
    cout << "Applicant inserted in sorted order!\n";
}

void deleteApplicant() {
    if (!head) { cout << "List is empty!\n"; return; }
    int appNo;
    cout << "Enter Application No to delete: "; cin >> appNo;
    Node* curr = head;
    while (curr && curr->appNo != appNo) curr = curr->next;
    if (!curr) { cout << "Application No not found!\n"; return; }
    if (curr == head) {
        head = head->next;
        if (head) head->prev = NULL;
    } else {
        curr->prev->next = curr->next;
        if (curr->next) curr->next->prev = curr->prev;
    }
    delete curr;
    cout << "Applicant record deleted successfully!\n";
}

void traverseForward() {
    if (!head) { cout << "List is empty!\n"; return; }
    cout << "\n--- Forward Order ---\n";
    Node* temp = head;
    while (temp) {
        cout << "App No: " << temp->appNo << " | Name: " << temp->name << "\n";
        temp = temp->next;
    }
}

void traverseBackward() {
    if (!head) { cout << "List is empty!\n"; return; }
    cout << "\n--- Backward Order ---\n";
    Node* temp = head;
    while (temp->next) temp = temp->next;
    while (temp) {
        cout << "App No: " << temp->appNo << " | Name: " << temp->name << "\n";
        temp = temp->prev;
    }
}

int main() {
int ch;
    do {
        cout << "\n--- Set 19: Sorted Loan Applicants (DLL) ---\n";
        cout << "1. Insert Applicant (Sorted)\n2. Delete Applicant by App No\n3. Traverse Forward\n4. Traverse Backward\n5. Exit\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1: insertSorted(); break;
            case 2: deleteApplicant(); break;
            case 3: traverseForward(); break;
            case 4: traverseBackward(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (ch != 5);
    return 0;
}

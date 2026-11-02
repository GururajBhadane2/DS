#include <iostream>
#include <string>
using namespace std;

// Doubly Linked List Node
struct Node {
    int roll;
    string name;
    Node* prev;
    Node* next;
};

Node* head = NULL;

// Insert student in ascending order of roll number
void insertSorted() {
    Node* newNode = new Node();
    cout << "Enter Roll No: ";
    cin >> newNode->roll;
    cout << "Enter Name: ";
    cin >> newNode->name;
    newNode->prev = NULL;
    newNode->next = NULL;

    // Case 1: List is empty or new node is smaller than head
    if (head == NULL || newNode->roll < head->roll) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
    } else {
        // Case 2: Find the position to insert
        Node* curr = head;
        while (curr->next != NULL && curr->next->roll < newNode->roll) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        if (curr->next != NULL) {
            curr->next->prev = newNode;
        }
        curr->next = newNode;
        newNode->prev = curr;
    }
    cout << "Student inserted in sorted order!\n";
}

// Delete a student by roll number
void deleteStudent() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }
    int roll;
    cout << "Enter Roll No to delete: ";
    cin >> roll;

    Node* curr = head;
    while (curr != NULL && curr->roll != roll) {
        curr = curr->next;
    }

    if (curr == NULL) {
        cout << "Roll No not found!\n";
        return;
    }

    // If node to delete is head
    if (curr == head) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
    } else {
        curr->prev->next = curr->next;
        if (curr->next != NULL) {
            curr->next->prev = curr->prev;
        }
    }
    delete curr;
    cout << "Student deleted successfully!\n";
}

// Display forward
void displayForward() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }
    cout << "\n--- Forward Order ---\n";
    Node* temp = head;
    while (temp != NULL) {
        cout << "Roll: " << temp->roll << " | Name: " << temp->name << "\n";
        temp = temp->next;
    }
}

// Display backward
void displayBackward() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }
    cout << "\n--- Reverse Order ---\n";
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (temp != NULL) {
        cout << "Roll: " << temp->roll << " | Name: " << temp->name << "\n";
        temp = temp->prev;
    }
}

int main() {
    int choice;
    do {
        cout << "\n--- Sorted Student List (DLL) ---\n";
        cout << "1. Insert Student (Sorted)\n";
        cout << "2. Delete Student\n";
        cout << "3. Display Forward\n";
        cout << "4. Display Backward\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: insertSorted(); break;
            case 2: deleteStudent(); break;
            case 3: displayForward(); break;
            case 4: displayBackward(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}

#include <iostream>
using namespace std;

// Node structure for Attendance
struct Node {
    int roll;
    char status; // 'P' for Present, 'A' for Absent
    Node* next;
};

Node* head = NULL;

// Add attendance entry at the end
void markAttendance() {
    Node* newNode = new Node();
    cout << "Enter Roll No: ";
    cin >> newNode->roll;
    cout << "Enter Status (P for Present, A for Absent): ";
    cin >> newNode->status;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Attendance recorded!\n";
}

// Display attendance of all students
void display() {
    if (head == NULL) {
        cout << "No attendance records found!\n";
        return;
    }
    cout << "\n--- Attendance List ---\n";
    cout << "Roll No\tStatus\n";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->roll << "\t" << temp->status << "\n";
        temp = temp->next;
    }
}

// Calculate attendance summary
void showSummary() {
    if (head == NULL) {
        cout << "No records available!\n";
        return;
    }
    int total = 0, present = 0;
    Node* temp = head;
    while (temp != NULL) {
        total++;
        if (temp->status == 'P' || temp->status == 'p') {
            present++;
        }
        temp = temp->next;
    }
    cout << "\n--- Summary ---\n";
    cout << "Total Students: " << total << "\n";
    cout << "Present: " << present << "\n";
    cout << "Absent: " << (total - present) << "\n";
    cout << "Percentage: " << (present * 100.0 / total) << "%\n";
}

int main() {
    int choice;
    do {
        cout << "\n--- Student Attendance (SLL) ---\n";
        cout << "1. Mark Attendance\n";
        cout << "2. Display Attendance\n";
        cout << "3. Attendance Summary\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: markAttendance(); break;
            case 2: display(); break;
            case 3: showSummary(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}

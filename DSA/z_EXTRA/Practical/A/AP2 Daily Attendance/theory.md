EXPERIMENT NO. 2
AIM:
To write a C++ program to maintain the daily attendance of students using a singly linked list and implement functions to perform the following operations:
 * Insert attendance (P/A) at the end of the list.
 * Update the attendance of a given day.
 * Calculate the total number of Present and Absent days.
 * Display the complete attendance list.
PAGE 1: THEORY & CONTEXT
1. Introduction
Managing student attendance is a core task in educational institutions. Attendance records must be logged continuously day by day, periodically updated for corrections, and summarized at the end of a session or term.
 * Limitations of Fixed Arrays for Dynamic Data:
   * Using a standard static array requires defining a fixed size in advance.
   * If the number of instructional days in a term is unknown or varies, an array can lead to memory waste (if oversized) or stack overflow (if undersized).
   * Inserting or growing records continuously incurs unnecessary allocation overhead.
 * Why Linked Lists? A Singly Linked List provides dynamic memory allocation, expanding automatically with each new day's attendance entry without needing a predetermined maximum capacity.
 * Scope of this Practical: This system dynamically maintains an attendance log for a student where each node stores:
   * Day Number (Auto-incremented integer index)
   * Attendance Status ('P' for Present, 'A' for Absent)
   * Pointer to Next Node (Linking memory addresses dynamically)
2. Core Concepts
A. Singly Linked List Data Structure
A Singly Linked List is a linear data structure where elements are not stored at contiguous memory locations. Instead, each element is a separate object called a Node.
 * Node Structure: Each node consists of two main parts:
   * Data Member(s): Stores the actual values (day and status).
   * Pointer Member (next): Stores the memory address of the next node in the sequence.
 * Head Pointer: A reference pointer named head points to the first node of the list. If head == nullptr, the list is currently empty.
 * Dynamic Memory Allocation: Nodes are dynamically allocated on the heap memory at runtime using the new operator.
B. Memory Representation
      +-------------+      +-------------+      +-------------+
HEAD  | Day: 1      |      | Day: 2      |      | Day: 3      |
 ---> | Status: 'P' | ---> | Status: 'A' | ---> | Status: 'P' | ---> NULL
      | Next: 0x108 |      | Next: 0x200 |      | Next: NULL  |
      +-------------+      +-------------+      +-------------+
      (Address:0x100)      (Address:0x108)      (Address:0x200)

PAGE 2: DETAILED OPERATIONS & ALGORITHMS
3. Operations Performed on the Linked List
Operation 1: Insertion at the End (Appending Entry)
Inserts a new attendance log ('P' or 'A') for the next sequential day.
 * Algorithm Steps:
   * Validate input status (normalize 'p'/'a' to uppercase 'P'/'A').
   * Increment the internal dayCounter.
   * Dynamically create a new Node using new Node(dayCounter, status).
   * If head == nullptr, set head = newNode.
   * Otherwise, traverse the list using a temporary pointer temp until temp->next == nullptr.
   * Attach the new node: temp->next = newNode.
Operation 2: Updating Attendance for a Specific Day
Searches for a specific day's record in the linked list and modifies its attendance status.
 * Algorithm Steps:
   * Start traversal from head using temp.
   * Compare temp->getDay() with targetDay.
   * If matched, update status via temp->setStatus(newStatus) and terminate search.
   * If temp becomes nullptr without finding targetDay, display "Day not found".
Operation 3: Calculating Total Present and Absent Days
Traverses the complete linked list to aggregate attendance statistics.
 * Algorithm Steps:
   * Initialize counters: presentCount = 0, absentCount = 0.
   * Set temp = head.
   * While temp != nullptr:
     * If temp->getStatus() == 'P', increment presentCount.
     * If temp->getStatus() == 'A', increment absentCount.
     * Advance pointer: temp = temp->getNext().
   * Print the aggregated totals.
Operation 4: Displaying the Attendance Record
Iterates through all nodes from head to the tail and prints each entry in tabular format.
 * Algorithm Steps:
   * Check if head == nullptr; if so, display "No records found".
   * Print table headers (Day and Status).
   * Traverse with temp, printing temp->getDay() and converting status characters to full text ("Present" or "Absent").

PAGE 3: COMPARISON & ADVANTAGES

4. Comparison: Array vs. Singly Linked List

| Feature | Array-Based System (Exp 1) | Linked List System (Exp 2) |
|---|---|---|
| Memory Allocation | Static / Contiguous allocation | Dynamic / Non-contiguous allocation |
| Fixed Capacity | Yes (limited by initial size) | No (grows/shrinks dynamically) |
| Insertion at End | O(1) | O(N) (without tail pointer) / O(1) (with tail pointer) |
| Memory Overhead | Lower (stores data only) | Higher (stores data + pointer per node) |
| Traversals | Direct index access O(1) | Sequential traversal O(N) |


5. Summary Table of Operations

| Operation | Time Complexity | Space Complexity | Primary Task |
|---|---|---|---|
| Insert at End | O(N) | O(1) | Traverse to tail node and link new dynamic node |
| Update Day | O(N) | O(1) | Search node by day field and modify status |
| Calculate Totals | O(N) | O(1) | Traverse entire list and aggregate present/absent counts |
| Display List | O(N) | O(1) | Traverse from head to nullptr and output data |
| Destructor Cleanup | O(N) | O(1) | Deallocate memory for all nodes to prevent memory leaks |


PAGE 4: C++ PROGRAM SOURCE CODE

```bash

#include <iostream>
using namespace std;

// Node Class
class Node {
public:
    int day;
    char status;
    Node* next;

    Node(int d, char s) {
        day = d;
        status = s;
        next = nullptr;
    }

    int getDay() const { return day; }
    char getStatus() const { return status; }
    void setStatus(char s) { status = s; }
    Node* getNext() const { return next; }
    void setNext(Node* n) { next = n; }
};

// Linked List Class
class AttendanceList {
private:
    Node* head;
    int dayCounter;

public:
    AttendanceList() {
        head = nullptr;
        dayCounter = 0;
    }

    // Function a: Insert attendance (P/A) at end
    void insertAttendance(char status) {
        if (status == 'p') status = 'P';
        else if (status == 'a') status = 'A';

        if (status != 'P' && status != 'A') {
            cout << "Invalid status! Please enter 'P' or 'A'.\n";
            return;
        }

        dayCounter++;
        Node* newNode = new Node(dayCounter, status);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->getNext() != nullptr) {
                temp = temp->getNext();
            }
            temp->setNext(newNode);
        }

        cout << "Attendance recorded for Day " << dayCounter << ": " << status << "\n";
    }

    // Function b: Update attendance for a given day
    void updateAttendance(int targetDay, char newStatus) {
        if (newStatus == 'p') newStatus = 'P';
        else if (newStatus == 'a') newStatus = 'A';

        if (newStatus != 'P' && newStatus != 'A') {
            cout << "Invalid status! Please enter 'P' or 'A'.\n";
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            if (temp->getDay() == targetDay) {
                temp->setStatus(newStatus);
                cout << "Attendance for Day " << targetDay << " successfully updated to " << newStatus << ".\n";
                return;
            }
            temp = temp->getNext();
        }

        cout << "Day " << targetDay << " not found.\n";
    }

    // Function c: Calculate total Present and Absent days
    void calculateTotals() {
        int presentCount = 0;
        int absentCount = 0;
        Node* temp = head;

        while (temp != nullptr) {
            if (temp->getStatus() == 'P') {
                presentCount++;
            } else if (temp->getStatus() == 'A') {
                absentCount++;
            }
            temp = temp->getNext();
        }

        cout << "\n--- Attendance Summary ---\n";
        cout << "Total Present Days: " << presentCount << "\n";
        cout << "Total Absent Days : " << absentCount << "\n";
        cout << "---------------------------\n";
    }

    // Function d: Display complete attendance list
    void displayAttendance() {
        if (head == nullptr) {
            cout << "No attendance records found.\n";
            return;
        }

        cout << "\n--- Complete Attendance Record ---\n";
        cout << "Day\t\tStatus\n";

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->getDay() << "\t\t" 
                 << (temp->getStatus() == 'P' ? "Present (P)" : "Absent (A)") 
                 << "\n";
            temp = temp->getNext();
        }
    }

    // Destructor to deallocate heap memory
    ~AttendanceList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->getNext();
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    AttendanceList studentRecord;
    int choice, day;
    char status;

    do {
        cout << "\n=== Student Attendance Management System ===\n";
        cout << "1. Insert Attendance (P/A)\n";
        cout << "2. Update Attendance for a Day\n";
        cout << "3. Calculate Total Present/Absent Days\n";
        cout << "4. Display Complete Attendance List\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter attendance (P Present, A Absent): ";
            cin >> status;
            studentRecord.insertAttendance(status);
            break;
        case 2:
            cout << "Enter day number to update: ";
            cin >> day;
            cout << "Enter new status (P/A): ";
            cin >> status;
            studentRecord.updateAttendance(day, status);
            break;
        case 3:
            studentRecord.calculateTotals();
            break;
        case 4:
            studentRecord.displayAttendance();
            break;
        case 5:
            cout << "Program Exited Successfully.\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}

```

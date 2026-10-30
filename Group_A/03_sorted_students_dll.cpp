#include <iostream>
#include <string>
#include <iomanip>

struct StudentNode {
    int rollNo;
    std::string name;
    double cgpa;
    StudentNode* prev;
    StudentNode* next;

    StudentNode(int r, std::string n, double c) 
        : rollNo(r), name(n), cgpa(c), prev(nullptr), next(nullptr) {}
};

class SortedStudentDLL {
private:
    StudentNode* head;
    StudentNode* tail;

public:
    SortedStudentDLL() : head(nullptr), tail(nullptr) {}

    ~SortedStudentDLL() {
        StudentNode* curr = head;
        while (curr) {
            StudentNode* temp = curr->next;
            delete curr;
            curr = temp;
        }
    }

    // a. Insert a student so that the list remains sorted by roll number
    void insertSorted(int rollNo, const std::string& name, double cgpa) {
        StudentNode* newNode = new StudentNode(rollNo, name, cgpa);

        // Case 1: Empty list
        if (!head) {
            head = tail = newNode;
            std::cout << "Inserted Roll No " << rollNo << " as first student.\n";
            return;
        }

        // Case 2: Insert before head
        if (rollNo < head->rollNo) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            std::cout << "Inserted Roll No " << rollNo << " at beginning.\n";
            return;
        }

        // Case 3: Insert after tail
        if (rollNo > tail->rollNo) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            std::cout << "Inserted Roll No " << rollNo << " at end.\n";
            return;
        }

        // Case 4: Insert in between
        StudentNode* curr = head;
        while (curr && curr->rollNo < rollNo) {
            curr = curr->next;
        }

        if (curr && curr->rollNo == rollNo) {
            std::cout << "Student with Roll No " << rollNo << " already exists! Insertion skipped.\n";
            delete newNode;
            return;
        }

        // Insert before curr
        newNode->next = curr;
        newNode->prev = curr->prev;
        curr->prev->next = newNode;
        curr->prev = newNode;

        std::cout << "Inserted Roll No " << rollNo << " in sorted order.\n";
    }

    // b. Delete a student by roll number
    void deleteByRollNo(int rollNo) {
        if (!head) {
            std::cout << "List is empty.\n";
            return;
        }

        StudentNode* curr = head;
        while (curr && curr->rollNo != rollNo) {
            curr = curr->next;
        }

        if (!curr) {
            std::cout << "Student with Roll No " << rollNo << " not found!\n";
            return;
        }

        if (curr == head && curr == tail) {
            head = tail = nullptr;
        } else if (curr == head) {
            head = head->next;
            head->prev = nullptr;
        } else if (curr == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }

        std::cout << "Deleted student [" << curr->name << ", Roll: " << rollNo << "].\n";
        delete curr;
    }

    // c. Traverse the list forward
    void traverseForward() const {
        if (!head) {
            std::cout << "Student list is empty.\n";
            return;
        }

        std::cout << "\n--- Forward Traversal (Ascending Roll Numbers) ---\n";
        std::cout << std::left << std::setw(12) << "Roll No" 
                  << std::setw(25) << "Student Name" 
                  << std::setw(10) << "CGPA" << "\n";
        std::cout << "--------------------------------------------------\n";
        StudentNode* curr = head;
        while (curr) {
            std::cout << std::left << std::setw(12) << curr->rollNo
                      << std::setw(25) << curr->name
                      << std::fixed << std::setprecision(2) << std::setw(10) << curr->cgpa << "\n";
            curr = curr->next;
        }
        std::cout << "--------------------------------------------------\n";
    }

    // d. Traverse the list backward
    void traverseBackward() const {
        if (!tail) {
            std::cout << "Student list is empty.\n";
            return;
        }

        std::cout << "\n--- Backward Traversal (Descending Roll Numbers) ---\n";
        std::cout << std::left << std::setw(12) << "Roll No" 
                  << std::setw(25) << "Student Name" 
                  << std::setw(10) << "CGPA" << "\n";
        std::cout << "--------------------------------------------------\n";
        StudentNode* curr = tail;
        while (curr) {
            std::cout << std::left << std::setw(12) << curr->rollNo
                      << std::setw(25) << curr->name
                      << std::fixed << std::setprecision(2) << std::setw(10) << curr->cgpa << "\n";
            curr = curr->prev;
        }
        std::cout << "--------------------------------------------------\n";
    }
};

int main() {
    SortedStudentDLL dll;

    std::cout << "=== Sorted Student List using Doubly Linked List ===\n";
    // a. Insert in random order to test sorted insertion
    dll.insertSorted(105, "Esha Rao", 9.4);
    dll.insertSorted(101, "Aarav Sharma", 8.8);
    dll.insertSorted(108, "Harsh Vardhan", 7.9);
    dll.insertSorted(103, "Chirag Verma", 8.5);
    dll.insertSorted(106, "Farhan Khan", 8.2);

    // c. Forward display
    dll.traverseForward();

    // d. Backward display
    dll.traverseBackward();

    // b. Delete by roll number
    dll.deleteByRollNo(103);
    dll.deleteByRollNo(101);

    // Forward display after deletion
    dll.traverseForward();

    return 0;
}

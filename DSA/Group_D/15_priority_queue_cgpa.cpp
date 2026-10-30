#include <iostream>
#include <string>
#include <iomanip>

/*
 * Priority Queue where Priority = Higher CGPA:
 * a. Insert student with CGPA
 * b. Delete the highest CGPA student (served first for campus interview / scholarship)
 * c. Display queue after each operation
 * d. Count students processed
 */

struct StudentPQNode {
    int rollNo;
    std::string name;
    double cgpa;
    StudentPQNode* next;

    StudentPQNode(int r, std::string n, double c) 
        : rollNo(r), name(n), cgpa(c), next(nullptr) {}
};

class CGPAPriorityQueue {
private:
    StudentPQNode* head;
    int processedCount;

public:
    CGPAPriorityQueue() : head(nullptr), processedCount(0) {}

    ~CGPAPriorityQueue() {
        while (!isEmpty()) {
            StudentPQNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    // a. Insert student with CGPA (Priority = higher CGPA)
    void insertStudent(int rollNo, const std::string& name, double cgpa) {
        StudentPQNode* newNode = new StudentPQNode(rollNo, name, cgpa);

        // If queue is empty or new student has higher CGPA than head
        if (!head || cgpa > head->cgpa) {
            newNode->next = head;
            head = newNode;
        } else {
            StudentPQNode* curr = head;
            while (curr->next && curr->next->cgpa >= cgpa) {
                curr = curr->next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
        }
        std::cout << "Inserted: [Roll: " << rollNo << ", Name: " << name 
                  << ", CGPA: " << std::fixed << std::setprecision(2) << cgpa << "]\n";
        displayQueue();
    }

    // b. Delete the highest CGPA student
    void serveHighestCGPA() {
        if (isEmpty()) {
            std::cout << "Queue Underflow! No students in priority queue.\n";
            return;
        }

        StudentPQNode* highest = head;
        head = head->next;
        processedCount++;

        std::cout << "\n>>> SERVED HIGHEST CGPA STUDENT: [" << highest->name 
                  << ", Roll: " << highest->rollNo 
                  << ", CGPA: " << std::fixed << std::setprecision(2) << highest->cgpa << "] <<<\n";
        delete highest;

        // c. Display queue after operation
        displayQueue();
    }

    // c. Display queue
    void displayQueue() const {
        if (isEmpty()) {
            std::cout << "Priority Queue is currently empty.\n\n";
            return;
        }
        std::cout << "Current Merit Priority Queue (Ordered by CGPA):\n";
        StudentPQNode* curr = head;
        int rank = 1;
        while (curr) {
            std::cout << "  Rank " << rank++ << ": "
                      << std::left << std::setw(20) << curr->name
                      << " (Roll: " << std::setw(6) << curr->rollNo
                      << " | CGPA: " << std::fixed << std::setprecision(2) << curr->cgpa << ")\n";
            curr = curr->next;
        }
        std::cout << "\n";
    }

    // d. Count students processed
    int getProcessedCount() const {
        return processedCount;
    }
};

int main() {
    CGPAPriorityQueue pq;

    std::cout << "=== CGPA-based Priority Queue System ===\n\n";

    // a. Insert students
    pq.insertStudent(101, "Aarav Sharma", 8.40);
    pq.insertStudent(102, "Bhavna Patel", 9.65);
    pq.insertStudent(103, "Chirag Verma", 7.90);
    pq.insertStudent(104, "Devansh Joshi", 9.15);

    // b. Delete/Serve highest CGPA
    pq.serveHighestCGPA();
    pq.serveHighestCGPA();

    // Insert more
    pq.insertStudent(105, "Esha Rao", 9.80);

    // Serve next
    pq.serveHighestCGPA();

    // d. Display processed count
    std::cout << "=========================================\n";
    std::cout << "Total Students Processed: " << pq.getProcessedCount() << "\n";
    std::cout << "=========================================\n";

    return 0;
}

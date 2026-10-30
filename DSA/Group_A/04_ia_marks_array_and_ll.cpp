#include <iostream>
#include <iomanip>
#include <cstdint>

// Node for linked list representation
struct MarkNode {
    int studentId;
    double marks;
    MarkNode* next;

    MarkNode(int id, double m) : studentId(id), marks(m), next(nullptr) {}
};

class IAMarksManager {
private:
    // 1. Array representation
    int arrIds[100];
    double arrMarks[100];
    int count;

    // 2. Linked list representation
    MarkNode* head;

public:
    IAMarksManager() : count(0), head(nullptr) {}

    ~IAMarksManager() {
        MarkNode* curr = head;
        while (curr) {
            MarkNode* temp = curr->next;
            delete curr;
            curr = temp;
        }
    }

    // a. Insert student marks in both structures
    void insert(int studentId, double marks) {
        // Insert into Array
        arrIds[count] = studentId;
        arrMarks[count] = marks;
        count++;

        // Insert into Linked List (at end)
        MarkNode* newNode = new MarkNode(studentId, marks);
        if (!head) {
            head = newNode;
        } else {
            MarkNode* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        std::cout << "Added Student ID " << studentId << " with IA Marks " << marks << ".\n";
    }

    // b. Display memory representation and index nodes
    void displayMemoryRepresentation() const {
        std::cout << "\n============================================================\n";
        std::cout << " 1. ARRAY MEMORY REPRESENTATION (Contiguous Storage)\n";
        std::cout << "============================================================\n";
        std::cout << std::left << std::setw(8) << "Index" 
                  << std::setw(14) << "Student ID" 
                  << std::setw(12) << "Marks" 
                  << std::setw(20) << "Physical Address" << "\n";
        std::cout << "------------------------------------------------------------\n";
        for (int i = 0; i < count; ++i) {
            std::cout << std::left << std::setw(8) << i
                      << std::setw(14) << arrIds[i]
                      << std::setw(12) << arrMarks[i]
                      << "0x" << std::hex << reinterpret_cast<uintptr_t>(&arrMarks[i]) << std::dec << "\n";
        }

        std::cout << "\n============================================================\n";
        std::cout << " 2. LINKED LIST MEMORY REPRESENTATION (Non-Contiguous Nodes)\n";
        std::cout << "============================================================\n";
        std::cout << std::left << std::setw(14) << "Student ID" 
                  << std::setw(12) << "Marks" 
                  << std::setw(20) << "Node Address" 
                  << std::setw(20) << "Next Pointer Addr" << "\n";
        std::cout << "------------------------------------------------------------\n";
        MarkNode* curr = head;
        while (curr) {
            std::cout << std::left << std::setw(14) << curr->studentId
                      << std::setw(12) << curr->marks
                      << "0x" << std::hex << reinterpret_cast<uintptr_t>(curr) << std::dec << "\t"
                      << (curr->next ? ("0x" + std::to_string(reinterpret_cast<uintptr_t>(curr->next))) : "NULL") << "\n";
            curr = curr->next;
        }
        std::cout << "============================================================\n";
    }

    // c. Count how many students scored more than 80 marks
    void countHighScorers(double threshold = 80.0) const {
        // Count in Array
        int arrayCount = 0;
        for (int i = 0; i < count; ++i) {
            if (arrMarks[i] > threshold) {
                arrayCount++;
            }
        }

        // Count in Linked List
        int llCount = 0;
        MarkNode* curr = head;
        while (curr) {
            if (curr->marks > threshold) {
                llCount++;
            }
            curr = curr->next;
        }

        std::cout << "\n--- High Scorers Analysis (Marks > " << threshold << ") ---\n";
        std::cout << "Total students scoring > " << threshold << " (from Array):       " << arrayCount << "\n";
        std::cout << "Total students scoring > " << threshold << " (from Linked List): " << llCount << "\n\n";
    }
};

int main() {
    IAMarksManager mgr;

    std::cout << "=== Internal Assessment (IA) Marks Management ===\n";
    // a. Insert marks
    mgr.insert(201, 85.5);
    mgr.insert(202, 72.0);
    mgr.insert(203, 91.0);
    mgr.insert(204, 64.5);
    mgr.insert(205, 82.5);
    mgr.insert(206, 88.0);

    // b. Display memory representation
    mgr.displayMemoryRepresentation();

    // c. Count students with marks > 80
    mgr.countHighScorers(80.0);

    return 0;
}

#include <iostream>
#include <string>

/*
 * Circular Queue for Bus Pass Distribution:
 * a. Insert student IDs in circular queue
 * b. Delete student ID as pass is issued
 * c. Detect queue full/empty conditions
 * d. Display the circular queue
 */

class BusPassQueue {
private:
    std::string* arr;
    int capacity;
    int front;
    int rear;
    int count;

public:
    BusPassQueue(int size = 5) : capacity(size), front(0), rear(-1), count(0) {
        arr = new std::string[capacity];
    }

    ~BusPassQueue() {
        delete[] arr;
    }

    // c. Detect queue empty condition
    bool isEmpty() const {
        return count == 0;
    }

    // c. Detect queue full condition
    bool isFull() const {
        return count == capacity;
    }

    // a. Insert student ID in circular queue
    void insertStudentID(const std::string& studentId) {
        if (isFull()) {
            std::cout << "[FULL CONDITION DETECTED] Bus Pass Queue is full! Cannot add Student ID: " 
                      << studentId << "\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = studentId;
        count++;
        std::cout << "Enqueued Student ID [" << studentId << "] at index " << rear 
                  << " (Queue size: " << count << "/" << capacity << ")\n";
    }

    // b. Delete student ID as pass is issued
    void issuePass() {
        if (isEmpty()) {
            std::cout << "[EMPTY CONDITION DETECTED] Bus Pass Queue is empty! No students waiting.\n";
            return;
        }
        std::string issuedStudent = arr[front];
        front = (front + 1) % capacity;
        count--;
        std::cout << ">>> Bus Pass ISSUED to Student ID: " << issuedStudent 
                  << " (Remaining waiting: " << count << ") <<<\n";
    }

    // d. Display circular queue
    void display() const {
        if (isEmpty()) {
            std::cout << "Bus Pass Queue is EMPTY.\n\n";
            return;
        }
        std::cout << "\n--- Current Bus Pass Circular Queue ---\n";
        std::cout << "Front index: " << front << " | Rear index: " << rear << "\n";
        std::cout << "Queue contents: ";
        for (int i = 0; i < count; ++i) {
            int actualIdx = (front + i) % capacity;
            std::cout << "[" << actualIdx << "]: " << arr[actualIdx] << "  ";
        }
        std::cout << "\n----------------------------------------\n\n";
    }
};

int main() {
    BusPassQueue bpq(4); // Fixed circular capacity of 4

    std::cout << "=== Bus Pass Distribution Counter (Circular Queue) ===\n\n";

    // Insert student IDs
    bpq.insertStudentID("STU-1001");
    bpq.insertStudentID("STU-1002");
    bpq.insertStudentID("STU-1003");
    bpq.insertStudentID("STU-1004");
    bpq.display();

    // Trigger full condition
    bpq.insertStudentID("STU-1005");

    // Issue passes (Delete from queue)
    bpq.issuePass();
    bpq.issuePass();
    bpq.display();

    // Insert more into reused wrapped-around circular slots
    bpq.insertStudentID("STU-1005");
    bpq.insertStudentID("STU-1006");
    bpq.display();

    // Issue all remaining
    bpq.issuePass();
    bpq.issuePass();
    bpq.issuePass();
    bpq.issuePass();

    // Trigger empty condition
    bpq.issuePass();

    return 0;
}

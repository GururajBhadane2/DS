#include <iostream>
#include <string>
#include <vector>

/*
 * Student Admission Queue:
 * a. Enqueue student token number
 * b. Dequeue and display processed student
 * c. Display front and rear token number
 * d. Display complete queue
 */

struct StudentApplicant {
    int tokenNo;
    std::string name;
    std::string course;
};

class AdmissionQueue {
private:
    StudentApplicant queueArr[100];
    int front;
    int rear;
    int count;
    int capacity;

public:
    AdmissionQueue(int cap = 100) : front(0), rear(-1), count(0), capacity(cap) {}

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == capacity;
    }

    // a. Enqueue student token number
    void enqueue(int tokenNo, const std::string& name, const std::string& course) {
        if (isFull()) {
            std::cout << "Admission Queue is Full! Cannot issue token " << tokenNo << ".\n";
            return;
        }
        rear++;
        queueArr[rear] = {tokenNo, name, course};
        count++;
        std::cout << "Enqueued Token #" << tokenNo << " for [" << name << " - " << course << "].\n";
    }

    // b. Dequeue and display student processes
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. No applicants waiting for admission processing.\n";
            return;
        }
        StudentApplicant processed = queueArr[front];
        front++;
        count--;
        std::cout << "\n>>> PROCESSED ADMISSION FOR: Token #" << processed.tokenNo 
                  << " | Name: " << processed.name 
                  << " | Admitted to: " << processed.course << " <<<\n\n";
    }

    // c. Display front and rear token number
    void displayFrontAndRear() const {
        if (isEmpty()) {
            std::cout << "Queue is empty. Front and Rear pointers are inactive.\n";
            return;
        }
        std::cout << "------------------------------------------\n";
        std::cout << "Front Token: #" << queueArr[front].tokenNo 
                  << " (" << queueArr[front].name << ")\n";
        std::cout << "Rear Token:  #" << queueArr[rear].tokenNo 
                  << " (" << queueArr[rear].name << ")\n";
        std::cout << "------------------------------------------\n";
    }

    // d. Display complete queue
    void displayQueue() const {
        if (isEmpty()) {
            std::cout << "Admission Queue is currently empty.\n";
            return;
        }

        std::cout << "\n============================================================\n";
        std::cout << "                Current Admission Waiting Queue             \n";
        std::cout << "============================================================\n";
        std::cout << "Position\tToken No\tApplicant Name\t\tCourse\n";
        std::cout << "------------------------------------------------------------\n";
        int pos = 1;
        for (int i = front; i <= rear; ++i) {
            std::cout << pos++ << "\t\t#" << queueArr[i].tokenNo 
                      << "\t\t" << queueArr[i].name 
                      << "\t\t" << queueArr[i].course << "\n";
        }
        std::cout << "============================================================\n";
        std::cout << "Total waiting applicants: " << count << "\n\n";
    }
};

int main() {
    AdmissionQueue admissionQ;

    std::cout << "=== College Admission Queue Simulation ===\n\n";

    // a. Enqueue students
    admissionQ.enqueue(101, "Rohan Deshmukh", "Computer Science");
    admissionQ.enqueue(102, "Ananya Verma",   "Information Tech");
    admissionQ.enqueue(103, "Kunal Sen",       "Electronics");
    admissionQ.enqueue(104, "Priya Sharma",    "Data Science");

    // d. Display complete queue
    admissionQ.displayQueue();

    // c. Display front and rear tokens
    admissionQ.displayFrontAndRear();

    // b. Dequeue and process
    admissionQ.dequeue();
    admissionQ.dequeue();

    // c. Display front and rear tokens after processing
    admissionQ.displayFrontAndRear();

    // d. Display updated queue
    admissionQ.displayQueue();

    return 0;
}

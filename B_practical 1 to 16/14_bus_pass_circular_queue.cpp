#include <iostream>
#include <string>
using namespace std;

const int MAX = 5; // Circular queue size

string q[MAX];
int front = -1;
int rear = -1;

// Check if Full
bool isFull() {
    return (front == (rear + 1) % MAX);
}

// Check if Empty
bool isEmpty() {
    return (front == -1);
}

// Enqueue into circular queue
void enqueue() {
    if (isFull()) {
        cout << "Bus Pass Queue is FULL! Please wait.\n";
        return;
    }
    string studentId;
    cout << "Enter Student ID for Bus Pass: ";
    cin >> studentId;

    if (isEmpty()) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    q[rear] = studentId;
    cout << "Student " << studentId << " added to queue at position " << rear << ".\n";
}

// Dequeue from circular queue
void dequeue() {
    if (isEmpty()) {
        cout << "Bus Pass Queue is EMPTY!\n";
        return;
    }
    cout << "Issued Bus Pass to Student: " << q[front] << "\n";

    if (front == rear) {
        // Only one element was present
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Display circular queue
void display() {
    if (isEmpty()) {
        cout << "Queue is Empty!\n";
        return;
    }
    cout << "\n--- Bus Pass Waiting Line ---\n";
    int i = front;
    while (true) {
        cout << q[i] << " ";
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    cout << "\n";
}

int main() {
    int choice;
    do {
        cout << "\n--- Bus Pass Counter (Circular Queue) ---\n";
        cout << "1. Issue Token (Enqueue)\n";
        cout << "2. Serve Student (Dequeue)\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}

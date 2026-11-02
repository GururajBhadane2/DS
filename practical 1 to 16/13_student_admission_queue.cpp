#include <iostream>
#include <string>
using namespace std;

const int MAX = 10;

struct Student {
    int token;
    string name;
};

Student q[MAX];
int front = -1;
int rear = -1;

// Enqueue: Add student to queue
void enqueue() {
    if (rear == MAX - 1) {
        cout << "Admission Queue is Full!\n";
        return;
    }
    if (front == -1) front = 0;
    rear++;
    cout << "Enter Token Number: ";
    cin >> q[rear].token;
    cout << "Enter Student Name: ";
    cin >> q[rear].name;
    cout << "Student " << q[rear].name << " added to waiting queue.\n";
}

// Dequeue: Process next student
void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue is Empty! No students waiting.\n";
        front = -1;
        rear = -1;
        return;
    }
    cout << "Processed Token #" << q[front].token << " (" << q[front].name << ") for admission.\n";
    front++;
    if (front > rear) {
        front = -1;
        rear = -1;
    }
}

// Display queue
void display() {
    if (front == -1 || front > rear) {
        cout << "Queue is Empty!\n";
        return;
    }
    cout << "\n--- Current Admission Queue ---\n";
    cout << "Token\tName\n";
    for (int i = front; i <= rear; i++) {
        cout << q[i].token << "\t" << q[i].name << "\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n--- Student Admission Counter (Linear Queue) ---\n";
        cout << "1. Enqueue Student\n";
        cout << "2. Dequeue Student\n";
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

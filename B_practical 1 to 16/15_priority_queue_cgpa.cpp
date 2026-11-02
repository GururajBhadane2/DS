#include <iostream>
#include <string>
using namespace std;

const int MAX = 50;

struct Student {
    int roll;
    string name;
    float cgpa;
};

Student pq[MAX];
int n = 0;

// Enqueue student by priority (highest CGPA first)
void enqueue() {
    if (n >= MAX) {
        cout << "Priority Queue is Full!\n";
        return;
    }
    Student s;
    cout << "Enter Roll No: ";
    cin >> s.roll;
    cout << "Enter Name: ";
    cin >> s.name;
    cout << "Enter CGPA: ";
    cin >> s.cgpa;

    // Find position to insert based on CGPA (highest first)
    int i = n - 1;
    while (i >= 0 && pq[i].cgpa < s.cgpa) {
        pq[i + 1] = pq[i];
        i--;
    }
    pq[i + 1] = s;
    n++;
    cout << "Student " << s.name << " added with priority CGPA: " << s.cgpa << "\n";
}

// Dequeue: Serve highest priority student
void dequeue() {
    if (n == 0) {
        cout << "Queue is Empty!\n";
        return;
    }
    cout << "\nServing Student:\n";
    cout << "Roll: " << pq[0].roll << " | Name: " << pq[0].name << " | CGPA: " << pq[0].cgpa << "\n";

    // Shift remaining students forward
    for (int i = 0; i < n - 1; i++) {
        pq[i] = pq[i + 1];
    }
    n--;
}

// Display priority queue
void display() {
    if (n == 0) {
        cout << "Queue is Empty!\n";
        return;
    }
    cout << "\n--- Priority Queue (Highest CGPA First) ---\n";
    cout << "Priority\tRoll\tName\tCGPA\n";
    for (int i = 0; i < n; i++) {
        cout << (i + 1) << "\t\t" << pq[i].roll << "\t" << pq[i].name << "\t" << pq[i].cgpa << "\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n--- Scholarship / Interview Priority Queue ---\n";
        cout << "1. Enqueue Student (by CGPA Priority)\n";
        cout << "2. Dequeue Student (Highest CGPA)\n";
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

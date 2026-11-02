// Set 70 - Software Support Ticket Resolution Queue Simulation
// Simulate the support ticket system of a software
// company using a simple queue. Each ticket has
// a Ticket ID and Issue Type. Write functions to:
// a. Enqueue a new ticket
// b. Dequeue and display the ticket being resolved
// c. Display the front and rear tickets
// d. Display the complete queue

#include <iostream>
#include <string>
using namespace std;

const int MAX = 10;
struct Ticket {
    int id;
    string issue;
};

Ticket q[MAX];
int front = -1, rear = -1;

void enqueue() {
    if (rear == MAX - 1) { cout << "Ticket queue full!\n"; return; }
    Ticket t;
    cout << "Enter Ticket ID: "; cin >> t.id;
    cout << "Enter Issue Type (Bug/Billing/Login): "; cin >> t.issue;
    if (front == -1) front = 0;
    q[++rear] = t;
    cout << "Ticket #" << t.id << " (" << t.issue << ") queued.\n";
}

void dequeue() {
    if (front == -1 || front > rear) { cout << "No tickets to resolve!\n"; front = rear = -1; return; }
    cout << "Resolved Ticket #" << q[front].id << " (" << q[front].issue << ")\n";
    front++;
    if (front > rear) front = rear = -1;
}

void showFrontRear() {
    if (front == -1 || front > rear) { cout << "Queue empty!\n"; return; }
    cout << "Front Ticket: #" << q[front].id << " | Rear Ticket: #" << q[rear].id << "\n";
}

void display() {
    if (front == -1 || front > rear) { cout << "No pending tickets!\n"; return; }
    cout << "\n--- Support Ticket Queue ---\n";
    for (int i = front; i <= rear; i++) cout << "#" << q[i].id << " [" << q[i].issue << "]\n";
}

int main() {
int ch;
    do {
        cout << "\n--- Set 70: Support Ticket Queue ---\n1. Enqueue New Ticket\n2. Dequeue (Resolve Ticket)\n3. Display Front & Rear\n4. Display Complete Queue\n5. Exit\nEnter: ";
        cin >> ch;
        if (ch == 1) enqueue();
        else if (ch == 2) dequeue();
        else if (ch == 3) showFrontRear();
        else if (ch == 4) display();
    } while (ch != 5);
    return 0;
}

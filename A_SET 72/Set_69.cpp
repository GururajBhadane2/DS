// Set 69 - Customer Care Call Center Queue Simulation
// Simulate the call queue of a customer care
// centre using a simple queue. Write functions to:
// a. Enqueue an incoming call ID
// b. Dequeue and display the call being answered
// c. Display the number of calls waiting
// d. Display the complete queue

#include <iostream>
using namespace std;

const int MAX = 10;
int q[MAX];
int front = -1, rear = -1;

void enqueue() {
    if (rear == MAX - 1) { cout << "All lines busy! Queue full.\n"; return; }
    int callId;
    cout << "Enter Incoming Call ID: "; cin >> callId;
    if (front == -1) front = 0;
    q[++rear] = callId;
    cout << "Call #" << callId << " placed in waiting queue.\n";
}

void dequeue() {
    if (front == -1 || front > rear) { cout << "No calls waiting!\n"; front = rear = -1; return; }
    cout << "Agent answering Call #" << q[front++] << "\n";
    if (front > rear) front = rear = -1;
}

void countWaiting() {
    if (front == -1 || front > rear) cout << "No calls waiting.\n";
    else cout << "Number of calls waiting in line: " << (rear - front + 1) << "\n";
}

void display() {
    if (front == -1 || front > rear) { cout << "No calls waiting.\n"; return; }
    cout << "Call Queue: ";
    for (int i = front; i <= rear; i++) cout << "Call#" << q[i] << " ";
    cout << "\n";
}

int main() {
int ch;
    do {
        cout << "\n--- Set 69: Customer Care Call Queue ---\n1. Enqueue Incoming Call\n2. Dequeue (Answer Call)\n3. Number of Calls Waiting\n4. Display Complete Queue\n5. Exit\nEnter: ";
        cin >> ch;
        if (ch == 1) enqueue();
        else if (ch == 2) dequeue();
        else if (ch == 3) countWaiting();
        else if (ch == 4) display();
    } while (ch != 5);
    return 0;
}

// Title: Set 71 - Railway Reservation Counter Queue with Overflow Alert
// Problem Statement:
//   Simulate the railway reservation counter
//   using a simple queue. Write functions to:
//   a. Enqueue a passenger's token number
//   b. Dequeue and display the passenger being served
//   c. Display "Queue Overflow" when the counter line is full
//   d. Display the complete queue

#include <iostream>
using namespace std;

const int MAX = 5;
int q[MAX];
int front = -1, rear = -1;

void enqueue() {
    if (rear == MAX - 1) { cout << "Queue Overflow! Counter line is completely full.\n"; return; }
    int token;
    cout << "Enter passenger token number: "; cin >> token;
    if (front == -1) front = 0;
    q[++rear] = token;
    cout << "Passenger #" << token << " joined reservation counter queue.\n";
}

void dequeue() {
    if (front == -1 || front > rear) { cout << "Queue is empty!\n"; front = rear = -1; return; }
    cout << "Ticket issued to passenger #" << q[front++] << "\n";
    if (front > rear) front = rear = -1;
}

void display() {
    if (front == -1 || front > rear) { cout << "Reservation counter line is empty!\n"; return; }
    cout << "\n--- Reservation Counter Waiting Line ---\n";
    for (int i = front; i <= rear; i++) cout << "#" << q[i] << " ";
    cout << "\n";
}

int main() {
int ch;
    do {
        cout << "\n--- Set 71: Railway Reservation Queue ---\n1. Enqueue Passenger\n2. Dequeue (Serve Passenger)\n3. Display Complete Queue\n4. Exit\nEnter: ";
        cin >> ch;
        if (ch == 1) enqueue();
        else if (ch == 2) dequeue();
        else if (ch == 3) display();
    } while (ch != 4);
    return 0;
}

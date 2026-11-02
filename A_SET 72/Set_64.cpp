/*
================================================================================
Title: Set 64 - Bank Teller Counter Queue with Waiting Count Simulation
Problem Statement:
  Simulate the teller counter of a bank using
  a simple queue. Write functions to:
  a. Enqueue a customer's token number
  b. Dequeue and display the customer being served
  c. Display the front and rear token numbers
  d. Display the number of customers waiting
================================================================================
*/

#include <iostream>
using namespace std;

const int MAX = 10;
int q[MAX];
int front = -1, rear = -1;

void enqueue() {
    if (rear == MAX - 1) { cout << "Teller Queue Full!\n"; return; }
    int t;
    cout << "Enter customer token: "; cin >> t;
    if (front == -1) front = 0;
    q[++rear] = t;
    cout << "Token #" << t << " enqueued.\n";
}

void dequeue() {
    if (front == -1 || front > rear) { cout << "Queue Empty!\n"; front = rear = -1; return; }
    cout << "Serving customer #" << q[front++] << "\n";
    if (front > rear) front = rear = -1;
}

void countWaiting() {
    if (front == -1 || front > rear) cout << "No customers waiting.\n";
    else cout << "Number of customers waiting: " << (rear - front + 1) << "\n";
}

int main() {
        cout << "=====================================================\n";
    cout << "  SET 64: Bank Teller Counter Queue with Waiting Count Simulation\n";
    cout << "=====================================================\n";
int ch;
    do {
        cout << "\n--- Set 64: Bank Teller Counter Queue ---\n";
        cout << "1. Enqueue Token\n2. Dequeue (Serve Customer)\n3. Front/Rear\n4. Number Waiting\n5. Exit\nEnter: ";
        cin >> ch;
        if (ch == 1) enqueue();
        else if (ch == 2) dequeue();
        else if (ch == 3) {
            if (front != -1) cout << "Front: #" << q[front] << " | Rear: #" << q[rear] << "\n";
        } else if (ch == 4) countWaiting();
    } while (ch != 5);
    return 0;
}

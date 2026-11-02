// Set 63 - Cinema Ticket Booking Counter Queue Simulation
// Simulate the ticket booking counter of a cinema using a simple queue (array based). Write
// functions to:
// a. Enqueue a customer's token number (display "Queue Overflow" if full)
// b. Dequeue a customer when served (display "Queue Underflow" if empty)
// c. Display the front and rear token numbers
// d. Display the complete queue

#include <iostream>
using namespace std;

const int MAX = 5;
int q[MAX];
int front = -1, rear = -1;

void enqueue() {
    if (rear == MAX - 1) { cout << "Queue Overflow! Ticket counter queue is full.\n"; return; }
    int token;
    cout << "Enter Customer Token: "; cin >> token;
    if (front == -1) front = 0;
    q[++rear] = token;
    cout << "Token #" << token << " enqueued.\n";
}

void dequeue() {
    if (front == -1 || front > rear) { cout << "Queue Underflow! No customers in queue.\n"; front = rear = -1; return; }
    cout << "Issued ticket to Customer Token #" << q[front++] << "\n";
    if (front > rear) front = rear = -1;
}

void showFrontRear() {
    if (front == -1) { cout << "Queue empty!\n"; return; }
    cout << "Front Token: #" << q[front] << " | Rear Token: #" << q[rear] << "\n";
}

void display() {
    if (front == -1) { cout << "Queue empty!\n"; return; }
    cout << "Cinema Queue: ";
    for (int i = front; i <= rear; i++) cout << "#" << q[i] << " ";
    cout << "\n";
}

int main() {
int ch;
    do {
        cout << "\n--- Set 63: Cinema Ticket Counter Queue ---\n";
        cout << "1. Enqueue Customer\n2. Dequeue Customer\n3. Front & Rear\n4. Display Complete Queue\n5. Exit\nEnter: ";
        cin >> ch;
        switch (ch) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: showFrontRear(); break;
            case 4: display(); break;
        }
    } while (ch != 5);
    return 0;
}

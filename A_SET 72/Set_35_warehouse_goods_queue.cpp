// Title: Set 35 - Warehouse Goods Dispatch Queue Simulation
// Problem Statement:
//   Simulate the goods dispatch queue of a warehouse.
//   a. Enqueue an order number
//   b. Dequeue and display the order being dispatched
//   c. Display the front and rear order numbers
//   d. Display the complete queue

#include <iostream>
using namespace std;

const int MAX = 10;
int q[MAX];
int front = -1, rear = -1;

void enqueue() {
    if (rear == MAX - 1) { cout << "Dispatch Queue Full!\n"; return; }
    int order;
    cout << "Enter Order Number: "; cin >> order;
    if (front == -1) front = 0;
    q[++rear] = order;
    cout << "Order #" << order << " added to dispatch queue.\n";
}

void dequeue() {
    if (front == -1 || front > rear) { cout << "Queue is Empty!\n"; front = rear = -1; return; }
    cout << "Dispatched Order #" << q[front++] << "\n";
    if (front > rear) front = rear = -1;
}

void showFrontRear() {
    if (front == -1) { cout << "Queue Empty!\n"; return; }
    cout << "Front Order: #" << q[front] << " | Rear Order: #" << q[rear] << "\n";
}

void display() {
    if (front == -1) { cout << "Queue Empty!\n"; return; }
    cout << "Pending Orders: ";
    for (int i = front; i <= rear; i++) cout << "#" << q[i] << " ";
    cout << "\n";
}

int main() {
int ch;
    do {
        cout << "\n--- Set 35: Goods Dispatch Queue ---\n1. Enqueue Order\n2. Dequeue Order\n3. Show Front/Rear\n4. Display Queue\n5. Exit\nEnter: ";
        cin >> ch;
        if (ch == 1) enqueue();
        else if (ch == 2) dequeue();
        else if (ch == 3) showFrontRear();
        else if (ch == 4) display();
    } while (ch != 5);
    return 0;
}

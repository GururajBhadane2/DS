// Set 68 - Food Delivery App Order Processing Queue Simulation
// Simulate the order processing of a food delivery app using a simple queue. Write functions to:
// a. Enqueue a new order number
// b. Dequeue and display the order being dispatched
// c. Display the front and rear order numbers
// d. Display all pending orders

#include <iostream>
using namespace std;

const int MAX = 10;
int q[MAX];
int front = -1, rear = -1;

void enqueue() {
    if (rear == MAX - 1) { cout << "Kitchen Queue Full!\n"; return; }
    int order;
    cout << "Enter Order Number: "; cin >> order;
    if (front == -1) front = 0;
    q[++rear] = order;
    cout << "Order #" << order << " placed in cooking queue.\n";
}

void dequeue() {
    if (front == -1 || front > rear) { cout << "No pending orders!\n"; front = rear = -1; return; }
    cout << "Order #" << q[front++] << " prepared and dispatched for delivery!\n";
    if (front > rear) front = rear = -1;
}

void showFrontRear() {
    if (front == -1 || front > rear) { cout << "Queue empty!\n"; return; }
    cout << "Front Order: #" << q[front] << " | Rear Order: #" << q[rear] << "\n";
}

void display() {
    if (front == -1 || front > rear) { cout << "No pending orders!\n"; return; }
    cout << "All Pending Orders: ";
    for (int i = front; i <= rear; i++) cout << "#" << q[i] << " ";
    cout << "\n";
}

int main() {
int ch;
    do {
        cout << "\n--- Set 68: Food Delivery Order Queue ---\n1. Enqueue New Order\n2. Dequeue Dispatched Order\n3. Front & Rear Orders\n4. Display Pending Orders\n5. Exit\nEnter: ";
        cin >> ch;
        if (ch == 1) enqueue();
        else if (ch == 2) dequeue();
        else if (ch == 3) showFrontRear();
        else if (ch == 4) display();
    } while (ch != 5);
    return 0;
}

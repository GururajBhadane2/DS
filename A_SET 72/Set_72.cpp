// Set 72 - Amazon Warehouse Order Packing Line Queue Simulation
// Simulate the order packing line of an Amazon
// warehouse using a simple queue. Write functions
// to:
// a. Enqueue an order number for packing
// b. Dequeue and display the order being packed
// c. Display the front and rear order numbers
// d. Display the complete queue and the count of orders waiting

#include <iostream>
using namespace std;

const int MAX = 10;
int q[MAX];
int front = -1, rear = -1;

void enqueue() {
    if (rear == MAX - 1) { cout << "Packing conveyor is full!\n"; return; }
    int orderNo;
    cout << "Enter Order Number for packing: "; cin >> orderNo;
    if (front == -1) front = 0;
    q[++rear] = orderNo;
    cout << "Order #" << orderNo << " placed on packing belt.\n";
}

void dequeue() {
    if (front == -1 || front > rear) { cout << "No orders waiting to be packed!\n"; front = rear = -1; return; }
    cout << "Order #" << q[front++] << " successfully packed and sealed!\n";
    if (front > rear) front = rear = -1;
}

void showFrontRear() {
    if (front == -1 || front > rear) { cout << "Queue empty!\n"; return; }
    cout << "Front Order: #" << q[front] << " | Rear Order: #" << q[rear] << "\n";
}

void display() {
    if (front == -1 || front > rear) { cout << "Packing queue is empty!\n"; return; }
    cout << "\n--- Amazon Packing Line Queue ---\n";
    for (int i = front; i <= rear; i++) cout << "#" << q[i] << " ";
    cout << "\nTotal Orders Waiting: " << (rear - front + 1) << "\n";
}

int main() {
int ch;
    do {
        cout << "\n--- Set 72: Amazon Packing Line Queue ---\n1. Enqueue Order for Packing\n2. Dequeue (Pack Order)\n3. Front & Rear Orders\n4. Display Queue & Count Waiting\n5. Exit\nEnter: ";
        cin >> ch;
        if (ch == 1) enqueue();
        else if (ch == 2) dequeue();
        else if (ch == 3) showFrontRear();
        else if (ch == 4) display();
    } while (ch != 5);
    return 0;
}

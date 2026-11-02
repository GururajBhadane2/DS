// Title: Set 25 - Library Book Issue Counter Queue Simulation
// Problem Statement:
//   Simulate the book issue counter queue of
//   a library.
//   a. Enqueue a member's token number
//   b. Dequeue and display the member being served
//   c. Display the front and rear token numbers
//   d. Display the complete queue

#include <iostream>
using namespace std;

const int MAX = 10;
int q[MAX];
int front = -1, rear = -1;

void enqueue() {
    if (rear == MAX - 1) { cout << "Queue Overflow! Counter line is full.\n"; return; }
    int token;
    cout << "Enter member token number: "; cin >> token;
    if (front == -1) front = 0;
    q[++rear] = token;
    cout << "Member token #" << token << " enqueued.\n";
}

void dequeue() {
    if (front == -1 || front > rear) { cout << "Queue Underflow! No members waiting.\n"; front = rear = -1; return; }
    cout << "Serving member with token #" << q[front++] << "\n";
    if (front > rear) front = rear = -1;
}

void showFrontRear() {
    if (front == -1) { cout << "Queue is empty!\n"; return; }
    cout << "Front Token: #" << q[front] << " | Rear Token: #" << q[rear] << "\n";
}

void display() {
    if (front == -1) { cout << "Queue is empty!\n"; return; }
    cout << "\n--- Book Issue Queue ---\n";
    for (int i = front; i <= rear; i++) cout << "#" << q[i] << " ";
    cout << "\n";
}

int main() {
int ch;
    do {
        cout << "\n--- Set 25: Library Issue Counter Queue ---\n";
        cout << "1. Enqueue Member Token\n2. Dequeue (Serve Member)\n3. Display Front & Rear\n4. Display Complete Queue\n5. Exit\nEnter choice: ";
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

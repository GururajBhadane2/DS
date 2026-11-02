// Title: Set 66 - Hospital OPD Queue with Full & Empty Boundary Checks
// Problem Statement:
//   Simulate the OPD queue of a hospital using
//   a simple queue. Write functions to:
//   a. Enqueue a patient's token number
//   b. Dequeue and display the patient being called
//   c. Check whether the queue is empty or full
//   d. Display the complete queue

#include <iostream>
using namespace std;

const int MAX = 5;
int q[MAX];
int front = -1, rear = -1;

bool isFull() { return rear == MAX - 1; }
bool isEmpty() { return front == -1 || front > rear; }

void enqueue() {
    if (isFull()) { cout << "OPD Queue is Full! Cannot add more patients.\n"; return; }
    int token;
    cout << "Enter Patient Token: "; cin >> token;
    if (front == -1) front = 0;
    q[++rear] = token;
    cout << "Patient Token #" << token << " enqueued.\n";
}

void dequeue() {
    if (isEmpty()) { cout << "OPD Queue is Empty!\n"; front = rear = -1; return; }
    cout << "Calling Patient Token #" << q[front++] << " into cabin.\n";
    if (front > rear) front = rear = -1;
}

void display() {
    if (isEmpty()) { cout << "Queue is Empty!\n"; return; }
    cout << "OPD Waiting Queue: ";
    for (int i = front; i <= rear; i++) cout << "#" << q[i] << " ";
    cout << "\n";
}

int main() {
int ch;
    do {
        cout << "\n--- Set 66: Hospital OPD Queue ---\n1. Enqueue Patient\n2. Call Patient (Dequeue)\n3. Check Status (Empty/Full)\n4. Display Complete Queue\n5. Exit\nEnter: ";
        cin >> ch;
        if (ch == 1) enqueue();
        else if (ch == 2) dequeue();
        else if (ch == 3) {
            cout << "Queue Empty: " << (isEmpty() ? "YES" : "NO") << "\n";
            cout << "Queue Full:  " << (isFull() ? "YES" : "NO") << "\n";
        }
        else if (ch == 4) display();
    } while (ch != 5);
    return 0;
}

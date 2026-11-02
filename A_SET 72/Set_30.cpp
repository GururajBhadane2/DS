/*
================================================================================
Title: Set 30 - Hospital OPD Queue Simulation using Simple Queue
Problem Statement:
  Simulate the OPD (outpatient department)
  queue of a hospital.
  a. Enqueue a patient's token number
  b. Dequeue and display the patient being called
  c. Display the front and rear token numbers
  d. Display the complete queue
================================================================================
*/

#include <iostream>
using namespace std;

const int MAX = 10;
int q[MAX];
int front = -1, rear = -1;

void enqueue() {
    if (rear == MAX - 1) { cout << "Queue Overflow! OPD line full.\n"; return; }
    int token;
    cout << "Enter Patient Token No: "; cin >> token;
    if (front == -1) front = 0;
    q[++rear] = token;
    cout << "Patient Token #" << token << " queued.\n";
}

void dequeue() {
    if (front == -1 || front > rear) { cout << "OPD Queue is Empty!\n"; front = rear = -1; return; }
    cout << "Calling Patient Token #" << q[front++] << " into doctor cabin.\n";
    if (front > rear) front = rear = -1;
}

void showFrontRear() {
    if (front == -1) { cout << "Queue is empty!\n"; return; }
    cout << "Front Token: #" << q[front] << " | Rear Token: #" << q[rear] << "\n";
}

void display() {
    if (front == -1) { cout << "Queue is empty!\n"; return; }
    cout << "\n--- Current OPD Queue ---\n";
    for (int i = front; i <= rear; i++) cout << "#" << q[i] << " ";
    cout << "\n";
}

int main() {
        cout << "=====================================================\n";
    cout << "  SET 30: Hospital OPD Queue Simulation using Simple Queue\n";
    cout << "=====================================================\n";
int ch;
    do {
        cout << "\n--- Set 30: Hospital OPD Queue ---\n";
        cout << "1. Enqueue Patient Token\n2. Dequeue (Call Patient)\n3. Display Front & Rear\n4. Display Complete Queue\n5. Exit\nEnter choice: ";
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

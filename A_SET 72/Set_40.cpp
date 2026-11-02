// Set 40 - Bank Teller Counter Queue Simulation
// Simulate the teller counter queue of a bank.
// a. Enqueue a customer's token number
// b. Dequeue and display the customer being served
// c. Display the front and rear token numbers
// d. Display the complete queue

#include <iostream>
using namespace std;

const int MAX = 10;
int q[MAX];
int front = -1, rear = -1;

void enqueue() {
    if (rear == MAX - 1) { cout << "Teller Queue Full!\n"; return; }
    int token;
    cout << "Enter customer token: "; cin >> token;
    if (front == -1) front = 0;
    q[++rear] = token;
    cout << "Customer #" << token << " enqueued.\n";
}

void dequeue() {
    if (front == -1 || front > rear) { cout << "Queue Empty!\n"; front = rear = -1; return; }
    cout << "Teller serving customer #" << q[front++] << "\n";
    if (front > rear) front = rear = -1;
}

int main() {
int ch;
    do {
        cout << "\n1. Enqueue Customer\n2. Dequeue Customer\n3. Show Front/Rear\n4. Display\n5. Exit\nEnter: ";
        cin >> ch;
        if (ch == 1) enqueue();
        else if (ch == 2) dequeue();
        else if (ch == 3) {
            if (front != -1) cout << "Front: #" << q[front] << " | Rear: #" << q[rear] << "\n";
        } else if (ch == 4) {
            if (front != -1) {
                cout << "Waiting customers: ";
                for (int i = front; i <= rear; i++) cout << "#" << q[i] << " ";
                cout << "\n";
            }
        }
    } while (ch != 5);
    return 0;
}

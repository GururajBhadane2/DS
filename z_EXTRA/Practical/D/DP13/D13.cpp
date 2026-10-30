#include <iostream>
using namespace std;

class AdmissionQueue {
public:
    int A[5];
    int front;
    int rear;

    AdmissionQueue() {
        front = -1;
        rear = -1;
    }

    void enQueue(int tokenNumber) {
        if ((front == 0 && rear == 4) || (rear == (front - 1) % 4)) {
            cout << "Queue Overflow\n";
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (rear == 4 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }
        A[rear] = tokenNumber;
        cout << "Token " << tokenNumber << " added to queue\n";
    }

    void deQueue() {
        if (front == -1) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Processed student token: " << A[front] << "\n";
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (front == 4) {
            front = 0;
        } else {
            front++;
        }
    }

    void displayFrontRear() {
        if (front == -1) {
            cout << "Front: -1, Rear: -1\n";
        } else {
            cout << "Front token: " << A[front] << ", Rear token: " << A[rear] << "\n";
        }
    }

    void displayQueue() {
        if (front == -1) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Complete Queue: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                cout << A[i] << " ";
            }
        } else {
            for (int i = front; i < 5; i++) {
                cout << A[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << A[i] << " ";
            }
        }
        cout << "\n";
    }
};

int main() {
    AdmissionQueue q;

    q.enQueue(101);
    q.enQueue(102);
    q.enQueue(103);
    
    q.displayFrontRear();
    q.displayQueue();

    q.deQueue();
    
    q.displayFrontRear();
    q.displayQueue();

    return 0;
}


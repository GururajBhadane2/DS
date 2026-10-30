#include <iostream>
#include <string>
using namespace std;

const int MAX = 10;

struct Request {
    int id;
    string name;
    string type; // "Emergency" or "Normal"
};

Request dequeArr[MAX];
int front = -1;
int rear = -1;
int ticketCounter = 1;

bool isFull() {
    return (front == 0 && rear == MAX - 1) || (front == rear + 1);
}

bool isEmpty() {
    return (front == -1);
}

// Insert at Front (for Emergency Requests)
void insertFront() {
    if (isFull()) {
        cout << "Service Desk Queue is FULL!\n";
        return;
    }
    Request req;
    req.id = ticketCounter++;
    req.type = "Emergency";
    cout << "Enter Student Name: ";
    cin >> req.name;

    if (isEmpty()) {
        front = 0;
        rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }
    dequeArr[front] = req;
    cout << "Emergency Ticket #" << req.id << " added at FRONT for " << req.name << ".\n";
}

// Insert at Rear (for Normal Requests)
void insertRear() {
    if (isFull()) {
        cout << "Service Desk Queue is FULL!\n";
        return;
    }
    Request req;
    req.id = ticketCounter++;
    req.type = "Normal";
    cout << "Enter Student Name: ";
    cin >> req.name;

    if (isEmpty()) {
        front = 0;
        rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }
    dequeArr[rear] = req;
    cout << "Normal Ticket #" << req.id << " added at REAR for " << req.name << ".\n";
}

// Delete from Front (Serve standard order)
void deleteFront() {
    if (isEmpty()) {
        cout << "No requests to serve!\n";
        return;
    }
    cout << "Serving Ticket #" << dequeArr[front].id << " (" << dequeArr[front].name 
         << " - " << dequeArr[front].type << ") from FRONT.\n";

    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

// Display Deque
void display() {
    if (isEmpty()) {
        cout << "Queue is Empty!\n";
        return;
    }
    cout << "\n--- Service Desk Requests (Front to Rear) ---\n";
    int i = front;
    while (true) {
        cout << "Ticket #" << dequeArr[i].id << " [" << dequeArr[i].type << "] - " << dequeArr[i].name << "\n";
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
}

int main() {
    int choice;
    do {
        cout << "\n--- Student Service Desk (Deque) ---\n";
        cout << "1. Add Emergency Request (Insert Front)\n";
        cout << "2. Add Normal Request (Insert Rear)\n";
        cout << "3. Serve Next Request (Delete Front)\n";
        cout << "4. Display All Pending Requests\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: insertFront(); break;
            case 2: insertRear(); break;
            case 3: deleteFront(); break;
            case 4: display(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}

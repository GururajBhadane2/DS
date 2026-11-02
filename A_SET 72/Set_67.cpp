/*
================================================================================
Title: Set 67 - Airline Check-in Counter Queue Simulation
Problem Statement:
  Simulate the check-in counter of an airline
  using a simple queue. Each passenger has a Ticket No
  and Name. Write functions to:
  a. Enqueue a passenger       b. Dequeue and display the passenger being checked in
  c. Display the first and last passenger in the queue
  d. Display the complete queue
================================================================================
*/

#include <iostream>
#include <string>
using namespace std;

const int MAX = 10;
struct Passenger {
    string ticket;
    string name;
};

Passenger q[MAX];
int front = -1, rear = -1;

void enqueue() {
    if (rear == MAX - 1) { cout << "Check-in line is full!\n"; return; }
    Passenger p;
    cout << "Enter Ticket No: "; cin >> p.ticket;
    cout << "Enter Passenger Name: "; cin >> p.name;
    if (front == -1) front = 0;
    q[++rear] = p;
    cout << "Passenger " << p.name << " joined check-in queue.\n";
}

void dequeue() {
    if (front == -1 || front > rear) { cout << "No passengers waiting!\n"; front = rear = -1; return; }
    cout << "Checked in: " << q[front].name << " (Ticket: " << q[front].ticket << ")\n";
    front++;
    if (front > rear) front = rear = -1;
}

void showFirstLast() {
    if (front == -1 || front > rear) { cout << "Queue is empty!\n"; return; }
    cout << "First in Line: " << q[front].name << "\n";
    cout << "Last in Line:  " << q[rear].name << "\n";
}

void display() {
    if (front == -1 || front > rear) { cout << "Queue is empty!\n"; return; }
    cout << "\n--- Airline Check-in Line ---\n";
    for (int i = front; i <= rear; i++) cout << (i - front + 1) << ". " << q[i].name << " (" << q[i].ticket << ")\n";
}

int main() {
        cout << "=====================================================\n";
    cout << "  SET 67: Airline Check-in Counter Queue Simulation\n";
    cout << "=====================================================\n";
int ch;
    do {
        cout << "\n--- Set 67: Airline Check-in Queue ---\n1. Enqueue Passenger\n2. Dequeue (Check-in)\n3. Display First & Last\n4. Display Complete Queue\n5. Exit\nEnter: ";
        cin >> ch;
        if (ch == 1) enqueue();
        else if (ch == 2) dequeue();
        else if (ch == 3) showFirstLast();
        else if (ch == 4) display();
    } while (ch != 5);
    return 0;
}

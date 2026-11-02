// Title: Set 23 - Amazon Warehouse Order Return Handling using Stack
// Problem Statement:
//   Simulate the order return handling of an
//   Amazon warehouse using a stack. Each
//   returned parcel has an Order ID, Product Name, and Price. Write functions to:
//   a. Push a newly returned parcel onto the stack (display “Stack Overflow” if the stack is full)
//   b. Pop the top parcel when it is processed and display its details (display “Stack Underflow” if
//   the stack is empty)
//   c. Peek and display the parcel currently on top of the stack without removing it
//   d. Display all parcels in the stack from top to bottom

#include <iostream>
#include <string>
using namespace std;

const int MAX = 5;

struct Parcel {
    int id;
    string name;
    float price;
};

Parcel stackArr[MAX];
int top = -1;

void push() {
    if (top >= MAX - 1) { cout << "Stack Overflow! Returned parcels stack is full.\n"; return; }
    Parcel p;
    cout << "Enter Order ID: "; cin >> p.id;
    cout << "Enter Product Name: "; cin >> p.name;
    cout << "Enter Price: "; cin >> p.price;
    stackArr[++top] = p;
    cout << "Parcel #" << p.id << " pushed onto stack!\n";
}

void pop() {
    if (top == -1) { cout << "Stack Underflow! No parcels to process.\n"; return; }
    Parcel p = stackArr[top--];
    cout << "Processed parcel: #" << p.id << " (" << p.name << ") - Rs. " << p.price << "\n";
}

void peek() {
    if (top == -1) { cout << "Stack is empty!\n"; return; }
    cout << "Top Parcel: #" << stackArr[top].id << " (" << stackArr[top].name << ")\n";
}

void display() {
    if (top == -1) { cout << "Stack is empty!\n"; return; }
    cout << "\n--- Returned Parcels Stack (Top to Bottom) ---\n";
    for (int i = top; i >= 0; i--) {
        cout << "#" << stackArr[i].id << "\t" << stackArr[i].name << "\tRs. " << stackArr[i].price << "\n";
    }
}

int main() {
int ch;
    do {
        cout << "\n--- Set 23: Warehouse Order Return Stack ---\n";
        cout << "1. Push Returned Parcel\n2. Pop Processed Parcel\n3. Peek Top Parcel\n4. Display All Parcels\n5. Exit\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
        }
    } while (ch != 5);
    return 0;
}

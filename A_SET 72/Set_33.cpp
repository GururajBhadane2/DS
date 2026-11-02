/*
================================================================================
Title: Set 33 - Amazon Warehouse Dispatch Processing using Stack
Problem Statement:
  Simulate the dispatch processing of an Amazon warehouse using a stack.
  Each parcel has a Parcel ID, Item Name, and Weight. Write functions to:
  a. Push a newly arrived parcel onto the stack (display "Stack Overflow" if full)
  b. Pop the parcel when dispatched and display its details (display "Stack Underflow" if empty)
  c. Peek and display the top parcel ready for dispatch
  d. Display all parcels currently in the stack
================================================================================
*/

#include <iostream>
#include <string>
using namespace std;

const int MAX = 10;
struct Item {
    int id;
    string name;
    float weight;
};

Item st[MAX];
int top = -1;

void push() {
    if (top >= MAX - 1) { cout << "Dispatch Stack Full!\n"; return; }
    Item item;
    cout << "Enter Item ID: "; cin >> item.id;
    cout << "Enter Name: "; cin >> item.name;
    cout << "Enter Weight (kg): "; cin >> item.weight;
    st[++top] = item;
    cout << "Item #" << item.id << " added to dispatch stack!\n";
}

void pop() {
    if (top == -1) { cout << "Stack Empty!\n"; return; }
    cout << "Dispatched: #" << st[top].id << " (" << st[top].name << ")\n";
    top--;
}

void display() {
    if (top == -1) { cout << "Empty!\n"; return; }
    for (int i = top; i >= 0; i--) cout << "#" << st[i].id << "\t" << st[i].name << "\t" << st[i].weight << "kg\n";
}

int main() {
        cout << "=====================================================\n";
    cout << "  SET 33: Amazon Warehouse Dispatch Processing using Stack\n";
    cout << "=====================================================\n";
int ch;
    do {
        cout << "\n--- Set 33: Warehouse Dispatch Stack ---\n1. Push Item\n2. Pop Dispatched\n3. Display\n4. Exit\nEnter: ";
        cin >> ch;
        if (ch == 1) push();
        else if (ch == 2) pop();
        else if (ch == 3) display();
    } while (ch != 4);
    return 0;
}

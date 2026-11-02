// Title: Set 38 - Bank Account Transaction Undo Stack Simulation
// Problem Statement:
//   Simulate the transaction history and Undo operation of a bank account using a stack. Write functions to:
//   a. Push a new transaction (Amount, Type: Deposit/Withdrawal) onto the stack
//   b. Undo (Pop) the last transaction and restore the previous balance
//   c. Display the most recent transaction (top of stack)
//   d. Display all past transactions in the stack

#include <iostream>
#include <string>
using namespace std;

const int MAX = 20;
struct Txn {
    int id;
    string type;
    float amount;
};

Txn st[MAX];
int top = -1;

void push() {
    if (top >= MAX - 1) return;
    Txn t;
    cout << "Enter Txn ID: "; cin >> t.id;
    cout << "Enter Type (Deposit/Withdraw): "; cin >> t.type;
    cout << "Enter Amount: "; cin >> t.amount;
    st[++top] = t;
    cout << "Recorded txn #" << t.id << "\n";
}

void undo() {
    if (top == -1) { cout << "Nothing to undo!\n"; return; }
    cout << "Undoing txn: #" << st[top].id << " (" << st[top].type << " Rs. " << st[top].amount << ")\n";
    top--;
}

int main() {
int ch;
    do {
        cout << "\n1. Add Transaction\n2. Undo Last\n3. Display\n4. Exit\nEnter: "; cin >> ch;
        if (ch == 1) push();
        else if (ch == 2) undo();
        else if (ch == 3) {
            for (int i = top; i >= 0; i--) cout << "#" << st[i].id << " " << st[i].type << " Rs." << st[i].amount << "\n";
        }
    } while (ch != 4);
    return 0;
}

#include <iostream>
#include <string>
using namespace std;

const int MAX = 50;

struct BillItem {
    string description;
    float amount;
};

BillItem billStack[MAX];
int top = -1;

// Push: Add a charge / fee item
void addItem() {
    if (top >= MAX - 1) {
        cout << "Bill limit reached!\n";
        return;
    }
    top++;
    cout << "Enter Item / Fee Name (e.g. Tuition, Exam, Library): ";
    cin >> billStack[top].description;
    cout << "Enter Amount: ";
    cin >> billStack[top].amount;
    cout << "Added: " << billStack[top].description << " (Rs. " << billStack[top].amount << ")\n";
}

// Pop: Undo last added fee item
void undoItem() {
    if (top == -1) {
        cout << "No items to undo!\n";
        return;
    }
    cout << "Undoing last entry: " << billStack[top].description 
         << " (Rs. " << billStack[top].amount << ")\n";
    top--;
}

// Display Bill and Total
void displayBill() {
    if (top == -1) {
        cout << "No items in bill!\n";
        return;
    }
    float total = 0;
    cout << "\n--- College Fee Receipt ---\n";
    cout << "Item\t\tAmount\n";
    cout << "---------------------------\n";
    for (int i = 0; i <= top; i++) {
        cout << billStack[i].description << "\t\tRs. " << billStack[i].amount << "\n";
        total += billStack[i].amount;
    }
    cout << "---------------------------\n";
    cout << "Total Payable:\tRs. " << total << "\n";
}

int main() {
    int choice;
    do {
        cout << "\n--- College Billing System (Stack Undo) ---\n";
        cout << "1. Add Fee Item (Push)\n";
        cout << "2. Undo Last Item (Pop)\n";
        cout << "3. Display Bill & Total\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addItem(); break;
            case 2: undoItem(); break;
            case 3: displayBill(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}

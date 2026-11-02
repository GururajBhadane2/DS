// Set 16 - Maintain Customer Bank Records using Array
// Maintain the records of N customers (Account No, Name, Balance) using an array. Write
// functions to:
// a. Insert a new customer at a given position
// b. Delete a customer by Account No
// c. Search a customer by Account No and display the record
// d. Display all customers

#include <iostream>
#include <string>
using namespace std;

struct Customer {
    int accNo;
    string name;
    float balance;
};

Customer custs[100];
int n = 0;

void insertCustomer() {
    if (n >= 100) { cout << "Array full!\n"; return; }
    int pos;
    cout << "Enter position (0 to " << n << "): "; cin >> pos;
    if (pos < 0 || pos > n) { cout << "Invalid position!\n"; return; }
    Customer c;
    cout << "Enter Account No: "; cin >> c.accNo;
    cout << "Enter Customer Name: "; cin >> c.name;
    cout << "Enter Balance: "; cin >> c.balance;
    for (int i = n; i > pos; i--) custs[i] = custs[i - 1];
    custs[pos] = c;
    n++;
    cout << "Customer inserted successfully!\n";
}

void deleteCustomer() {
    if (n == 0) { cout << "No customers to delete!\n"; return; }
    int acc, found = -1;
    cout << "Enter Account No to delete: "; cin >> acc;
    for (int i = 0; i < n; i++) {
        if (custs[i].accNo == acc) { found = i; break; }
    }
    if (found == -1) { cout << "Account No not found!\n"; return; }
    for (int i = found; i < n - 1; i++) custs[i] = custs[i + 1];
    n--;
    cout << "Customer deleted successfully!\n";
}

void searchCustomer() {
    int acc;
    cout << "Enter Account No to search: "; cin >> acc;
    for (int i = 0; i < n; i++) {
        if (custs[i].accNo == acc) {
            cout << "Found! Acc: " << custs[i].accNo << ", Name: " << custs[i].name << ", Balance: " << custs[i].balance << "\n";
            return;
        }
    }
    cout << "Customer not found!\n";
}

void display() {
    if (n == 0) { cout << "No customers available!\n"; return; }
    cout << "\nAcc No\tName\tBalance\n";
    for (int i = 0; i < n; i++) cout << custs[i].accNo << "\t" << custs[i].name << "\t" << custs[i].balance << "\n";
}

int main() {
int ch;
    do {
        cout << "\n--- Set 16: Customer Records (Array) ---\n";
        cout << "1. Insert Customer at Position\n2. Delete Customer by Acc No\n3. Search Customer by Acc No\n4. Display All\n5. Exit\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1: insertCustomer(); break;
            case 2: deleteCustomer(); break;
            case 3: searchCustomer(); break;
            case 4: display(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (ch != 5);
    return 0;
}

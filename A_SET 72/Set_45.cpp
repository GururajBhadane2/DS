/*
================================================================================
Title: Set 45 - Bank Transaction History Search using Linear Search
Problem Statement:
  Maintain the transaction history of a bank
  account (Transaction ID, Type, Amount). Write
  functions to:
  a. Read N transactions
  b. Search for a transaction by Transaction ID using linear search
  c. Display the position (index) and details of the transaction
  d. Display "Transaction not found" if absent
================================================================================
*/

#include <iostream>
#include <string>
using namespace std;

struct Txn {
    int id;
    string type;
    float amount;
};

int main() {
        cout << "=====================================================\n";
    cout << "  SET 45: Bank Transaction History Search using Linear Search\n";
    cout << "=====================================================\n";
int n;
    cout << "Enter number of transactions: "; cin >> n;
    Txn arr[100];
    for (int i = 0; i < n; i++) {
        cout << "Enter Txn ID, Type, Amount: ";
        cin >> arr[i].id >> arr[i].type >> arr[i].amount;
    }
    int target, found = -1;
    cout << "\nEnter Transaction ID to search: "; cin >> target;
    for (int i = 0; i < n; i++) {
        if (arr[i].id == target) { found = i; break; }
    }
    if (found != -1) {
        cout << "Found at index " << found << "! Type: " << arr[found].type << ", Amount: Rs." << arr[found].amount << "\n";
    } else {
        cout << "Transaction not found\n";
    }
    return 0;
}

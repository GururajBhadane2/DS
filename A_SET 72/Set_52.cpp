// Title: Set 52 - Warehouse Stock List Search with Batch Aggregation
// Problem Statement:
//   Maintain the stock list of a warehouse (Item
//   Code, Item Name, Quantity). Write functions to:
//   a. Read N items (item codes may repeat across batches)
//   b. Search by Item Code using linear search
//   c. Display all batches with that Item Code
//   d. Display the total quantity available for that Item Code

#include <iostream>
#include <string>
using namespace std;

struct Batch {
    string itemCode;
    string itemName;
    int qty;
};

int main() {
int n;
    cout << "Enter number of batch items: "; cin >> n;
    Batch arr[100];
    for (int i = 0; i < n; i++) {
        cout << "Enter Item Code, Item Name, Quantity: ";
        cin >> arr[i].itemCode >> arr[i].itemName >> arr[i].qty;
    }
    string target; int totalQty = 0, batchCount = 0;
    cout << "\nEnter Item Code to search: "; cin >> target;
    cout << "\nMatching Batches:\n";
    for (int i = 0; i < n; i++) {
        if (arr[i].itemCode == target) {
            cout << "Batch [" << i << "]: " << arr[i].itemName << " | Qty: " << arr[i].qty << "\n";
            totalQty += arr[i].qty;
            batchCount++;
        }
    }
    if (batchCount > 0) cout << "Total Available Quantity across all batches: " << totalQty << "\n";
    else cout << "Item Code not found in warehouse!\n";
    return 0;
}

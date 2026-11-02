// Set 54 - Bank Customer Records Lookup using Binary Search
// Maintain bank customer records (Account No,
// Name, Balance). Write functions to:
// a. Read N records and sort them by Account No
// b. Search an account using binary search
// c. Display the customer's record
// d. Display "Account not found" if absent

#include <iostream>
#include <string>
using namespace std;

struct Customer {
    int accNo;
    string name;
    float balance;
};

int main() {
int n;
    cout << "Enter number of customers: "; cin >> n;
    Customer arr[100];
    for (int i = 0; i < n; i++) {
        cout << "Enter Acc No, Name, Balance: ";
        cin >> arr[i].accNo >> arr[i].name >> arr[i].balance;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].accNo > arr[j + 1].accNo) {
                Customer t = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = t;
            }
        }
    }
    int target, low = 0, high = n - 1, found = -1;
    cout << "\nEnter Account No to search: "; cin >> target;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid].accNo == target) { found = mid; break; }
        else if (arr[mid].accNo < target) low = mid + 1;
        else high = mid - 1;
    }
    if (found != -1) cout << "Record Found: " << arr[found].name << " | Balance: Rs." << arr[found].balance << "\n";
    else cout << "Account not found\n";
    return 0;
}

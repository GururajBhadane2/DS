// Title: Set 49 - Hotel Guest Register Search using Linear Search
// Problem Statement:
//   Maintain the guest register of a hotel (Room
//   No, Guest Name, Days Stayed). Write functions to:
//   a. Read N guest records
//   b. Search for a guest by Name using linear search
//   c. Display the room number and days stayed
//   d. Display the position of the match in the register

#include <iostream>
#include <string>
using namespace std;

struct Guest {
    int roomNo;
    string name;
    int days;
};

int main() {
int n;
    cout << "Enter number of guests: "; cin >> n;
    Guest arr[100];
    for (int i = 0; i < n; i++) {
        cout << "Enter Room No, Guest Name, Days Stayed: ";
        cin >> arr[i].roomNo >> arr[i].name >> arr[i].days;
    }
    string target; int found = -1;
    cout << "\nEnter Guest Name to search: "; cin >> target;
    for (int i = 0; i < n; i++) {
        if (arr[i].name == target) { found = i; break; }
    }
    if (found != -1) {
        cout << "Guest Match Found at Position (Index): " << found << "\n";
        cout << "Room No: " << arr[found].roomNo << " | Days Stayed: " << arr[found].days << "\n";
    } else {
        cout << "Guest record not found!\n";
    }
    return 0;
}

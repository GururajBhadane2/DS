/*
================================================================================
Title: Set 51 - Phone Directory Search using Linear Search
Problem Statement:
  Maintain a phone directory (Name, Phone Number,
  City). Write functions to:
  a. Read N contacts
  b. Search a contact by Phone Number using linear search
  c. Display the contact details
  d. Display "Number not saved" if not found
================================================================================
*/

#include <iostream>
#include <string>
using namespace std;

struct Contact {
    string name;
    string phone;
    string city;
};

int main() {
        cout << "=====================================================\n";
    cout << "  SET 51: Phone Directory Search using Linear Search\n";
    cout << "=====================================================\n";
int n;
    cout << "Enter number of contacts: "; cin >> n;
    Contact arr[100];
    for (int i = 0; i < n; i++) {
        cout << "Enter Name, Phone Number, City: ";
        cin >> arr[i].name >> arr[i].phone >> arr[i].city;
    }
    string targetPhone; int found = -1;
    cout << "\nEnter Phone Number to search: "; cin >> targetPhone;
    for (int i = 0; i < n; i++) {
        if (arr[i].phone == targetPhone) { found = i; break; }
    }
    if (found != -1) {
        cout << "Contact Found: " << arr[found].name << " (" << arr[found].city << ")\n";
    } else {
        cout << "Number not saved\n";
    }
    return 0;
}

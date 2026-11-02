/*
================================================================================
Title: Set 50 - Railway Reservation List Search by PNR using Linear Search
Problem Statement:
  Maintain a railway reservation list (PNR,
  Passenger Name, Train No). Write functions to:
  a. Read N reservations
  b. Search by PNR using linear search
  c. Display the booking details if found
  d. Display the number of comparisons made
================================================================================
*/

#include <iostream>
#include <string>
using namespace std;

struct Booking {
    string pnr;
    string name;
    int trainNo;
};

int main() {
        cout << "=====================================================\n";
    cout << "  SET 50: Railway Reservation List Search by PNR using Linear Search\n";
    cout << "=====================================================\n";
int n;
    cout << "Enter number of reservations: "; cin >> n;
    Booking arr[100];
    for (int i = 0; i < n; i++) {
        cout << "Enter PNR, Passenger Name, Train No: ";
        cin >> arr[i].pnr >> arr[i].name >> arr[i].trainNo;
    }
    string target; int comps = 0, found = -1;
    cout << "\nEnter PNR to search: "; cin >> target;
    for (int i = 0; i < n; i++) {
        comps++;
        if (arr[i].pnr == target) { found = i; break; }
    }
    if (found != -1) {
        cout << "Booking Found! Passenger: " << arr[found].name << " | Train No: " << arr[found].trainNo << "\n";
    } else {
        cout << "Booking not found!\n";
    }
    cout << "Number of comparisons: " << comps << "\n";
    return 0;
}

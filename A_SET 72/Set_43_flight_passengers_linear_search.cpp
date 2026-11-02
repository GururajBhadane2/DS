// Title: Set 43 - Flight Passenger List Search using Linear Search
// Problem Statement:
//   Maintain the passenger list of a flight (Ticket
//   No, Name, Seat No). Write functions to:
//   a. Read the records of N passengers
//   b. Search a passenger by Name using linear search
//   c. Display the record if found, otherwise display "Passenger not found"
//   d. Display the number of comparisons made

#include <iostream>
#include <string>
using namespace std;

struct Passenger {
    string ticketNo;
    string name;
    string seatNo;
};

int main() {
int n;
    cout << "Enter number of passengers: "; cin >> n;
    Passenger arr[100];
    for (int i = 0; i < n; i++) {
        cout << "Enter Ticket No, Name, Seat No: ";
        cin >> arr[i].ticketNo >> arr[i].name >> arr[i].seatNo;
    }
    string target; int comps = 0, found = -1;
    cout << "\nEnter Passenger Name to search: "; cin >> target;
    for (int i = 0; i < n; i++) {
        comps++;
        if (arr[i].name == target) { found = i; break; }
    }
    if (found != -1) cout << "Record Found! Ticket: " << arr[found].ticketNo << ", Seat: " << arr[found].seatNo << "\n";
    else cout << "Passenger not found\n";
    cout << "Number of comparisons: " << comps << "\n";
    return 0;
}

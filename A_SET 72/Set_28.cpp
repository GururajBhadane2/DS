// Set 28 - Airline Flight Lookup System using Binary Search
// Simulate the flight lookup system of an airline
// using binary search. Each flight record
// has a Flight Number, Destination, and Departure Time. Write functions to:
// a. Read the flight records of N flights and sort them by Flight Number in ascending order
// b. Search for a flight by Flight Number using binary search
// c. Display the full flight record if found, otherwise display “Flight not found”
// d. Display the number of comparisons made during the search
// .

#include <iostream>
#include <string>
using namespace std;

struct Flight {
    int flightNo;
    string dest;
    string depTime;
};

Flight flights[100];
int n = 0;

void sortFlights() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (flights[j].flightNo > flights[j + 1].flightNo) {
                Flight temp = flights[j];
                flights[j] = flights[j + 1];
                flights[j + 1] = temp;
            }
        }
    }
}

void searchFlight(int target) {
    int low = 0, high = n - 1, comps = 0, foundIdx = -1;
    while (low <= high) {
        comps++;
        int mid = (low + high) / 2;
        if (flights[mid].flightNo == target) { foundIdx = mid; break; }
        else if (flights[mid].flightNo < target) low = mid + 1;
        else high = mid - 1;
    }
    if (foundIdx != -1) {
        cout << "\nFlight Found!\n";
        cout << "Flight No: " << flights[foundIdx].flightNo << "\n";
        cout << "Destination: " << flights[foundIdx].dest << "\n";
        cout << "Departure: " << flights[foundIdx].depTime << "\n";
    } else {
        cout << "\nFlight not found!\n";
    }
    cout << "Comparisons Made: " << comps << "\n";
}

int main() {
cout << "Enter number of flights: "; cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter Flight " << (i + 1) << " (No, Destination, DepartureTime): ";
        cin >> flights[i].flightNo >> flights[i].dest >> flights[i].depTime;
    }
    sortFlights();
    int target;
    cout << "\nEnter Flight Number to search: "; cin >> target;
    searchFlight(target);
    return 0;
}

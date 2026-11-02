// Title: Set 61 - Pin Code Directory Search using Binary Search
// Problem Statement:
//   Maintain a list of Pin Codes (Pin Code, Area,
//   City). Write functions to:
//   a. Read N entries and sort them by Pin Code
//   b. Search a Pin Code using binary search
//   c. Display the area and city
//   d. Display the number of comparisons made

#include <iostream>
#include <string>
using namespace std;

struct PinRecord {
    int pin;
    string area;
    string city;
};

int main() {
int n;
    cout << "Enter number of Pin Code entries: "; cin >> n;
    PinRecord arr[100];
    for (int i = 0; i < n; i++) {
        cout << "Enter Pin Code, Area, City: ";
        cin >> arr[i].pin >> arr[i].area >> arr[i].city;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].pin > arr[j + 1].pin) {
                PinRecord t = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = t;
            }
        }
    }
    int target, low = 0, high = n - 1, comps = 0, found = -1;
    cout << "\nEnter Pin Code to search: "; cin >> target;
    while (low <= high) {
        comps++;
        int mid = (low + high) / 2;
        if (arr[mid].pin == target) { found = mid; break; }
        else if (arr[mid].pin < target) low = mid + 1;
        else high = mid - 1;
    }
    if (found != -1) cout << "Location: " << arr[found].area << ", City: " << arr[found].city << "\n";
    else cout << "Pin Code not found!\n";
    cout << "Number of comparisons: " << comps << "\n";
    return 0;
}

// Title: Set 58 - Railway Timetable Lookup using Binary Search
// Problem Statement:
//   Maintain a railway timetable (Train No, Train Name, Departure Time). Write functions to:
//   a. Read N trains and sort them by Train No
//   b. Search a train using binary search
//   c. Display the train details if found
//   d. Display "Train not available" otherwise

#include <iostream>
#include <string>
using namespace std;

struct Train {
    int trainNo;
    string name;
    string depTime;
};

int main() {
int n;
    cout << "Enter number of trains: "; cin >> n;
    Train arr[100];
    for (int i = 0; i < n; i++) {
        cout << "Enter Train No, Train Name, Departure Time: ";
        cin >> arr[i].trainNo >> arr[i].name >> arr[i].depTime;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].trainNo > arr[j + 1].trainNo) {
                Train t = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = t;
            }
        }
    }
    int target, low = 0, high = n - 1, found = -1;
    cout << "\nEnter Train Number to search: "; cin >> target;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid].trainNo == target) { found = mid; break; }
        else if (arr[mid].trainNo < target) low = mid + 1;
        else high = mid - 1;
    }
    if (found != -1) cout << "Train Details: " << arr[found].name << " departing at " << arr[found].depTime << "\n";
    else cout << "Train not available\n";
    return 0;
}

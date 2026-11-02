// Set 60 - Hotel Room Directory Lookup using Binary Search
// Maintain hotel rooms (Room No, Type, Rate).
// Write functions to:
// a. Read N rooms sorted by Room No
// b. Search a room using binary search
// c. Display the room details and rate if found
// d. Display "Room does not exist" otherwise

#include <iostream>
#include <string>
using namespace std;

struct Room {
    int roomNo;
    string type;
    float rate;
};

int main() {
int n;
    cout << "Enter number of rooms (sorted by room number): "; cin >> n;
    Room arr[100];
    for (int i = 0; i < n; i++) {
        cout << "Enter Room No, Type (Deluxe/Standard), Rate: ";
        cin >> arr[i].roomNo >> arr[i].type >> arr[i].rate;
    }
    int target, low = 0, high = n - 1, found = -1;
    cout << "\nEnter Room No to search: "; cin >> target;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid].roomNo == target) { found = mid; break; }
        else if (arr[mid].roomNo < target) low = mid + 1;
        else high = mid - 1;
    }
    if (found != -1) cout << "Room Details: " << arr[found].type << " Room | Rate: Rs." << arr[found].rate << "/night\n";
    else cout << "Room does not exist\n";
    return 0;
}

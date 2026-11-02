// Title: Set 57 - Hospital Patient Records: Binary Search vs Linear Search
// Problem Statement:
//   Maintain hospital patient records (Patient
//   ID, Name, Age). Write functions to:
//   a. Read N patients and sort them by Patient ID
//   b. Search a patient using binary search
//   c. Display the record if found
//   d. Display the number of comparisons and compare it with linear search on the same data

#include <iostream>
#include <string>
using namespace std;

struct Patient {
    int id;
    string name;
    int age;
};

int main() {
int n;
    cout << "Enter number of patients: "; cin >> n;
    Patient arr[100];
    for (int i = 0; i < n; i++) {
        cout << "Enter Patient ID, Name, Age: ";
        cin >> arr[i].id >> arr[i].name >> arr[i].age;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].id > arr[j + 1].id) {
                Patient temp = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = temp;
            }
        }
    }
    int target;
    cout << "\nEnter Patient ID to search: "; cin >> target;
    // Linear search
    int linearComps = 0;
    for (int i = 0; i < n; i++) {
        linearComps++;
        if (arr[i].id == target) break;
    }
    // Binary search
    int low = 0, high = n - 1, bsComps = 0, found = -1;
    while (low <= high) {
        bsComps++;
        int mid = (low + high) / 2;
        if (arr[mid].id == target) { found = mid; break; }
        else if (arr[mid].id < target) low = mid + 1;
        else high = mid - 1;
    }
    if (found != -1) cout << "\nPatient Found: " << arr[found].name << " (Age: " << arr[found].age << ")\n";
    else cout << "\nPatient not found!\n";
    cout << "Linear Search Comparisons: " << linearComps << "\n";
    cout << "Binary Search Comparisons: " << bsComps << "\n";
    return 0;
}

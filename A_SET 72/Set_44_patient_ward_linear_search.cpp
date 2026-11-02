// Title: Set 44 - Hospital Patient Ward List Search with Duplicate Matching
// Problem Statement:
//   Maintain the records of N patients (Patient
//   ID, Name, Ward) in a hospital. Write functions to:
//   a. Read the patient records into an array
//   b. Search a patient by Name using linear search
//   c. Display all patients matching the given Name (names may repeat)
//   d. Display the total number of matches found

#include <iostream>
#include <string>
using namespace std;

struct Patient {
    int id;
    string name;
    string ward;
};

int main() {
int n;
    cout << "Enter number of patients: "; cin >> n;
    Patient arr[100];
    for (int i = 0; i < n; i++) {
        cout << "Enter Patient ID, Name, Ward: ";
        cin >> arr[i].id >> arr[i].name >> arr[i].ward;
    }
    string target;
    cout << "\nEnter Patient Name to search (can have multiple): "; cin >> target;
    int matches = 0;
    cout << "\nMatching Records:\n";
    for (int i = 0; i < n; i++) {
        if (arr[i].name == target) {
            cout << "ID: " << arr[i].id << " | Ward: " << arr[i].ward << "\n";
            matches++;
        }
    }
    cout << "Total number of matches found: " << matches << "\n";
    return 0;
}

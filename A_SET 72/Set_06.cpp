/*
================================================================================
Title: Set 06 - Maintain Patient Records using Array
Problem Statement:
  Maintain the records of N patients (Patient ID, Name, Age) using an array. Write functions to:
  a. Insert a new patient at a given position
  b. Delete a patient by Patient ID
  c. Search a patient by Patient ID and display the record
  d. Display all patients
================================================================================
*/

#include <iostream>
#include <string>
using namespace std;

struct Patient {
    int id;
    string name;
    int age;
};

Patient list[100];
int n = 0;

void insertPatient() {
    if (n >= 100) { cout << "Array full!\n"; return; }
    int pos;
    cout << "Enter position (0 to " << n << "): "; cin >> pos;
    if (pos < 0 || pos > n) { cout << "Invalid position!\n"; return; }
    Patient p;
    cout << "Enter Patient ID: "; cin >> p.id;
    cout << "Enter Name: "; cin >> p.name;
    cout << "Enter Age: "; cin >> p.age;
    for (int i = n; i > pos; i--) list[i] = list[i - 1];
    list[pos] = p;
    n++;
    cout << "Patient inserted successfully!\n";
}

void deletePatient() {
    if (n == 0) { cout << "No patients to delete!\n"; return; }
    int id, found = -1;
    cout << "Enter Patient ID to delete: "; cin >> id;
    for (int i = 0; i < n; i++) {
        if (list[i].id == id) { found = i; break; }
    }
    if (found == -1) { cout << "Patient ID not found!\n"; return; }
    for (int i = found; i < n - 1; i++) list[i] = list[i + 1];
    n--;
    cout << "Patient deleted successfully!\n";
}

void searchPatient() {
    int id;
    cout << "Enter Patient ID to search: "; cin >> id;
    for (int i = 0; i < n; i++) {
        if (list[i].id == id) {
            cout << "Found! ID: " << list[i].id << ", Name: " << list[i].name << ", Age: " << list[i].age << "\n";
            return;
        }
    }
    cout << "Patient not found!\n";
}

void display() {
    if (n == 0) { cout << "No patient records!\n"; return; }
    cout << "\nID\tName\tAge\n";
    for (int i = 0; i < n; i++) cout << list[i].id << "\t" << list[i].name << "\t" << list[i].age << "\n";
}

int main() {
        cout << "=====================================================\n";
    cout << "  SET 06: Maintain Patient Records using Array\n";
    cout << "=====================================================\n";
int ch;
    do {
        cout << "\n--- Set 6: Patient Records (Array) ---\n";
        cout << "1. Insert Patient at Position\n2. Delete Patient by ID\n3. Search Patient by ID\n4. Display All\n5. Exit\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1: insertPatient(); break;
            case 2: deletePatient(); break;
            case 3: searchPatient(); break;
            case 4: display(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (ch != 5);
    return 0;
}

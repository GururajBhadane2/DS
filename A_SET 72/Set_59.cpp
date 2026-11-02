/*
================================================================================
Title: Set 59 - Employee Records Lookup with Step Counting using Binary Search
Problem Statement:
  Maintain employee records (Employee ID, Name,
  Salary). Write functions to:
  a. Read N employees and sort them by Employee ID
  b. Search an employee using binary search
  c. Display the record if found
  d. Display the number of steps taken
================================================================================
*/

#include <iostream>
#include <string>
using namespace std;

struct Employee {
    int id;
    string name;
    float salary;
};

int main() {
        cout << "=====================================================\n";
    cout << "  SET 59: Employee Records Lookup with Step Counting using Binary Search\n";
    cout << "=====================================================\n";
int n;
    cout << "Enter number of employees: "; cin >> n;
    Employee arr[100];
    for (int i = 0; i < n; i++) {
        cout << "Enter Emp ID, Name, Salary: ";
        cin >> arr[i].id >> arr[i].name >> arr[i].salary;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].id > arr[j + 1].id) {
                Employee t = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = t;
            }
        }
    }
    int target, low = 0, high = n - 1, steps = 0, found = -1;
    cout << "\nEnter Employee ID to search: "; cin >> target;
    while (low <= high) {
        steps++;
        int mid = (low + high) / 2;
        if (arr[mid].id == target) { found = mid; break; }
        else if (arr[mid].id < target) low = mid + 1;
        else high = mid - 1;
    }
    if (found != -1) cout << "Employee Found: " << arr[found].name << " | Salary: Rs." << arr[found].salary << "\n";
    else cout << "Employee not found!\n";
    cout << "Number of steps taken: " << steps << "\n";
    return 0;
}

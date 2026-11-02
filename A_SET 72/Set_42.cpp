/*
================================================================================
Title: Set 42 - Employee Department Directory using Linear Search
Problem Statement:
  Maintain an employee department directory (Employee ID, Name, Department). Write functions to:
  a. Read N employee records into an array
  b. Search for an employee by Name using linear search
  c. Display all employee details matching the given Department
  d. Display the total number of comparisons made during the search
================================================================================
*/

#include <iostream>
#include <string>
using namespace std;

struct Employee {
    int id;
    string name;
    string dept;
};

int main() {
        cout << "=====================================================\n";
    cout << "  SET 42: Employee Department Directory using Linear Search\n";
    cout << "=====================================================\n";
int n;
    cout << "Enter number of employees: "; cin >> n;
    Employee arr[100];
    for (int i = 0; i < n; i++) {
        cout << "Enter Emp ID, Name, Dept: ";
        cin >> arr[i].id >> arr[i].name >> arr[i].dept;
    }
    string target; int comps = 0, found = -1;
    cout << "\nEnter Employee Name to search: "; cin >> target;
    for (int i = 0; i < n; i++) {
        comps++;
        if (arr[i].name == target) { found = i; break; }
    }
    if (found != -1) cout << "Employee Found! ID: " << arr[found].id << ", Dept: " << arr[found].dept << "\n";
    else cout << "Employee not found!\n";
    cout << "Number of comparisons: " << comps << "\n";
    return 0;
}

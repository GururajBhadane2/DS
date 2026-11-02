// Title: Set 41 - Student Course Registration using Linear Search
// Problem Statement:
//   Maintain the student course registration list (Roll No, Name, Course). Write functions to:
//   a. Read N student course registration records into an array
//   b. Search for a student by Roll No using linear search
//   c. Display the registration details if found, otherwise display "Student not found"
//   d. Display the total number of comparisons made during the search

#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    string course;
};

int main() {
int n;
    cout << "Enter number of students: "; cin >> n;
    Student arr[100];
    for (int i = 0; i < n; i++) {
        cout << "Enter ID, Name, Course: ";
        cin >> arr[i].id >> arr[i].name >> arr[i].course;
    }
    int target, comps = 0, found = -1;
    cout << "\nEnter Student ID to search: "; cin >> target;
    for (int i = 0; i < n; i++) {
        comps++;
        if (arr[i].id == target) { found = i; break; }
    }
    if (found != -1) cout << "Student Found! Name: " << arr[found].name << ", Course: " << arr[found].course << "\n";
    else cout << "Student not found!\n";
    cout << "Number of comparisons: " << comps << "\n";
    return 0;
}

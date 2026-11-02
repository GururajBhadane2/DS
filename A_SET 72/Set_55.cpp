// Title: Set 55 - Student Records Binary Search with Iteration Index Tracing
// Problem Statement:
//   Maintain student records (Roll No, Name,
//   CGPA). Write functions to:
//   a. Read N records already sorted by Roll No
//   b. Search a student by Roll No using binary search (iterative)
//   c. Display the record if found
//   d. Display the low, mid, and high index at every step

#include <iostream>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
    float cgpa;
};

int main() {
int n;
    cout << "Enter number of students (enter in sorted order of Roll No): "; cin >> n;
    Student arr[100];
    for (int i = 0; i < n; i++) {
        cout << "Enter Roll No, Name, CGPA: ";
        cin >> arr[i].roll >> arr[i].name >> arr[i].cgpa;
    }
    int target, low = 0, high = n - 1, found = -1;
    cout << "\nEnter Roll No to search: "; cin >> target;
    cout << "\nTracing Binary Search Steps:\n";
    cout << "Step\tLow\tMid\tHigh\tMid Value\n";
    int step = 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        cout << step++ << "\t" << low << "\t" << mid << "\t" << high << "\t" << arr[mid].roll << "\n";
        if (arr[mid].roll == target) { found = mid; break; }
        else if (arr[mid].roll < target) low = mid + 1;
        else high = mid - 1;
    }
    if (found != -1) cout << "\nStudent Found: " << arr[found].name << " (CGPA: " << arr[found].cgpa << ")\n";
    else cout << "\nStudent not found!\n";
    return 0;
}

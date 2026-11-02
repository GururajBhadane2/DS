// Title: Set 48 - Student Marks List Search & Frequency Counter
// Problem Statement:
//   Maintain the marks list of N students (Roll No, Name, Marks). Write functions to:
//   a. Read the student records
//   b. Search a student by Roll No using linear search
//   c. Display the student's record
//   d. Count and display how many students scored the same marks as the student found

#include <iostream>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
    float marks;
};

int main() {
int n;
    cout << "Enter number of students: "; cin >> n;
    Student arr[100];
    for (int i = 0; i < n; i++) {
        cout << "Enter Roll No, Name, Marks: ";
        cin >> arr[i].roll >> arr[i].name >> arr[i].marks;
    }
    int targetRoll, found = -1;
    cout << "\nEnter Roll No to search: "; cin >> targetRoll;
    for (int i = 0; i < n; i++) {
        if (arr[i].roll == targetRoll) { found = i; break; }
    }
    if (found != -1) {
        cout << "Found Student: " << arr[found].name << " with Marks: " << arr[found].marks << "\n";
        float targetMarks = arr[found].marks;
        int sameScoreCount = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i].marks == targetMarks) sameScoreCount++;
        }
        cout << "Total students with the exact same marks (" << targetMarks << "): " << sameScoreCount << "\n";
    } else {
        cout << "Student not found!\n";
    }
    return 0;
}

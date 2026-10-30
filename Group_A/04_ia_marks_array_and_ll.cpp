#include <iostream>
using namespace std;

// Maximum students
const int MAX = 100;

int rollNo[MAX];
float marks[MAX];
int n = 0;

// Add marks for a student
void addMarks() {
    if (n >= MAX) {
        cout << "Class limit reached!\n";
        return;
    }
    cout << "Enter Roll No: ";
    cin >> rollNo[n];
    cout << "Enter Internal Marks (out of 50): ";
    cin >> marks[n];
    n++;
    cout << "Marks added successfully!\n";
}

// Display all marks
void displayMarks() {
    if (n == 0) {
        cout << "No marks recorded!\n";
        return;
    }
    cout << "\n--- Student IA Marks ---\n";
    cout << "Roll No\tMarks\n";
    for (int i = 0; i < n; i++) {
        cout << rollNo[i] << "\t" << marks[i] << "\n";
    }
}

// Analyze marks (Max, Min, Average)
void analyzeMarks() {
    if (n == 0) {
        cout << "No data to analyze!\n";
        return;
    }
    float maxMarks = marks[0];
    float minMarks = marks[0];
    float sum = 0;
    int passCount = 0;

    for (int i = 0; i < n; i++) {
        if (marks[i] > maxMarks) maxMarks = marks[i];
        if (marks[i] < minMarks) minMarks = marks[i];
        sum += marks[i];
        if (marks[i] >= 20.0) passCount++; // passing criteria 40% of 50 = 20
    }

    cout << "\n--- Performance Analysis ---\n";
    cout << "Highest Marks: " << maxMarks << "\n";
    cout << "Lowest Marks:  " << minMarks << "\n";
    cout << "Average Marks: " << (sum / n) << "\n";
    cout << "Passed Students: " << passCount << " / " << n << "\n";
}

int main() {
    int choice;
    do {
        cout << "\n--- Internal Assessment (IA) Marks ---\n";
        cout << "1. Add Student Marks\n";
        cout << "2. Display All Marks\n";
        cout << "3. Analyze Marks (Highest, Lowest, Average)\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addMarks(); break;
            case 2: displayMarks(); break;
            case 3: analyzeMarks(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}

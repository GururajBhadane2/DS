#include <iostream>
#include <string>
using namespace std;

// Structure to store Student details
struct Student {
    int roll;
    string name;
    float marks;
};

// Global array and student count
Student s[100];
int n = 0;

// Function to insert a student
void insertStudent() {
    if (n >= 100) {
        cout << "Array is full!\n";
        return;
    }
    cout << "Enter Roll No: ";
    cin >> s[n].roll;
    cout << "Enter Name: ";
    cin >> s[n].name;
    cout << "Enter Marks: ";
    cin >> s[n].marks;
    n++;
    cout << "Student added successfully!\n";
}

// Function to delete a student by Roll No
void deleteStudent() {
    if (n == 0) {
        cout << "No students to delete!\n";
        return;
    }
    int roll, found = -1;
    cout << "Enter Roll No to delete: ";
    cin >> roll;

    for (int i = 0; i < n; i++) {
        if (s[i].roll == roll) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        cout << "Student not found!\n";
        return;
    }

    // Shift elements to the left
    for (int i = found; i < n - 1; i++) {
        s[i] = s[i + 1];
    }
    n--;
    cout << "Student deleted successfully!\n";
}

// Function to search a student by Roll No
void searchStudent() {
    if (n == 0) {
        cout << "List is empty!\n";
        return;
    }
    int roll;
    cout << "Enter Roll No to search: ";
    cin >> roll;

    for (int i = 0; i < n; i++) {
        if (s[i].roll == roll) {
            cout << "Found! Name: " << s[i].name << ", Marks: " << s[i].marks << "\n";
            return;
        }
    }
    cout << "Student not found!\n";
}

// Function to display all students
void display() {
    if (n == 0) {
        cout << "No students in the list!\n";
        return;
    }
    cout << "\n--- Student Records ---\n";
    cout << "Roll\tName\tMarks\n";
    for (int i = 0; i < n; i++) {
        cout << s[i].roll << "\t" << s[i].name << "\t" << s[i].marks << "\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n--- Student Database Menu ---\n";
        cout << "1. Insert Student\n";
        cout << "2. Delete Student\n";
        cout << "3. Search Student\n";
        cout << "4. Display All\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: insertStudent(); break;
            case 2: deleteStudent(); break;
            case 3: searchStudent(); break;
            case 4: display(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
};

// Linear Search by Roll No
int linearSearch(Student s[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (s[i].roll == target) {
            return i; // index found
        }
    }
    return -1;
}

// Bubble Sort helper by Roll No for Binary Search
void sortStudents(Student s[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].roll > s[j + 1].roll) {
                Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

// Binary Search by Roll No (requires sorted array)
int binarySearch(Student s[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (s[mid].roll == target) {
            return mid;
        } else if (s[mid].roll < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

void display(Student s[], int n) {
    cout << "\nRoll\tName\n";
    for (int i = 0; i < n; i++) {
        cout << s[i].roll << "\t" << s[i].name << "\n";
    }
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student s[100];
    for (int i = 0; i < n; i++) {
        cout << "Enter Roll No and Name for student " << (i + 1) << ": ";
        cin >> s[i].roll >> s[i].name;
    }

    int choice;
    do {
        cout << "\n--- Student Search Menu ---\n";
        cout << "1. Linear Search\n";
        cout << "2. Binary Search\n";
        cout << "3. Display All Students\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int roll;
            cout << "Enter Roll No to search: ";
            cin >> roll;
            int idx = linearSearch(s, n, roll);
            if (idx != -1) {
                cout << "Student Found! Name: " << s[idx].name << "\n";
            } else {
                cout << "Student not found!\n";
            }
        } else if (choice == 2) {
            sortStudents(s, n);
            cout << "Students sorted by Roll No for Binary Search.\n";
            int roll;
            cout << "Enter Roll No to search: ";
            cin >> roll;
            int idx = binarySearch(s, n, roll);
            if (idx != -1) {
                cout << "Student Found! Name: " << s[idx].name << "\n";
            } else {
                cout << "Student not found!\n";
            }
        } else if (choice == 3) {
            display(s, n);
        } else if (choice == 4) {
            cout << "Exiting...\n";
        } else {
            cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}

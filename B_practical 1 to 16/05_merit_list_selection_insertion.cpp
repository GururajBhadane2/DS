#include <iostream>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
    float marks;
};

// Selection Sort (Descending by marks)
void selectionSort(Student a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j].marks > a[maxIndex].marks) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            Student temp = a[i];
            a[i] = a[maxIndex];
            a[maxIndex] = temp;
        }
    }
}

// Insertion Sort (Descending by marks)
void insertionSort(Student a[], int n) {
    for (int i = 1; i < n; i++) {
        Student key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j].marks < key.marks) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void display(Student a[], int n) {
    cout << "\nRank\tRoll\tName\tMarks\n";
    for (int i = 0; i < n; i++) {
        cout << (i + 1) << "\t" << a[i].roll << "\t" << a[i].name << "\t" << a[i].marks << "\n";
    }
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student s[100];
    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << (i + 1) << ":\n";
        cout << "Enter Roll No: ";
        cin >> s[i].roll;
        cout << "Enter Name: ";
        cin >> s[i].name;
        cout << "Enter Marks: ";
        cin >> s[i].marks;
    }

    int choice;
    do {
        cout << "\n--- Merit List Sorting Menu ---\n";
        cout << "1. Selection Sort (Merit List)\n";
        cout << "2. Insertion Sort (Merit List)\n";
        cout << "3. Display Current List\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                selectionSort(s, n);
                cout << "\nSorted using Selection Sort:\n";
                display(s, n);
                break;
            case 2:
                insertionSort(s, n);
                cout << "\nSorted using Insertion Sort:\n";
                display(s, n);
                break;
            case 3:
                display(s, n);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    double cgpa;

public:
    Student() {
        name = "";
        rollNumber = 0;
        cgpa = 0.0;
    }

    void inputDetails(int id) {
        cout << "\nEnter details for Student " << id << ":\n";
        cout << "Name: ";
        cin.ignore(); 
        getline(cin, name);
        cout << "Roll Number: ";
        cin >> rollNumber;
        cout << "CGPA: ";
        cin >> cgpa;
    }
    void displayRow(int rank) const {
        cout << rank << "\t" 
             << rollNumber << "\t" 
             << cgpa << "\t" 
             << name << "\n";
    }

    double getCgpa() const {
        return cgpa;
    }
};
 
 
class MeritList {
private:
    Student* students;
    int size;

public:
    MeritList(int n) {
        size = n;
        students = new Student[size];
    }

    ~MeritList() {
        delete[] students;
    }

    void inputList() {
        for (int i = 0; i < size; i++) {
            students[i].inputDetails(i + 1);
        }
    }

    void selectionSortDescending() {
        for (int i = 0; i < size - 1; i++) {
            int max = i;
            
            for (int j = i + 1; j < size; j++) {
                if (students[j].getCgpa() > students[max].getCgpa()) {
                    max = j;
                }
            }
            
            if (max != i) {
                Student temp = students[i];
                students[i] = students[max];
                students[max] = temp;
            }
        }
    }
    void displayTopFive() const {
        cout << "Rank\tRoll No\tCGPA\tName\n";

        int limit = (size < 5) ? size : 5; 
        
        for (int i = 0; i < limit; i++) {
            students[i].displayRow(i + 1);
        }
        
        if (size < 5) {
            cout << "\n(less than 5 Student.)\n";
        }
    }
};

int main() {
    int totalStudents;

    cout << "Enter the total number of students: ";
    cin >> totalStudents;

    if (totalStudents <= 0) {
        cout << "Enter valid Number\n";
        return 0;
    }

    MeritList engineeringMeritList(totalStudents);
    engineeringMeritList.inputList();
    engineeringMeritList.selectionSortDescending();
    engineeringMeritList.displayTopFive();

    return 0;
}


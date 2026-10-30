#include <iostream>
#include <string>
#include <iomanip>

struct Student {
    int rollNo;
    std::string name;
    double cgpa;
};

class StudentInfoSystem {
private:
    Student students[100];
    int count;
    int capacity;

public:
    StudentInfoSystem(int cap = 100) : count(0), capacity(cap) {}

    // a. Insert a new student at a given position (0-based)
    void insertStudent(int position, int rollNo, const std::string& name, double cgpa) {
        if (count >= capacity) {
            std::cout << "Database Full! Cannot insert student.\n";
            return;
        }
        if (position < 0 || position > count) {
            std::cout << "Invalid position! Allowed: 0 to " << count << ".\n";
            return;
        }

        // Check for duplicate roll number
        for (int i = 0; i < count; ++i) {
            if (students[i].rollNo == rollNo) {
                std::cout << "Error: Student with Roll No " << rollNo << " already exists!\n";
                return;
            }
        }

        for (int i = count; i > position; --i) {
            students[i] = students[i - 1];
        }

        students[position] = {rollNo, name, cgpa};
        count++;
        std::cout << "Successfully inserted student [" << name << "] at position " << position << ".\n";
    }

    // b. Delete a student by roll number
    void deleteStudentByRollNo(int rollNo) {
        int index = -1;
        for (int i = 0; i < count; ++i) {
            if (students[i].rollNo == rollNo) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            std::cout << "Student with Roll No " << rollNo << " not found!\n";
            return;
        }

        std::string deletedName = students[index].name;
        for (int i = index; i < count - 1; ++i) {
            students[i] = students[i + 1];
        }
        count--;
        std::cout << "Successfully deleted student [" << deletedName << ", Roll: " << rollNo << "].\n";
    }

    // c. Search a student by roll number and display record
    void searchStudentByRollNo(int rollNo) const {
        for (int i = 0; i < count; ++i) {
            if (students[i].rollNo == rollNo) {
                std::cout << "\n--- Student Record Found ---\n";
                std::cout << "Index:    " << i << "\n";
                std::cout << "Roll No:  " << students[i].rollNo << "\n";
                std::cout << "Name:     " << students[i].name << "\n";
                std::cout << "CGPA:     " << std::fixed << std::setprecision(2) << students[i].cgpa << "\n";
                return;
            }
        }
        std::cout << "Student with Roll No " << rollNo << " was not found.\n";
    }

    // d. Display all students stored in the array
    void displayAll() const {
        if (count == 0) {
            std::cout << "No student records available.\n";
            return;
        }

        std::cout << "\n============================================================\n";
        std::cout << std::left << std::setw(8) << "Pos" 
                  << std::setw(12) << "Roll No" 
                  << std::setw(25) << "Student Name" 
                  << std::setw(10) << "CGPA" << "\n";
        std::cout << "------------------------------------------------------------\n";
        for (int i = 0; i < count; ++i) {
            std::cout << std::left << std::setw(8) << i
                      << std::setw(12) << students[i].rollNo
                      << std::setw(25) << students[i].name
                      << std::fixed << std::setprecision(2) << std::setw(10) << students[i].cgpa << "\n";
        }
        std::cout << "============================================================\n";
        std::cout << "Total Students: " << count << "\n\n";
    }
};

int main() {
    StudentInfoSystem sis;

    std::cout << "=== Student Information System (Array Based) ===\n";
    // a. Insert students
    sis.insertStudent(0, 101, "Aarav Sharma", 8.92);
    sis.insertStudent(1, 102, "Bhavna Patel", 9.15);
    sis.insertStudent(2, 104, "Devansh Joshi", 7.85);
    sis.insertStudent(2, 103, "Chirag Verma", 8.45); // insert at position 2

    // d. Display all
    sis.displayAll();

    // c. Search by roll number
    sis.searchStudentByRollNo(103);
    sis.searchStudentByRollNo(999);

    // b. Delete student by roll number
    sis.deleteStudentByRollNo(102);

    // d. Display updated list
    sis.displayAll();

    return 0;
}

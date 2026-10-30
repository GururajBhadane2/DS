#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

struct AcademicRecord {
    int rollNo;
    std::string name;
    std::string division;
};

// a. Linear search by Name
int linearSearchByName(const std::vector<AcademicRecord>& list, const std::string& targetName, int& comparisons) {
    comparisons = 0;
    for (size_t i = 0; i < list.size(); ++i) {
        comparisons++;
        if (list[i].name == targetName) {
            return i; // Found
        }
    }
    return -1; // Not found
}

// Helper to sort by roll number for binary search
void sortByRollNumber(std::vector<AcademicRecord>& list) {
    std::sort(list.begin(), list.end(), [](const AcademicRecord& a, const AcademicRecord& b) {
        return a.rollNo < b.rollNo;
    });
}

// b. Binary search by Roll Number
int binarySearchByRollNo(const std::vector<AcademicRecord>& sortedList, int targetRollNo, int& comparisons) {
    comparisons = 0;
    int left = 0;
    int right = sortedList.size() - 1;

    while (left <= right) {
        comparisons++;
        int mid = left + (right - left) / 2;

        if (sortedList[mid].rollNo == targetRollNo) {
            return mid;
        }
        if (sortedList[mid].rollNo < targetRollNo) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

void printRecord(const AcademicRecord& r) {
    std::cout << "  Roll No:  " << r.rollNo << "\n";
    std::cout << "  Name:     " << r.name << "\n";
    std::cout << "  Division: " << r.division << "\n";
}

int main() {
    std::vector<AcademicRecord> students = {
        {105, "Pooja Mehta", "Div A"},
        {102, "Rohan Deshmukh", "Div B"},
        {108, "Ananya Sen", "Div A"},
        {101, "Karan Singh", "Div C"},
        {104, "Sneha Nair", "Div B"},
        {107, "Vikram Malhotra", "Div A"},
        {103, "Aditi Roy", "Div C"}
    };

    std::cout << "=== Academic Office Student Directory ===\n";
    std::cout << std::left << std::setw(10) << "Roll No" 
              << std::setw(22) << "Name" 
              << std::setw(10) << "Division" << "\n";
    std::cout << "------------------------------------------\n";
    for (const auto& s : students) {
        std::cout << std::left << std::setw(10) << s.rollNo 
                  << std::setw(22) << s.name 
                  << std::setw(10) << s.division << "\n";
    }
    std::cout << "------------------------------------------\n\n";

    // a. Linear Search by Name
    std::cout << "--- 1. Linear Search by Name ---\n";
    std::string searchNames[] = {"Sneha Nair", "NonExistent Student"};
    for (const auto& name : searchNames) {
        int comparisons = 0;
        int idx = linearSearchByName(students, name, comparisons);
        std::cout << "Searching for \"" << name << "\":\n";
        if (idx != -1) {
            std::cout << ">> Found record at index " << idx << ":\n";
            printRecord(students[idx]);
        } else {
            std::cout << ">> Record not found.\n";
        }
        std::cout << ">> Number of comparisons made: " << comparisons << "\n\n";
    }

    // b. Binary Search by Roll Number (requires sorting first)
    std::cout << "--- 2. Binary Search by Roll Number (with sorting) ---\n";
    sortByRollNumber(students);
    std::cout << "Array sorted by Roll Number successfully.\n";

    int searchRolls[] = {104, 999};
    for (int rNo : searchRolls) {
        int comparisons = 0;
        int idx = binarySearchByRollNo(students, rNo, comparisons);
        std::cout << "Searching for Roll No " << rNo << ":\n";
        if (idx != -1) {
            std::cout << ">> Found record:\n";
            printRecord(students[idx]);
        } else {
            std::cout << ">> Record not found.\n";
        }
        std::cout << ">> Number of comparisons made: " << comparisons << "\n\n";
    }

    return 0;
}

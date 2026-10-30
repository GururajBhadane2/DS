#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

struct Student {
    int rollNo;
    std::string name;
    double cgpa;
};

void displayStudents(const std::vector<Student>& list, int limit = -1) {
    int count = (limit == -1 || limit > static_cast<int>(list.size())) ? list.size() : limit;
    std::cout << std::left << std::setw(6) << "Rank"
              << std::setw(12) << "Roll No"
              << std::setw(25) << "Student Name"
              << std::setw(10) << "CGPA" << "\n";
    std::cout << "---------------------------------------------------------\n";
    for (int i = 0; i < count; ++i) {
        std::cout << std::left << std::setw(6) << (i + 1)
                  << std::setw(12) << list[i].rollNo
                  << std::setw(25) << list[i].name
                  << std::fixed << std::setprecision(2) << std::setw(10) << list[i].cgpa << "\n";
    }
    std::cout << "---------------------------------------------------------\n";
}

// a. Selection sort for descending CGPA
void selectionSortDescending(std::vector<Student>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int maxIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j].cgpa > arr[maxIdx].cgpa) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            std::swap(arr[i], arr[maxIdx]);
        }
    }
}

// b. Insertion sort for descending CGPA and count number of shifts
int insertionSortDescending(std::vector<Student>& arr) {
    int n = arr.size();
    int shiftCount = 0;

    for (int i = 1; i < n; ++i) {
        Student key = arr[i];
        int j = i - 1;

        // Shift elements with smaller CGPA to the right
        while (j >= 0 && arr[j].cgpa < key.cgpa) {
            arr[j + 1] = arr[j];
            shiftCount++;
            j--;
        }
        arr[j + 1] = key;
    }
    return shiftCount;
}

int main() {
    std::vector<Student> rawData = {
        {101, "Aarav Sharma", 8.45},
        {102, "Bhavna Patel", 9.60},
        {103, "Chirag Verma", 7.80},
        {104, "Devansh Joshi", 9.15},
        {105, "Esha Rao", 9.85},
        {106, "Farhan Khan", 8.90},
        {107, "Gauri Kulkarni", 9.35},
        {108, "Harsh Vardhan", 7.50}
    };

    std::cout << "=== Original Student Records ===\n";
    displayStudents(rawData);

    // a. Selection Sort descending
    std::vector<Student> list1 = rawData;
    selectionSortDescending(list1);
    std::cout << "\n=== Full Merit List (Sorted using Selection Sort Descending) ===\n";
    displayStudents(list1);

    // b. Insertion Sort descending with shift count
    std::vector<Student> list2 = rawData;
    int shifts = insertionSortDescending(list2);
    std::cout << "\nInsertion Sort executed successfully.\n";
    std::cout << "Total number of data shifts performed: " << shifts << "\n";

    // c. Display Top 5 students
    std::cout << "\n=========================================================\n";
    std::cout << "              TOP 5 MERIT SCHOLARSHIP AWARDEES           \n";
    std::cout << "=========================================================\n";
    displayStudents(list2, 5);

    return 0;
}

#include <iostream>
#include <iomanip>
#include <cctype>

struct AttendanceNode {
    int day;
    char status; // 'P' or 'A'
    AttendanceNode* next;

    AttendanceNode(int d, char s) : day(d), status(std::toupper(s)), next(nullptr) {}
};

class AttendanceTracker {
private:
    AttendanceNode* head;
    int totalDays;

public:
    AttendanceTracker() : head(nullptr), totalDays(0) {}

    ~AttendanceTracker() {
        AttendanceNode* curr = head;
        while (curr) {
            AttendanceNode* temp = curr->next;
            delete curr;
            curr = temp;
        }
    }

    // a. Insert attendance (P/A) at the end of the list
    void insertAttendance(char status) {
        char s = std::toupper(status);
        if (s != 'P' && s != 'A') {
            std::cout << "Invalid status! Use 'P' for Present or 'A' for Absent.\n";
            return;
        }

        totalDays++;
        AttendanceNode* newNode = new AttendanceNode(totalDays, s);

        if (!head) {
            head = newNode;
        } else {
            AttendanceNode* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        std::cout << "Marked Day " << totalDays << ": " << (s == 'P' ? "Present" : "Absent") << ".\n";
    }

    // b. Update the attendance of a given day
    void updateAttendance(int day, char newStatus) {
        char s = std::toupper(newStatus);
        if (s != 'P' && s != 'A') {
            std::cout << "Invalid status! Use 'P' or 'A'.\n";
            return;
        }

        AttendanceNode* curr = head;
        while (curr) {
            if (curr->day == day) {
                char oldStatus = curr->status;
                curr->status = s;
                std::cout << "Updated Day " << day << " status from " << oldStatus << " to " << s << ".\n";
                return;
            }
            curr = curr->next;
        }
        std::cout << "Day " << day << " not found in attendance record.\n";
    }

    // c. Calculate total number of Present and Absent days
    void calculateAttendanceSummary(int& presentCount, int& absentCount, double& percentage) const {
        presentCount = 0;
        absentCount = 0;
        AttendanceNode* curr = head;

        while (curr) {
            if (curr->status == 'P') presentCount++;
            else if (curr->status == 'A') absentCount++;
            curr = curr->next;
        }

        if (totalDays > 0) {
            percentage = (static_cast<double>(presentCount) / totalDays) * 100.0;
        } else {
            percentage = 0.0;
        }
    }

    // d. Display the complete attendance list
    void displayAttendance() const {
        if (!head) {
            std::cout << "No attendance records available.\n";
            return;
        }

        std::cout << "\n=========================================\n";
        std::cout << "          Daily Attendance Log           \n";
        std::cout << "=========================================\n";
        std::cout << std::left << std::setw(10) << "Day" << std::setw(15) << "Status" << "\n";
        std::cout << "-----------------------------------------\n";

        AttendanceNode* curr = head;
        while (curr) {
            std::cout << std::left << std::setw(10) << ("Day " + std::to_string(curr->day))
                      << std::setw(15) << (curr->status == 'P' ? "Present [P]" : "Absent  [A]") << "\n";
            curr = curr->next;
        }
        std::cout << "-----------------------------------------\n";

        int p = 0, a = 0;
        double pct = 0.0;
        calculateAttendanceSummary(p, a, pct);
        std::cout << "Total Days: " << totalDays 
                  << " | Present: " << p 
                  << " | Absent: " << a 
                  << " | Percentage: " << std::fixed << std::setprecision(2) << pct << "%\n";
        std::cout << "=========================================\n\n";
    }
};

int main() {
    AttendanceTracker tracker;

    std::cout << "=== Student Attendance Tracking System (SLL) ===\n";
    // a. Insert attendance
    tracker.insertAttendance('P');
    tracker.insertAttendance('P');
    tracker.insertAttendance('A');
    tracker.insertAttendance('P');
    tracker.insertAttendance('A');
    tracker.insertAttendance('P');
    tracker.insertAttendance('P');

    // d. Display attendance
    tracker.displayAttendance();

    // b. Update attendance for Day 3 (from A to P)
    tracker.updateAttendance(3, 'P');

    // d. Display updated attendance & calculation
    tracker.displayAttendance();

    return 0;
}

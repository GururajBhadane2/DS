#include <iostream>
#include <string>
#include <deque>
#include <iomanip>

/*
 * Student Service Desk Using Deque:
 * a. Add emergency cases at front
 * b. Add normal cases at rear
 * c. Serve from front
 * d. Display deque after each operation
 */

struct ServiceRequest {
    int ticketId;
    std::string studentName;
    std::string issueDescription;
    bool isEmergency;
};

class StudentServiceDesk {
private:
    std::deque<ServiceRequest> deskQueue;
    int nextTicketId;

public:
    StudentServiceDesk() : nextTicketId(101) {}

    // a. Add emergency cases at front
    void addEmergencyRequest(const std::string& name, const std::string& issue) {
        ServiceRequest req = {nextTicketId++, name, issue, true};
        deskQueue.push_front(req);
        std::cout << "[EMERGENCY ADDED TO FRONT] Ticket #" << req.ticketId 
                  << " (" << name << ": " << issue << ")\n";
        displayDeque();
    }

    // b. Add normal cases at rear
    void addNormalRequest(const std::string& name, const std::string& issue) {
        ServiceRequest req = {nextTicketId++, name, issue, false};
        deskQueue.push_back(req);
        std::cout << "[NORMAL CASE ADDED TO REAR] Ticket #" << req.ticketId 
                  << " (" << name << ": " << issue << ")\n";
        displayDeque();
    }

    // c. Serve from front
    void serveRequest() {
        if (deskQueue.empty()) {
            std::cout << "Service Desk is free! No pending requests.\n";
            return;
        }
        ServiceRequest served = deskQueue.front();
        deskQueue.pop_front();

        std::cout << "\n>>> SERVING TICKET #" << served.ticketId << " (" 
                  << (served.isEmergency ? "EMERGENCY" : "NORMAL") << ") <<<\n";
        std::cout << "    Student: " << served.studentName << "\n";
        std::cout << "    Issue:   " << served.issueDescription << "\n\n";

        displayDeque();
    }

    // d. Display deque after each operation
    void displayDeque() const {
        if (deskQueue.empty()) {
            std::cout << "Service Desk Deque is currently empty.\n\n";
            return;
        }

        std::cout << "---------------- Current Service Desk Queue ----------------\n";
        std::cout << std::left << std::setw(10) << "Position"
                  << std::setw(12) << "Ticket #"
                  << std::setw(14) << "Type"
                  << std::setw(20) << "Student Name"
                  << std::setw(30) << "Issue" << "\n";
        std::cout << "------------------------------------------------------------\n";
        int pos = 1;
        for (const auto& req : deskQueue) {
            std::cout << std::left << std::setw(10) << (pos == 1 ? "FRONT (1)" : std::to_string(pos))
                      << std::setw(12) << ("#" + std::to_string(req.ticketId))
                      << std::setw(14) << (req.isEmergency ? "[EMERGENCY]" : "[NORMAL]")
                      << std::setw(20) << req.studentName
                      << std::setw(30) << req.issueDescription << "\n";
            pos++;
        }
        std::cout << "------------------------------------------------------------\n\n";
    }
};

int main() {
    StudentServiceDesk desk;

    std::cout << "=== Student Help & Service Desk (Deque System) ===\n\n";

    // b. Add normal cases at rear
    desk.addNormalRequest("Aarav", "Fee receipt photocopy required");
    desk.addNormalRequest("Bhavna", "Bonafide certificate application");

    // a. Add emergency cases at front
    desk.addEmergencyRequest("Dr. Sharma (Faculty)", "Urgent exam hall ticket discrepancy");

    // b. Add another normal case
    desk.addNormalRequest("Chirag", "Library card lost report");

    // a. Add another emergency case
    desk.addEmergencyRequest("Pooja", "Medical emergency leave submission");

    // c. Serve requests from front
    desk.serveRequest();
    desk.serveRequest();

    return 0;
}

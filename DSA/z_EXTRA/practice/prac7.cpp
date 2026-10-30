#include <iostream>
#include <string>

using namespace std;

// --- STRUCTURES & CONSTANTS ---
#define MAX_FLEET 5
#define STACK_SIZE 10
#define MAX_RECORDS 100

struct Incident {
    int id;
    string description;
    Incident* next;
    Incident* prev;
};

struct IncidentRecord {
    int id;
    string description;
};

// --- MODULE 1: Action Log (Stack) ---
class ActionLog {
private:
    int undoStack[STACK_SIZE];
    int top;
public:
    ActionLog() { top = -1; }
    void logAction(int incidentID) {
        if (top >= STACK_SIZE - 1) return;
        undoStack[++top] = incidentID;
    }
    int undoLastAction() {
        if (top < 0) return -1;
        return undoStack[top--];
    }
};

// --- MODULE 2: Fleet Management (Circular Queue) ---
class FleetManager {
private:
    int fleet[MAX_FLEET];
    int front, rear, activeCount;
public:
    FleetManager() { front = -1; rear = -1; activeCount = 0; }
    
    void addUnit(int unitID) {
        if (activeCount == MAX_FLEET) {
            cout << "[WARNING] Fleet capacity is full.\n";
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX_FLEET;
        fleet[rear] = unitID;
        activeCount++;
        cout << "[FLEET] Unit #" << unitID << " added to rotation.\n";
    }

    int deployNextUnit() {
        if (activeCount == 0) return -1;
        int deployedID = fleet[front];
        front = (front + 1) % MAX_FLEET;
        activeCount--;
        return deployedID;
    }
};

// --- MODULE 3: Incident Triage (Deque) ---
class DispatchDeque {
private:
    Incident* front;
    Incident* rear;
public:
    DispatchDeque() { front = rear = nullptr; }

    void addEmergency(int id, string desc) {
        Incident* newIncident = new Incident{id, desc, nullptr, nullptr};
        if (!front) {
            front = rear = newIncident;
        } else {
            newIncident->next = front;
            front->prev = newIncident;
            front = newIncident;
        }
        cout << "\n[CRITICAL] Emergency Incident #" << id << " added to FRONT.\n";
    }

    void addNormal(int id, string desc) {
        Incident* newIncident = new Incident{id, desc, nullptr, nullptr};
        if (!rear) {
            front = rear = newIncident;
        } else {
            newIncident->prev = rear;
            rear->next = newIncident;
            rear = newIncident;
        }
        cout << "\n[INFO] Normal Incident #" << id << " added to REAR.\n";
    }

    // Removes an incident if it was undone via Stack
    void removeIncident(int targetID) {
        Incident* temp = front;
        while (temp) {
            if (temp->id == targetID) {
                if (temp->prev) temp->prev->next = temp->next;
                else front = temp->next;
                if (temp->next) temp->next->prev = temp->prev;
                else rear = temp->prev;
                delete temp;
                cout << "[UNDO] Successfully removed Incident #" << targetID << " from queue.\n";
                return;
            }
            temp = temp->next;
        }
    }

    Incident* getNextDispatch() {
        if (!front) return nullptr;
        Incident* temp = front;
        front = front->next;
        if (front) front->prev = nullptr;
        else rear = nullptr;
        return temp;
    }
    
    void displayPending() {
        if (!front) { cout << "\n[STATUS] Queue is empty.\n"; return; }
        Incident* temp = front;
        cout << "\n--- Pending Incidents ---\n";
        while (temp) {
            cout << "ID: " << temp->id << " | Desc: " << temp->description << "\n";
            temp = temp->next;
        }
        cout << "-------------------------\n";
    }
};

// --- MODULE 4: Historical Records (Quick Sort & Binary Search) ---
class RecordArchive {
public:
    int partition(IncidentRecord arr[], int low, int high) {
        int pivot = arr[high].id;
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (arr[j].id < pivot) {
                i++;
                swap(arr[i].id, arr[j].id);
                swap(arr[i].description, arr[j].description);
            }
        }
        swap(arr[i + 1].id, arr[high].id);
        swap(arr[i + 1].description, arr[high].description);
        return (i + 1);
    }

    void quickSort(IncidentRecord arr[], int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    void binarySearch(IncidentRecord arr[], int low, int high, int targetID) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid].id == targetID) {
                cout << "\n[ARCHIVE RECORD FOUND] ID: " << arr[mid].id << " | Desc: " << arr[mid].description << "\n";
                return;
            }
            if (arr[mid].id < targetID) low = mid + 1;
            else high = mid - 1;
        }
        cout << "\n[ARCHIVE] Record ID " << targetID << " not found.\n";
    }
};

// --- MAIN TERMINAL ENGINE ---
int main() {
    DispatchDeque deque;
    FleetManager fleet;
    ActionLog log;
    RecordArchive archive;
    
    IncidentRecord archiveArray[MAX_RECORDS];
    int archiveCount = 0;

    int choice, id, unitID;
    string desc;

    // Pre-load some fleet vehicles
    fleet.addUnit(101);
    fleet.addUnit(102);

    while (true) {
        cout << "\n=== SMART CITY DISPATCH TERMINAL ===\n";
        cout << "1. Log Emergency Call (Priority Front)\n";
        cout << "2. Log Normal Call (Standard Rear)\n";
        cout << "3. Dispatch Available Unit\n";
        cout << "4. Undo Last Logged Call\n";
        cout << "5. View Pending Queue\n";
        cout << "6. End of Day: Sort & Search Archive\n";
        cout << "7. Exit\n";
        cout << "Enter command: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Incident ID: "; cin >> id;
                cout << "Enter Description: "; cin.ignore(); getline(cin, desc);
                deque.addEmergency(id, desc);
                log.logAction(id);
                break;
            case 2:
                cout << "Enter Incident ID: "; cin >> id;
                cout << "Enter Description: "; cin.ignore(); getline(cin, desc);
                deque.addNormal(id, desc);
                log.logAction(id);
                break;
            case 3: {
                int dispatchedUnit = fleet.deployNextUnit();
                if (dispatchedUnit == -1) {
                    cout << "\n[ALERT] No vehicles available for dispatch!\n";
                    break;
                }
                Incident* current = deque.getNextDispatch();
                if (current) {
                    cout << "\n[DISPATCHING] Vehicle #" << dispatchedUnit 
                         << " is responding to Incident #" << current->id << " (" << current->description << ")\n";
                    // Add to archive
                    archiveArray[archiveCount].id = current->id;
                    archiveArray[archiveCount].description = current->description;
                    archiveCount++;
                    delete current;
                } else {
                    cout << "\n[STATUS] No pending incidents to dispatch.\n";
                    fleet.addUnit(dispatchedUnit); // Return unit to fleet if no incident
                }
                break;
            }
            case 4: {
                int undoneID = log.undoLastAction();
                if (undoneID != -1) deque.removeIncident(undoneID);
                else cout << "\n[ERROR] No actions to undo.\n";
                break;
            }
            case 5:
                deque.displayPending();
                break;
            case 6: {
                if (archiveCount == 0) {
                    cout << "\n[ARCHIVE] No records to sort.\n";
                    break;
                }
                archive.quickSort(archiveArray, 0, archiveCount - 1);
                cout << "\n[ARCHIVE] " << archiveCount << " records successfully sorted using Quick Sort.\n";
                
                cout << "Enter an Incident ID to search for: "; cin >> id;
                archive.binarySearch(archiveArray, 0, archiveCount - 1, id);
                break;
            }
            case 7:
                cout << "Exiting terminal...\n";
                return 0;
            default:
                cout << "Invalid command.\n";
        }
    }
    return 0;
}
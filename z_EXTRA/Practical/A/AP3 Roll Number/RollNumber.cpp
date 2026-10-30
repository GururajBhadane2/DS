#include <iostream>
#include <string>

using namespace std;


struct StudentNode {
    int rollNo;
    string name;
    StudentNode* prev;
    StudentNode* next;

    StudentNode(int r, const string& n) : rollNo(r), name(n), prev(nullptr), next(nullptr) {}
};


class StudentDoublyLinkedList {
private:
    StudentNode* head;
    StudentNode* tail;

public:
    StudentDoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~StudentDoublyLinkedList() {
        StudentNode* current = head;
        while (current != nullptr) {
            StudentNode* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void insertSorted(int rollNo, const string& name) {
        StudentNode* check = head;
        while (check != nullptr) {
            if (check->rollNo == rollNo) {
                cout << "[Error] Roll number " << rollNo << " already exists!\n";
                return;
            }
            check = check->next;
        }

        StudentNode* newNode = new StudentNode(rollNo, name);

        if (head == nullptr) {
            head = tail = newNode;
            cout << "[Success] Inserted Roll No " << rollNo << " (" << name << ")\n";
            return;
        }

        if (rollNo < head->rollNo) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            cout << "[Success] Inserted Roll No " << rollNo << " (" << name << ")\n";
            return;
        }

        // Case 3: Insert in middle or at tail
        StudentNode* current = head;
        while (current->next != nullptr && current->next->rollNo < rollNo) {
            current = current->next;
        }

        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != nullptr) {
            current->next->prev = newNode; // Inserting in the middle
        } else {
            tail = newNode; // Inserting at the end, update tail pointer
        }

        current->next = newNode;
        cout << "[Success] Inserted Roll No " << rollNo << " (" << name << ")\n";
    }



    void deleteByRollNo(int rollNo) {
        if (head == nullptr) {
            cout << "[Error] List is empty. Cannot delete.\n";
            return;
        }

        StudentNode* current = head;
        while (current != nullptr && current->rollNo != rollNo) {
            current = current->next;
        }



        if (current == nullptr) {
            cout << "[Error] Roll number " << rollNo << " not found in the list.\n";
            return;
        }

        
        if (current == head && current == tail) {
            head = tail = nullptr;
        }
        
        else if (current == head) {
            head = head->next;
            head->prev = nullptr;
        }
        
        else if (current == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        
        else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }

        cout << "[Success] Deleted Roll No " << rollNo << " (" << current->name << ")\n";
        delete current;
    }


    void displayForward() const {
        if (head == nullptr) {
            cout << "\n--- Student List is Empty ---\n";
            return;
        }

        cout << "\n=========================================\n";
        cout << "  Student List (Forward - Ascending Roll)\n";
        cout << "=========================================\n";
        StudentNode* current = head;
        while (current != nullptr) {
            cout << "Roll No: " << current->rollNo << " | Name: " << current->name << "\n";
            current = current->next;
        }
        cout << "=========================================\n";
    }


    void displayBackward() const {
        if (tail == nullptr) {
            cout << "\n--- Student List is Empty ---\n";
            return;
        }

        cout << "\n=========================================\n";
        cout << " Student List (Backward - Descending Roll)\n";
        cout << "=========================================\n";
        StudentNode* current = tail;
        while (current != nullptr) {
            cout << "Roll No: " << current->rollNo << " | Name: " << current->name << "\n";
            current = current->prev;
        }
        cout << "=========================================\n";
    }
};

int main() {
    StudentDoublyLinkedList list;

    // --- Demonstration of Operations ---
    
 
    cout << "--- 1. INSERTION TEST ---\n";
    list.insertSorted(104, "Alice");
    list.insertSorted(101, "Bob");
    list.insertSorted(105, "Charlie");
    list.insertSorted(102, "David");
    list.insertSorted(103, "Eve");

 
    list.displayForward();

 
    list.displayBackward();

 
    cout << "\n--- 2. DELETION TEST ---\n";
    list.deleteByRollNo(101); // Delete Head
    list.deleteByRollNo(105); // Delete Tail
    list.deleteByRollNo(103); // Delete Middle
    list.deleteByRollNo(999); // Try deleting non-existent roll no

 
    list.displayForward();
    list.displayBackward();

    return 0;
}

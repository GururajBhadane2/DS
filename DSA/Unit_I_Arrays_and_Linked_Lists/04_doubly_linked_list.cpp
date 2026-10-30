#include <iostream>

struct DNode {
    int data;
    DNode* prev;
    DNode* next;

    DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    DNode* head;
    DNode* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        DNode* curr = head;
        while (curr) {
            DNode* temp = curr->next;
            delete curr;
            curr = temp;
        }
    }

    void insertAtHead(int val) {
        DNode* newNode = new DNode(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        std::cout << "Inserted " << val << " at head.\n";
    }

    void insertAtTail(int val) {
        DNode* newNode = new DNode(val);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        std::cout << "Inserted " << val << " at tail.\n";
    }

    void deleteByValue(int val) {
        if (!head) {
            std::cout << "List is empty.\n";
            return;
        }
        DNode* curr = head;
        while (curr && curr->data != val) {
            curr = curr->next;
        }
        if (!curr) {
            std::cout << "Element " << val << " not found.\n";
            return;
        }
        if (curr == head) {
            head = head->next;
            if (head) head->prev = nullptr;
            else tail = nullptr;
        } else if (curr == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }
        delete curr;
        std::cout << "Deleted " << val << " from DLL.\n";
    }

    void displayForward() const {
        std::cout << "Forward Traversal:  ";
        DNode* curr = head;
        while (curr) {
            std::cout << curr->data << " <-> ";
            curr = curr->next;
        }
        std::cout << "NULL\n";
    }

    void displayBackward() const {
        std::cout << "Backward Traversal: ";
        DNode* curr = tail;
        while (curr) {
            std::cout << curr->data << " <-> ";
            curr = curr->prev;
        }
        std::cout << "NULL\n";
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertAtHead(20);
    dll.insertAtHead(10);
    dll.insertAtTail(30);
    dll.insertAtTail(40);

    dll.displayForward();
    dll.displayBackward();

    dll.deleteByValue(20);
    dll.displayForward();
    dll.displayBackward();

    return 0;
}

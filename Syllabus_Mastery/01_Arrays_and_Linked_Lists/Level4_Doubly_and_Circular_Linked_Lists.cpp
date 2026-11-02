#include <iostream>

/*
 * LEVEL 4 (INTERMEDIATE/ADVANCED): Doubly and Circular Linked Lists
 * Demonstrates: 2-way traversal in DLL, and end-to-head cycle traversal in CLL.
 */

// --- Doubly Linked List ---
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
public:
    DNode* head;
    DNode* tail;
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insertEnd(int val) {
        DNode* n = new DNode(val);
        if (!head) { head = tail = n; return; }
        tail->next = n;
        n->prev = tail;
        tail = n;
    }

    void displayForward() const {
        std::cout << "DLL Forward:  ";
        DNode* cur = head;
        while (cur) { std::cout << cur->data << " <-> "; cur = cur->next; }
        std::cout << "NULL\n";
    }

    void displayBackward() const {
        std::cout << "DLL Backward: ";
        DNode* cur = tail;
        while (cur) { std::cout << cur->data << " <-> "; cur = cur->prev; }
        std::cout << "NULL\n";
    }
};

// --- Circular Linked List ---
struct CNode {
    int data;
    CNode* next;
    CNode(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
public:
    CNode* head;
    CircularLinkedList() : head(nullptr) {}

    void insertEnd(int val) {
        CNode* n = new CNode(val);
        if (!head) {
            head = n;
            n->next = head;
            return;
        }
        CNode* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = n;
        n->next = head;
    }

    void display() const {
        if (!head) return;
        std::cout << "CLL: ";
        CNode* temp = head;
        do {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        std::cout << "(back to head " << head->data << ")\n";
    }
};

int main() {
    std::cout << "=== Doubly Linked List ===\n";
    DoublyLinkedList dll;
    dll.insertEnd(10);
    dll.insertEnd(20);
    dll.insertEnd(30);
    dll.displayForward();
    dll.displayBackward();

    std::cout << "\n=== Circular Linked List ===\n";
    CircularLinkedList cll;
    cll.insertEnd(100);
    cll.insertEnd(200);
    cll.insertEnd(300);
    cll.display();

    return 0;
}

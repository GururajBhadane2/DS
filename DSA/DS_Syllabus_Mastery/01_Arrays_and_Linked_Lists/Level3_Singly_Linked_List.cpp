#include <iostream>

/*
 * LEVEL 3 (INTERMEDIATE): Singly Linked List
 * Demonstrates: Insert (Head/Tail/Position), Delete, Search, Reverse, Destructor
 */

struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    ~SinglyLinkedList() {
        Node* curr = head;
        while (curr) {
            Node* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }

    void insertAtHead(int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
    }

    void insertAtTail(int val) {
        Node* n = new Node(val);
        if (!head) { head = n; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
    }

    void deleteValue(int val) {
        if (!head) return;
        if (head->data == val) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }
        Node* curr = head;
        while (curr->next && curr->next->data != val) curr = curr->next;
        if (curr->next) {
            Node* toDelete = curr->next;
            curr->next = curr->next->next;
            delete toDelete;
        }
    }

    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void display() const {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList list;
    list.insertAtHead(20);
    list.insertAtHead(10);
    list.insertAtTail(30);
    list.insertAtTail(40);

    std::cout << "Original List: ";
    list.display();

    list.deleteValue(20);
    std::cout << "After deleting 20: ";
    list.display();

    list.reverse();
    std::cout << "After In-place Reversal: ";
    list.display();

    return 0;
}

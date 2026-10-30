#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    ~SinglyLinkedList() {
        Node* curr = head;
        while (curr) {
            Node* temp = curr->next;
            delete curr;
            curr = temp;
        }
    }

    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        std::cout << "Inserted " << val << " at beginning.\n";
    }

    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            std::cout << "Inserted " << val << " at end.\n";
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        std::cout << "Inserted " << val << " at end.\n";
    }

    void insertAtPosition(int val, int pos) {
        if (pos < 0) {
            std::cout << "Invalid position!\n";
            return;
        }
        if (pos == 0) {
            insertAtHead(val);
            return;
        }
        Node* temp = head;
        for (int i = 0; temp && i < pos - 1; ++i) {
            temp = temp->next;
        }
        if (!temp) {
            std::cout << "Position out of bounds!\n";
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        std::cout << "Inserted " << val << " at position " << pos << ".\n";
    }

    void deleteByValue(int val) {
        if (!head) {
            std::cout << "List is empty.\n";
            return;
        }
        if (head->data == val) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            std::cout << "Deleted " << val << " from list.\n";
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != val) {
            temp = temp->next;
        }
        if (!temp->next) {
            std::cout << "Element " << val << " not found in list.\n";
            return;
        }
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        std::cout << "Deleted " << val << " from list.\n";
    }

    bool search(int val) const {
        Node* temp = head;
        int idx = 0;
        while (temp) {
            if (temp->data == val) {
                std::cout << "Element " << val << " found at index " << idx << ".\n";
                return true;
            }
            temp = temp->next;
            idx++;
        }
        std::cout << "Element " << val << " not found.\n";
        return false;
    }

    void display() const {
        if (!head) {
            std::cout << "List is empty.\n";
            return;
        }
        std::cout << "Linked List: ";
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList sll;
    sll.insertAtHead(20);
    sll.insertAtHead(10);
    sll.insertAtTail(30);
    sll.insertAtPosition(25, 2);
    sll.display();

    sll.search(25);
    sll.search(99);

    sll.deleteByValue(25);
    sll.display();

    sll.deleteByValue(10);
    sll.display();

    return 0;
}

#include <iostream>

struct CNode {
    int data;
    CNode* next;
    CNode(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
private:
    CNode* head;

public:
    CircularLinkedList() : head(nullptr) {}

    ~CircularLinkedList() {
        if (!head) return;
        CNode* curr = head->next;
        while (curr != head) {
            CNode* temp = curr->next;
            delete curr;
            curr = temp;
        }
        delete head;
        head = nullptr;
    }

    void insertAtBeginning(int val) {
        CNode* newNode = new CNode(val);
        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            CNode* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
        std::cout << "Inserted " << val << " at beginning of circular list.\n";
    }

    void insertAtEnd(int val) {
        CNode* newNode = new CNode(val);
        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            CNode* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        std::cout << "Inserted " << val << " at end of circular list.\n";
    }

    void deleteNode(int val) {
        if (!head) {
            std::cout << "List is empty.\n";
            return;
        }
        CNode* curr = head;
        CNode* prev = nullptr;

        // If head contains the value
        if (head->data == val) {
            if (head->next == head) {
                delete head;
                head = nullptr;
                std::cout << "Deleted " << val << " (only node).\n";
                return;
            }
            CNode* last = head;
            while (last->next != head) {
                last = last->next;
            }
            last->next = head->next;
            CNode* toDelete = head;
            head = head->next;
            delete toDelete;
            std::cout << "Deleted head node " << val << ".\n";
            return;
        }

        prev = head;
        curr = head->next;
        while (curr != head && curr->data != val) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == head) {
            std::cout << "Element " << val << " not found in circular list.\n";
            return;
        }

        prev->next = curr->next;
        delete curr;
        std::cout << "Deleted " << val << " from circular list.\n";
    }

    void display() const {
        if (!head) {
            std::cout << "Circular List is empty.\n";
            return;
        }
        std::cout << "Circular List: ";
        CNode* temp = head;
        do {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        std::cout << "(back to head " << head->data << ")\n";
    }
};

int main() {
    CircularLinkedList cll;
    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtBeginning(5);
    cll.insertAtEnd(30);

    cll.display();

    cll.deleteNode(5);
    cll.display();

    cll.deleteNode(20);
    cll.display();

    return 0;
}

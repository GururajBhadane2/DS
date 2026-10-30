#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
public:
    Node* head;

    SinglyLinkedList() : head(nullptr) {}

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // In-place Iterative Reversal: O(N) Time, O(1) Extra Space
    void reverseIterative() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* nextNode = nullptr;

        while (curr != nullptr) {
            nextNode = curr->next; // Store next
            curr->next = prev;     // Reverse pointer
            prev = curr;           // Advance prev
            curr = nextNode;       // Advance curr
        }
        head = prev;
    }

    // In-place Recursive Reversal
    Node* reverseRecursiveHelper(Node* node) {
        if (!node || !node->next) {
            return node;
        }
        Node* newHead = reverseRecursiveHelper(node->next);
        node->next->next = node;
        node->next = nullptr;
        return newHead;
    }

    void reverseRecursive() {
        head = reverseRecursiveHelper(head);
    }

    void display() const {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }

    ~SinglyLinkedList() {
        Node* curr = head;
        while (curr) {
            Node* temp = curr->next;
            delete curr;
            curr = temp;
        }
    }
};

int main() {
    SinglyLinkedList list;
    for (int i = 1; i <= 5; ++i) {
        list.insert(i * 10);
    }

    std::cout << "Original List:\n";
    list.display();

    std::cout << "\nAfter Iterative In-place Reversal:\n";
    list.reverseIterative();
    list.display();

    std::cout << "\nAfter Recursive Reversal (Back to original orientation):\n";
    list.reverseRecursive();
    list.display();

    return 0;
}

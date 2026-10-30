#include <iostream>
#include <string>

/*
 * Priority Queue Implementation (Ordered Linked List):
 * Each node stores a data value and a numerical priority.
 * Higher priority value indicates higher precedence (served first).
 */

struct PQNode {
    std::string data;
    int priority;
    PQNode* next;

    PQNode(std::string d, int p) : data(d), priority(p), next(nullptr) {}
};

class PriorityQueue {
private:
    PQNode* head;

public:
    PriorityQueue() : head(nullptr) {}

    ~PriorityQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    // Insert element according to priority (Higher priority near the front)
    void enqueue(std::string data, int priority) {
        PQNode* newNode = new PQNode(data, priority);

        // If list is empty or new node has higher priority than head
        if (!head || priority > head->priority) {
            newNode->next = head;
            head = newNode;
        } else {
            PQNode* temp = head;
            while (temp->next && temp->next->priority >= priority) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        std::cout << "Enqueued: [" << data << ", Priority: " << priority << "]\n";
    }

    // Dequeue highest priority element from the front
    std::string dequeue() {
        if (isEmpty()) {
            std::cout << "Priority Queue Underflow!\n";
            return "";
        }
        PQNode* temp = head;
        std::string val = temp->data;
        int p = temp->priority;
        head = head->next;
        delete temp;
        std::cout << "Dequeued highest priority element: [" << val << ", Priority: " << p << "]\n";
        return val;
    }

    void peek() const {
        if (isEmpty()) {
            std::cout << "Priority Queue is empty.\n";
            return;
        }
        std::cout << "Highest priority item: [" << head->data << ", Priority: " << head->priority << "]\n";
    }

    void display() const {
        if (isEmpty()) {
            std::cout << "Priority Queue is empty.\n";
            return;
        }
        std::cout << "Priority Queue contents:\n";
        PQNode* curr = head;
        while (curr) {
            std::cout << "  -> (" << curr->data << " | Priority: " << curr->priority << ")\n";
            curr = curr->next;
        }
    }
};

int main() {
    PriorityQueue pq;

    pq.enqueue("Routine Report", 1);
    pq.enqueue("System Crash Alert", 10);
    pq.enqueue("User Password Reset", 3);
    pq.enqueue("Security Patch", 8);

    std::cout << "\nCurrent Queue state:\n";
    pq.display();

    pq.peek();

    std::cout << "\nServing jobs:\n";
    pq.dequeue();
    pq.dequeue();

    std::cout << "\nRemaining Queue state:\n";
    pq.display();

    return 0;
}

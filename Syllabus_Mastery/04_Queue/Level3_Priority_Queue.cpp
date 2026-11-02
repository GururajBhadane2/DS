#include <iostream>
#include <string>

/*
 * LEVEL 3 (INTERMEDIATE/ADVANCED): Priority Queue (Ordered Linked List)
 * Higher priority items are dequeued first.
 */

struct PQNode {
    std::string task;
    int priority;
    PQNode* next;
    PQNode(std::string t, int p) : task(t), priority(p), next(nullptr) {}
};

class PriorityQueue {
private:
    PQNode* head;
public:
    PriorityQueue() : head(nullptr) {}

    void push(std::string task, int priority) {
        PQNode* n = new PQNode(task, priority);
        if (!head || priority > head->priority) {
            n->next = head;
            head = n;
        } else {
            PQNode* cur = head;
            while (cur->next && cur->next->priority >= priority) {
                cur = cur->next;
            }
            n->next = cur->next;
            cur->next = n;
        }
    }

    std::string pop() {
        if (!head) return "";
        PQNode* temp = head;
        std::string t = temp->task;
        head = head->next;
        delete temp;
        return t;
    }

    void display() const {
        PQNode* cur = head;
        std::cout << "Priority Queue: ";
        while (cur) {
            std::cout << "[" << cur->task << " | P:" << cur->priority << "] -> ";
            cur = cur->next;
        }
        std::cout << "NULL\n";
    }
};

int main() {
    PriorityQueue pq;
    pq.push("Regular print", 1);
    pq.push("Kernel Interrupt", 10);
    pq.push("User IO request", 5);
    pq.display();

    std::cout << "Served: " << pq.pop() << "\n";
    pq.display();

    return 0;
}

#include <iostream>

struct QNode {
    int data;
    QNode* next;
    QNode(int val) : data(val), next(nullptr) {}
};

class DynamicQueue {
private:
    QNode* front;
    QNode* rear;
    int count;

public:
    DynamicQueue() : front(nullptr), rear(nullptr), count(0) {}

    ~DynamicQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    void enqueue(int val) {
        QNode* newNode = new QNode(val);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
        std::cout << "Enqueued: " << val << "\n";
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue Underflow! Queue is empty.\n";
            return -1;
        }
        QNode* temp = front;
        int val = temp->data;
        front = front->next;
        if (!front) {
            rear = nullptr;
        }
        delete temp;
        count--;
        std::cout << "Dequeued: " << val << "\n";
        return val;
    }

    int peek() const {
        if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            return -1;
        }
        return front->data;
    }

    int size() const {
        return count;
    }

    void display() const {
        if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            return;
        }
        std::cout << "Dynamic Queue (Front -> Rear): ";
        QNode* curr = front;
        while (curr) {
            std::cout << curr->data << " -> ";
            curr = curr->next;
        }
        std::cout << "NULL\n";
    }
};

int main() {
    DynamicQueue dq;

    dq.enqueue(100);
    dq.enqueue(200);
    dq.enqueue(300);
    dq.display();

    std::cout << "Front item: " << dq.peek() << "\n";
    std::cout << "Queue size: " << dq.size() << "\n";

    dq.dequeue();
    dq.display();

    dq.enqueue(400);
    dq.display();

    return 0;
}

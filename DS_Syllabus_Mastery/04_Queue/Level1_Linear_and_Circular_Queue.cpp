#include <iostream>

/*
 * LEVEL 1 (BASIC/INTERMEDIATE): Linear vs Circular Queue
 * Demonstrates how circular queue solves linear queue's false overflow problem.
 */

class CircularQueue {
private:
    int arr[5];
    int front, rear, count, capacity;

public:
    CircularQueue() : front(0), rear(-1), count(0), capacity(5) {}

    bool isFull() const { return count == capacity; }
    bool isEmpty() const { return count == 0; }

    void enqueue(int val) {
        if (isFull()) {
            std::cout << "Circular Queue Full! Cannot insert " << val << "\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        count++;
        std::cout << "Enqueued: " << val << "\n";
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Circular Queue Empty!\n";
            return -1;
        }
        int val = arr[front];
        front = (front + 1) % capacity;
        count--;
        std::cout << "Dequeued: " << val << "\n";
        return val;
    }

    void display() const {
        std::cout << "Queue elements: ";
        for (int i = 0; i < count; ++i) {
            std::cout << arr[(front + i) % capacity] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    CircularQueue cq;
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);
    cq.display();

    cq.dequeue();
    cq.dequeue();

    // Reusing wrapped-around space
    cq.enqueue(60);
    cq.enqueue(70);
    cq.display();

    return 0;
}

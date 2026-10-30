#include <iostream>

#define MAX 5

/*
 * Linear Queue using Array:
 * Follows FIFO (First-In, First-Out).
 * Note: Once elements are dequeued, vacant space at the front cannot be reused
 * without shifting (known as the drawback of simple linear queue).
 */

class LinearQueue {
private:
    int arr[MAX];
    int front;
    int rear;

public:
    LinearQueue() : front(-1), rear(-1) {}

    bool isEmpty() const {
        return front == -1 || front > rear;
    }

    bool isFull() const {
        return rear == MAX - 1;
    }

    void enqueue(int val) {
        if (isFull()) {
            std::cout << "Queue Overflow! Cannot enqueue " << val << ".\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = val;
        std::cout << "Enqueued: " << val << " (Rear: " << rear << ")\n";
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue Underflow! Queue is empty.\n";
            return -1;
        }
        int val = arr[front++];
        std::cout << "Dequeued: " << val << " (Front: " << front << ")\n";
        if (front > rear) { // Reset queue when all elements dequeued
            front = rear = -1;
        }
        return val;
    }

    int peek() const {
        if (isEmpty()) {
            std::cout << "Queue is empty!\n";
            return -1;
        }
        return arr[front];
    }

    void display() const {
        if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            return;
        }
        std::cout << "Linear Queue contents: ";
        for (int i = front; i <= rear; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    LinearQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();

    q.enqueue(60); // Queue Overflow

    q.dequeue();
    q.dequeue();
    q.display();

    std::cout << "Front element: " << q.peek() << "\n";

    return 0;
}

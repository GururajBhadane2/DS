#include <iostream>

/*
 * Circular Queue using Modulo Arithmetic:
 * Solves the memory wastage issue of linear queue by wrapping around indices.
 * Next Rear  = (rear + 1) % capacity
 * Next Front = (front + 1) % capacity
 */

class CircularQueue {
private:
    int* arr;
    int capacity;
    int front;
    int rear;
    int count;

public:
    CircularQueue(int cap = 5) : capacity(cap), front(0), rear(-1), count(0) {
        arr = new int[capacity];
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == capacity;
    }

    void enqueue(int val) {
        if (isFull()) {
            std::cout << "Circular Queue is FULL! Cannot enqueue " << val << ".\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        count++;
        std::cout << "Enqueued: " << val << " (Rear index: " << rear << ")\n";
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Circular Queue is EMPTY! Cannot dequeue.\n";
            return -1;
        }
        int val = arr[front];
        front = (front + 1) % capacity;
        count--;
        std::cout << "Dequeued: " << val << "\n";
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
        std::cout << "Circular Queue elements: ";
        for (int i = 0; i < count; ++i) {
            std::cout << arr[(front + i) % capacity] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    CircularQueue cq(5);

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);
    cq.display();

    cq.enqueue(60); // Full

    cq.dequeue();
    cq.dequeue();
    cq.display();

    // Re-use wrap-around space
    cq.enqueue(60);
    cq.enqueue(70);
    cq.display();

    return 0;
}

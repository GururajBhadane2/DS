#include <iostream>

/*
 * Double-Ended Queue (Deque):
 * Insertion and Deletion can be performed from both ends (Front & Rear).
 */

class Deque {
private:
    int* arr;
    int capacity;
    int front;
    int rear;
    int size;

public:
    Deque(int cap = 6) : capacity(cap), front(-1), rear(0), size(0) {
        arr = new int[capacity];
    }

    ~Deque() {
        delete[] arr;
    }

    bool isFull() const {
        return size == capacity;
    }

    bool isEmpty() const {
        return size == 0;
    }

    void insertFront(int val) {
        if (isFull()) {
            std::cout << "Deque Overflow at Front!\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            front = (front - 1 + capacity) % capacity;
        }
        arr[front] = val;
        size++;
        std::cout << "Inserted at front: " << val << "\n";
    }

    void insertRear(int val) {
        if (isFull()) {
            std::cout << "Deque Overflow at Rear!\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = val;
        size++;
        std::cout << "Inserted at rear: " << val << "\n";
    }

    int deleteFront() {
        if (isEmpty()) {
            std::cout << "Deque Underflow at Front!\n";
            return -1;
        }
        int val = arr[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        size--;
        std::cout << "Deleted from front: " << val << "\n";
        return val;
    }

    int deleteRear() {
        if (isEmpty()) {
            std::cout << "Deque Underflow at Rear!\n";
            return -1;
        }
        int val = arr[rear];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            rear = (rear - 1 + capacity) % capacity;
        }
        size--;
        std::cout << "Deleted from rear: " << val << "\n";
        return val;
    }

    int getFront() const {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int getRear() const {
        if (isEmpty()) return -1;
        return arr[rear];
    }

    void display() const {
        if (isEmpty()) {
            std::cout << "Deque is empty.\n";
            return;
        }
        std::cout << "Deque contents: ";
        for (int i = 0; i < size; ++i) {
            std::cout << arr[(front + i) % capacity] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    Deque dq(5);

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertFront(2);
    dq.display(); // 2 5 10 20

    std::cout << "Front: " << dq.getFront() << ", Rear: " << dq.getRear() << "\n";

    dq.deleteFront();
    dq.deleteRear();
    dq.display(); // 5 10

    return 0;
}

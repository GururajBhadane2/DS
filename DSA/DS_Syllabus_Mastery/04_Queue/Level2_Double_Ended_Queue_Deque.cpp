#include <iostream>

/*
 * LEVEL 2 (INTERMEDIATE): Double Ended Queue (Deque)
 * Supports push/pop at both front and rear in O(1).
 */

class DequeArray {
private:
    int arr[6];
    int front, rear, size, capacity;

public:
    DequeArray() : front(-1), rear(0), size(0), capacity(6) {}

    bool isFull() const { return size == capacity; }
    bool isEmpty() const { return size == 0; }

    void insertFront(int x) {
        if (isFull()) return;
        if (isEmpty()) front = rear = 0;
        else front = (front - 1 + capacity) % capacity;
        arr[front] = x;
        size++;
    }

    void insertRear(int x) {
        if (isFull()) return;
        if (isEmpty()) front = rear = 0;
        else rear = (rear + 1) % capacity;
        arr[rear] = x;
        size++;
    }

    int deleteFront() {
        if (isEmpty()) return -1;
        int val = arr[front];
        if (front == rear) front = rear = -1;
        else front = (front + 1) % capacity;
        size--;
        return val;
    }

    int deleteRear() {
        if (isEmpty()) return -1;
        int val = arr[rear];
        if (front == rear) front = rear = -1;
        else rear = (rear - 1 + capacity) % capacity;
        size--;
        return val;
    }

    void display() const {
        std::cout << "Deque: ";
        for (int i = 0; i < size; ++i) {
            std::cout << arr[(front + i) % capacity] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    DequeArray dq;
    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertFront(1);
    dq.display(); // 1 5 10 20

    std::cout << "Pop front: " << dq.deleteFront() << "\n";
    std::cout << "Pop rear:  " << dq.deleteRear() << "\n";
    dq.display(); // 5 10

    return 0;
}

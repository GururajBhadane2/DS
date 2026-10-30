#include <iostream>

/*
 * LEVEL 1 (BASIC): Stack as an ADT (LIFO)
 * 1. Array Implementation (Bounded, Overflow/Underflow)
 * 2. Linked List Implementation (Dynamic, Unbounded)
 */

class ArrayStack {
private:
    int arr[5];
    int top;
public:
    ArrayStack() : top(-1) {}
    bool isFull() const { return top == 4; }
    bool isEmpty() const { return top == -1; }
    void push(int x) {
        if (isFull()) { std::cout << "Stack Overflow!\n"; return; }
        arr[++top] = x;
    }
    int pop() {
        if (isEmpty()) { std::cout << "Stack Underflow!\n"; return -1; }
        return arr[top--];
    }
    int peek() const { return isEmpty() ? -1 : arr[top]; }
};

struct SNode {
    int data;
    SNode* next;
    SNode(int v) : data(v), next(nullptr) {}
};

class LinkedStack {
private:
    SNode* top;
public:
    LinkedStack() : top(nullptr) {}
    bool isEmpty() const { return top == nullptr; }
    void push(int x) {
        SNode* n = new SNode(x);
        n->next = top;
        top = n;
    }
    int pop() {
        if (isEmpty()) return -1;
        SNode* temp = top;
        int val = temp->data;
        top = top->next;
        delete temp;
        return val;
    }
    int peek() const { return isEmpty() ? -1 : top->data; }
};

int main() {
    std::cout << "--- Array Stack Test ---\n";
    ArrayStack as;
    as.push(10); as.push(20); as.push(30);
    std::cout << "Peek: " << as.peek() << ", Pop: " << as.pop() << "\n";

    std::cout << "--- Linked Stack Test ---\n";
    LinkedStack ls;
    ls.push(100); ls.push(200);
    std::cout << "Peek: " << ls.peek() << ", Pop: " << ls.pop() << "\n";

    return 0;
}

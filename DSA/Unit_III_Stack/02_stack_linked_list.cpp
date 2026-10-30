#include <iostream>

struct StackNode {
    int data;
    StackNode* next;
    StackNode(int val) : data(val), next(nullptr) {}
};

class StackLinkedList {
private:
    StackNode* top;
    int count;

public:
    StackLinkedList() : top(nullptr), count(0) {}

    ~StackLinkedList() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    void push(int val) {
        StackNode* newNode = new StackNode(val);
        newNode->next = top;
        top = newNode;
        count++;
        std::cout << "Pushed: " << val << "\n";
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow! Stack is empty.\n";
            return -1;
        }
        StackNode* temp = top;
        int poppedVal = temp->data;
        top = top->next;
        delete temp;
        count--;
        std::cout << "Popped: " << poppedVal << "\n";
        return poppedVal;
    }

    int peek() const {
        if (isEmpty()) {
            std::cout << "Stack is empty.\n";
            return -1;
        }
        return top->data;
    }

    int size() const {
        return count;
    }

    void display() const {
        if (isEmpty()) {
            std::cout << "Stack is empty.\n";
            return;
        }
        std::cout << "Dynamic Stack (Top -> Bottom): ";
        StackNode* curr = top;
        while (curr) {
            std::cout << curr->data << " -> ";
            curr = curr->next;
        }
        std::cout << "NULL\n";
    }
};

int main() {
    StackLinkedList s;

    s.push(100);
    s.push(200);
    s.push(300);
    s.display();

    std::cout << "Peek top: " << s.peek() << "\n";
    std::cout << "Size: " << s.size() << "\n";

    s.pop();
    s.display();

    return 0;
}

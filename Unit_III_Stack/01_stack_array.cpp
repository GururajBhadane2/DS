#include <iostream>

#define MAX_SIZE 5

class StackArray {
private:
    int arr[MAX_SIZE];
    int top;

public:
    StackArray() : top(-1) {}

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == MAX_SIZE - 1;
    }

    void push(int val) {
        if (isFull()) {
            std::cout << "Stack Overflow! Cannot push " << val << "\n";
            return;
        }
        arr[++top] = val;
        std::cout << "Pushed: " << val << " (Top is now at index " << top << ")\n";
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow! Stack is empty.\n";
            return -1;
        }
        int val = arr[top--];
        std::cout << "Popped: " << val << "\n";
        return val;
    }

    int peek() const {
        if (isEmpty()) {
            std::cout << "Stack is empty!\n";
            return -1;
        }
        return arr[top];
    }

    void display() const {
        if (isEmpty()) {
            std::cout << "Stack is empty.\n";
            return;
        }
        std::cout << "Stack contents (Top -> Bottom): ";
        for (int i = top; i >= 0; --i) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    StackArray s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    std::cout << "Top element (peek): " << s.peek() << "\n";

    s.pop();
    s.display();

    s.push(40);
    s.push(50);
    s.push(60); // fills stack
    s.push(70); // triggers overflow

    s.display();

    return 0;
}

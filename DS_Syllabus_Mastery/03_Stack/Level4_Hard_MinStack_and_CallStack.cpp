#include <iostream>
#include <stack>

/*
 * LEVEL 4 (HARD):
 * 1. Min-Stack: Retrieves minimum element in O(1) time and O(N) space.
 * 2. System Call Stack Tracing with recursion.
 */

class MinStack {
private:
    std::stack<int> mainStack;
    std::stack<int> minStack;

public:
    void push(int x) {
        mainStack.push(x);
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }

    void pop() {
        if (mainStack.empty()) return;
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        mainStack.pop();
    }

    int top() const {
        return mainStack.top();
    }

    int getMin() const {
        return minStack.top();
    }
};

int main() {
    MinStack ms;
    ms.push(18);
    ms.push(19);
    ms.push(29);
    ms.push(15);
    ms.push(16);

    std::cout << "Current Min: " << ms.getMin() << " (Expected 15)\n";
    ms.pop(); // pops 16
    ms.pop(); // pops 15
    std::cout << "Min after popping 15: " << ms.getMin() << " (Expected 18)\n";

    return 0;
}

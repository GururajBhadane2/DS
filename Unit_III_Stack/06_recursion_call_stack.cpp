#include <iostream>
#include <iomanip>

/*
 * Demonstration of Recursion and the System Call Stack Mechanism:
 * When a recursive function is invoked:
 * 1. An Activation Record (Stack Frame) is pushed onto the system call stack.
 * 2. It contains function parameters, local variables, and return address.
 * 3. Base case stops pushing and starts unwinding (popping frames).
 */

void printIndent(int depth) {
    for (int i = 0; i < depth; ++i) {
        std::cout << "  │ ";
    }
}

long long factorialWithCallStack(int n, int depth = 0) {
    printIndent(depth);
    std::cout << "┌── [PUSH Frame " << depth << "] factorial(" << n << ") called\n";

    if (n <= 1) {
        printIndent(depth);
        std::cout << "├── [BASE CASE REACHED] returning 1\n";
        printIndent(depth);
        std::cout << "└── [POP  Frame " << depth << "] returned 1\n";
        return 1;
    }

    long long subResult = factorialWithCallStack(n - 1, depth + 1);
    long long result = n * subResult;

    printIndent(depth);
    std::cout << "├── [COMPUTE] " << n << " * factorial(" << n - 1 << ") = " << result << "\n";
    printIndent(depth);
    std::cout << "└── [POP  Frame " << depth << "] returned " << result << "\n";

    return result;
}

// Tower of Hanoi showing recursive call flow
void towerOfHanoi(int n, char fromRod, char toRod, char auxRod, int depth = 0) {
    if (n == 0) return;

    printIndent(depth);
    std::cout << "Call: Solve Hanoi for " << n << " disks (" << fromRod << " -> " << toRod << ")\n";

    towerOfHanoi(n - 1, fromRod, auxRod, toRod, depth + 1);

    printIndent(depth);
    std::cout << ">> MOVE Disk " << n << " from [" << fromRod << "] to [" << toRod << "]\n";

    towerOfHanoi(n - 1, auxRod, toRod, fromRod, depth + 1);
}

int main() {
    std::cout << "========================================================\n";
    std::cout << " 1. SYSTEM CALL STACK TRACE: FACTORIAL(4)\n";
    std::cout << "========================================================\n";
    long long ans = factorialWithCallStack(4);
    std::cout << "\nResult: 4! = " << ans << "\n\n";

    std::cout << "========================================================\n";
    std::cout << " 2. RECURSIVE CALL TREE: TOWER OF HANOI (3 Disks)\n";
    std::cout << "========================================================\n";
    towerOfHanoi(3, 'A', 'C', 'B');

    return 0;
}

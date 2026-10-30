#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if parentheses are balanced
bool isBalanced(string expr) {
    stack<char> s;

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        // Push opening brackets
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        // Check closing brackets
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) {
                return false; // Closing bracket with no opening
            }

            char top = s.top();
            s.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false; // Mismatched brackets
            }
        }
    }

    // Stack must be empty if all matched
    return s.empty();
}

int main() {
    string expr;
    char cont;

    do {
        cout << "\nEnter Expression to check: ";
        cin >> expr;

        if (isBalanced(expr)) {
            cout << "Result: Well Parenthesized (Balanced)!\n";
        } else {
            cout << "Result: NOT Balanced!\n";
        }

        cout << "Check another expression? (y/n): ";
        cin >> cont;
    } while (cont == 'y' || cont == 'Y');

    return 0;
}

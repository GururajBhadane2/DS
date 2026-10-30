#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(string expr) {
    stack<char> s;

    for (int i = 0; i < expr.length(); i++) {
        char c = expr[i];

        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        } 
        else if (c == ')' || c == '}' || c == ']') {
            if (s.empty()) return false;

            char top = s.top();
            if ((c == ')' && top == '(') || 
                (c == '}' && top == '{') || 
                (c == ']' && top == '[')) {
                s.pop();
            } else {
                return false;
            }
        }
    }

    return s.empty();
}

int main() {
    string expr1 = "{()}[]";
    string expr2 = "{(})";

    cout << expr1 << " is " << (isBalanced(expr1) ? "Balanced\n" : "Not Balanced\n");
    cout << expr2 << " is " << (isBalanced(expr2) ? "Balanced\n" : "Not Balanced\n");

    return 0;
}


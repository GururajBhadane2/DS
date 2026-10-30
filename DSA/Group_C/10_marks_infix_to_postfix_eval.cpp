#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <cctype>
#include <cmath>
#include <iomanip>

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

// a. Convert Infix to Postfix
std::string infixToPostfix(const std::string& infix) {
    std::stack<char> st;
    std::string postfix = "";

    for (char ch : infix) {
        if (std::isspace(ch)) continue;

        if (std::isalnum(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            st.push(ch);
        } else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty() && st.top() == '(') st.pop();
        } else {
            while (!st.empty() && st.top() != '(' && precedence(st.top()) >= precedence(ch)) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

// b. Evaluate Postfix Expression for given student marks input
double evaluatePostfix(const std::string& postfix, const std::map<char, double>& values) {
    std::stack<double> st;

    for (char ch : postfix) {
        if (std::isalpha(ch)) {
            if (values.find(ch) != values.end()) {
                st.push(values.at(ch));
            } else {
                std::cout << "Error: Value for variable " << ch << " not provided! Defaulting to 0.\n";
                st.push(0.0);
            }
        } else if (std::isdigit(ch)) {
            st.push(ch - '0');
        } else {
            if (st.size() < 2) {
                std::cout << "Malformed postfix expression!\n";
                return 0.0;
            }
            double val2 = st.top(); st.pop();
            double val1 = st.top(); st.pop();

            switch (ch) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': 
                    if (val2 == 0) {
                        std::cout << "Division by zero!\n";
                        return 0.0;
                    }
                    st.push(val1 / val2); 
                    break;
                case '^': st.push(std::pow(val1, val2)); break;
            }
        }
    }
    return st.empty() ? 0.0 : st.top();
}

int main() {
    std::cout << "=== Marks Calculation Formula Evaluation ===\n";
    // Example formula: Final Internal = TheoryTest1 (A) + TheoryTest2 (B) + Assignment (C) / 2
    // Written as infix: (A+B)/2+C
    std::string infix = "(A+B)/2+C";
    std::cout << "Marks Formula (Infix):   " << infix << "\n";

    // a. Infix to postfix
    std::string postfix = infixToPostfix(infix);
    std::cout << "Marks Formula (Postfix): " << postfix << "\n\n";

    // b. Given inputs for Student
    // A (Test 1) = 18, B (Test 2) = 16, C (Assignment) = 10
    std::map<char, double> studentMarks = {
        {'A', 18.0},
        {'B', 16.0},
        {'C', 10.0}
    };

    std::cout << "Given Student Input Marks:\n";
    std::cout << "  Test 1 (A):     " << studentMarks['A'] << " / 20\n";
    std::cout << "  Test 2 (B):     " << studentMarks['B'] << " / 20\n";
    std::cout << "  Assignment (C): " << studentMarks['C'] << " / 10\n\n";

    double finalInternal = evaluatePostfix(postfix, studentMarks);
    std::cout << "Evaluated Final Internal Marks: " 
              << std::fixed << std::setprecision(2) << finalInternal << " / 25\n";

    return 0;
}

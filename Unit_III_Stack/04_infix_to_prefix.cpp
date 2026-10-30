#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>

/*
 * Infix to Prefix Conversion:
 * 1. Reverse the infix expression.
 * 2. Invert parentheses: '(' becomes ')' and ')' becomes '('.
 * 3. Convert to postfix (taking care of operator precedence/associativity).
 * 4. Reverse the postfix string to obtain the final prefix expression.
 */

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

std::string infixToPrefix(std::string infix) {
    // Step 1: Reverse infix
    std::reverse(infix.begin(), infix.end());

    // Step 2: Swap brackets
    for (char& ch : infix) {
        if (ch == '(') ch = ')';
        else if (ch == ')') ch = '(';
    }

    // Step 3: Modified postfix conversion
    std::stack<char> st;
    std::string postfix = "";

    for (char ch : infix) {
        if (std::isalnum(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            st.push(ch);
        } else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        } else {
            // For prefix conversion after reversal:
            // strictly greater precedence condition for right-associativity
            if (ch == '^') {
                while (!st.empty() && precedence(st.top()) >= precedence(ch)) {
                    postfix += st.top();
                    st.pop();
                }
            } else {
                while (!st.empty() && precedence(st.top()) > precedence(ch)) {
                    postfix += st.top();
                    st.pop();
                }
            }
            st.push(ch);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    // Step 4: Reverse postfix result
    std::reverse(postfix.begin(), postfix.end());
    return postfix;
}

int main() {
    std::string expressions[] = {
        "A+B*C",
        "(A+B)*C",
        "A+B*(C^D-E)"
    };

    for (const auto& expr : expressions) {
        std::cout << "Infix:  " << expr << "\n";
        std::cout << "Prefix: " << infixToPrefix(expr) << "\n\n";
    }

    return 0;
}

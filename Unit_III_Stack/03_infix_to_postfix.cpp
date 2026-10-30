#include <iostream>
#include <stack>
#include <string>
#include <cctype>

/*
 * Infix to Postfix Conversion using Shunting-Yard Algorithm:
 * Precedence:
 *   ^ (highest, right-associative)
 *   *, / (middle, left-associative)
 *   +, - (lowest, left-associative)
 */

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

bool isRightAssociative(char op) {
    return op == '^';
}

std::string infixToPostfix(const std::string& infix) {
    std::stack<char> st;
    std::string postfix = "";

    for (char ch : infix) {
        // Operand
        if (std::isalnum(ch)) {
            postfix += ch;
        }
        // Opening parenthesis
        else if (ch == '(') {
            st.push(ch);
        }
        // Closing parenthesis
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty() && st.top() == '(') {
                st.pop(); // Remove '('
            }
        }
        // Operator
        else {
            while (!st.empty() && st.top() != '(' &&
                   (precedence(st.top()) > precedence(ch) ||
                    (precedence(st.top()) == precedence(ch) && !isRightAssociative(ch)))) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    // Pop all remaining operators
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main() {
    std::string expressions[] = {
        "A+B*C",
        "(A+B)*C",
        "A+B*(C^D-E)^(F+G*H)-I",
        "K+L-M*N+(O^P)*W/U/V*T+Q"
    };

    for (const auto& expr : expressions) {
        std::cout << "Infix:   " << expr << "\n";
        std::cout << "Postfix: " << infixToPostfix(expr) << "\n\n";
    }

    return 0;
}

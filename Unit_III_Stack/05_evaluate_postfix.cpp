#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <cctype>

/*
 * Evaluation of Postfix Expression:
 * Scan left to right:
 * - If operand: push onto stack.
 * - If operator: pop two operands (op2, then op1), compute op1 <op> op2, push result.
 */

int evaluatePostfix(const std::string& expr) {
    std::stack<int> st;

    for (char ch : expr) {
        if (std::isspace(ch)) continue;

        if (std::isdigit(ch)) {
            st.push(ch - '0'); // Convert char to integer
        } else {
            if (st.size() < 2) {
                std::cout << "Invalid Expression!\n";
                return 0;
            }
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();

            switch (ch) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': 
                    if (val2 == 0) {
                        std::cout << "Division by zero!\n";
                        return 0;
                    }
                    st.push(val1 / val2); 
                    break;
                case '^': st.push(static_cast<int>(std::pow(val1, val2))); break;
                default:
                    std::cout << "Unknown operator: " << ch << "\n";
                    return 0;
            }
        }
    }
    return st.top();
}

int main() {
    std::string tests[] = {
        "231*+9-",     // (2 + (3 * 1)) - 9 = 5 - 9 = -4
        "53+82-*",     // (5 + 3) * (8 - 2) = 8 * 6 = 48
        "23^2*",       // (2 ^ 3) * 2 = 8 * 2 = 16
        "42/3+"        // (4 / 2) + 3 = 5
    };

    for (const auto& expr : tests) {
        std::cout << "Postfix Expression: " << expr << "\n";
        std::cout << "Evaluated Result:   " << evaluatePostfix(expr) << "\n\n";
    }

    return 0;
}

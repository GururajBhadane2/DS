#include <iostream>
#include <stack>
#include <string>

/*
 * Parenthesis Checking using Stack:
 * Supported brackets: (), {}, []
 * Validates that every opening symbol is matched with the corresponding closing symbol
 * in proper nesting order.
 */

bool checkParentheses(const std::string& expr, std::string& errorMsg) {
    std::stack<std::pair<char, int>> st; // stores char and 1-based position

    for (int i = 0; i < static_cast<int>(expr.length()); ++i) {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            st.push({ch, i + 1});
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.empty()) {
                errorMsg = "Unmatched closing bracket '" + std::string(1, ch) + "' at position " + std::to_string(i + 1);
                return false;
            }

            char open = st.top().first;
            int openPos = st.top().second;
            st.pop();

            if ((ch == ')' && open != '(') ||
                (ch == '}' && open != '{') ||
                (ch == ']' && open != '[')) {
                errorMsg = "Mismatched brackets: '" + std::string(1, open) + "' at pos " + std::to_string(openPos) 
                         + " closed by '" + std::string(1, ch) + "' at pos " + std::to_string(i + 1);
                return false;
            }
        }
    }

    if (!st.empty()) {
        errorMsg = "Unclosed opening bracket '" + std::string(1, st.top().first) + "' at position " + std::to_string(st.top().second);
        return false;
    }

    errorMsg = "Expression is well-formed and balanced.";
    return true;
}

int main() {
    std::string testExpressions[] = {
        "{a + [b * (c - d)] / e}",             // Balanced
        "((a + b) * (c - d)",                  // Unclosed (
        "{[a + b) + c]}",                      // Mismatched
        "a + b) * c",                          // Unmatched )
        "[A + {B - (C * D)} + (E / F)]"        // Balanced
    };

    std::cout << "=== Parenthesis Checker Using Stack ===\n\n";

    for (const auto& expr : testExpressions) {
        std::string reason;
        bool isValid = checkParentheses(expr, reason);

        std::cout << "Expression: " << expr << "\n";
        std::cout << "Status:     " << (isValid ? "VALID (BALANCED)" : "INVALID (UNBALANCED)") << "\n";
        std::cout << "Details:    " << reason << "\n";
        std::cout << "--------------------------------------------------------\n";
    }

    return 0;
}

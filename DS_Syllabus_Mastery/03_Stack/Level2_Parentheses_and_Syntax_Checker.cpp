#include <iostream>
#include <stack>
#include <string>

/*
 * LEVEL 2 (INTERMEDIATE): Bracket and Syntax Validation using Stack
 * Checks (), {}, [] with position diagnostic reporting.
 */

bool isValidParentheses(const std::string& s, std::string& err) {
    std::stack<std::pair<char, int>> st;
    for (int i = 0; i < (int)s.length(); ++i) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            st.push({c, i + 1});
        } else if (c == ')' || c == '}' || c == ']') {
            if (st.empty()) {
                err = "Extra closing bracket '" + std::string(1, c) + "' at position " + std::to_string(i + 1);
                return false;
            }
            char open = st.top().first;
            int pos = st.top().second;
            st.pop();
            if ((c == ')' && open != '(') ||
                (c == '}' && open != '{') ||
                (c == ']' && open != '[')) {
                err = "Mismatched '" + std::string(1, open) + "' at pos " + std::to_string(pos) + " with '" + std::string(1, c) + "' at pos " + std::to_string(i + 1);
                return false;
            }
        }
    }
    if (!st.empty()) {
        err = "Unclosed bracket '" + std::string(1, st.top().first) + "' at position " + std::to_string(st.top().second);
        return false;
    }
    err = "Valid";
    return true;
}

int main() {
    std::string tests[] = {"{[a + b] * (c - d)}", "([a + b)}", "((a + b)"};
    for (const auto& t : tests) {
        std::string err;
        bool ok = isValidParentheses(t, err);
        std::cout << t << " -> " << (ok ? "BALANCED" : ("ERROR: " + err)) << "\n";
    }
    return 0;
}

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>
#include <cmath>

/*
 * LEVEL 3 (HARD): Complete Expression Processing
 * 1. Infix to Postfix (Shunting-Yard)
 * 2. Infix to Prefix
 * 3. Postfix Evaluation
 */

int prec(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

std::string infixToPostfix(const std::string& infix) {
    std::stack<char> st;
    std::string post = "";
    for (char c : infix) {
        if (std::isalnum(c)) post += c;
        else if (c == '(') st.push(c);
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') { post += st.top(); st.pop(); }
            if (!st.empty()) st.pop();
        } else {
            while (!st.empty() && st.top() != '(' && (prec(st.top()) > prec(c) || (prec(st.top()) == prec(c) && c != '^'))) {
                post += st.top(); st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) { post += st.top(); st.pop(); }
    return post;
}

std::string infixToPrefix(std::string infix) {
    std::reverse(infix.begin(), infix.end());
    for (char& c : infix) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }
    std::stack<char> st;
    std::string post = "";
    for (char c : infix) {
        if (std::isalnum(c)) post += c;
        else if (c == '(') st.push(c);
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') { post += st.top(); st.pop(); }
            if (!st.empty()) st.pop();
        } else {
            while (!st.empty() && prec(st.top()) > prec(c)) { post += st.top(); st.pop(); }
            st.push(c);
        }
    }
    while (!st.empty()) { post += st.top(); st.pop(); }
    std::reverse(post.begin(), post.end());
    return post;
}

double evalPostfix(const std::string& post) {
    std::stack<double> st;
    for (char c : post) {
        if (std::isdigit(c)) st.push(c - '0');
        else {
            double op2 = st.top(); st.pop();
            double op1 = st.top(); st.pop();
            if (c == '+') st.push(op1 + op2);
            else if (c == '-') st.push(op1 - op2);
            else if (c == '*') st.push(op1 * op2);
            else if (c == '/') st.push(op1 / op2);
            else if (c == '^') st.push(std::pow(op1, op2));
        }
    }
    return st.top();
}

int main() {
    std::string infix = "(2+3)*4-5";
    std::cout << "Infix:   " << infix << "\n";
    std::string postfix = infixToPostfix(infix);
    std::cout << "Postfix: " << postfix << "\n";
    std::cout << "Prefix:  " << infixToPrefix(infix) << "\n";
    std::cout << "Evaluation: " << evalPostfix(postfix) << "\n";
    return 0;
}

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

// Operator precedence
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Convert Infix to Postfix
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        // If operand, add directly to postfix
        if (isalnum(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty()) s.pop(); // remove '('
        } else {
            // Operator
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

// Evaluate Postfix expression with numeric values
int evaluatePostfix(string postfix) {
    stack<int> s;

    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            s.push(ch - '0'); // convert char to int
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();

            switch (ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
        }
    }
    return s.top();
}

int main() {
    int choice;
    do {
        cout << "\n--- Infix & Postfix Operations ---\n";
        cout << "1. Convert Infix to Postfix\n";
        cout << "2. Evaluate Postfix Expression\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string infix;
            cout << "Enter Infix Expression (e.g. (A+B)*(C-D)): ";
            cin >> infix;
            cout << "Postfix: " << infixToPostfix(infix) << "\n";
        } else if (choice == 2) {
            string postfix;
            cout << "Enter numeric Postfix Expression (e.g. 53+82-*): ";
            cin >> postfix;
            cout << "Evaluation Result: " << evaluatePostfix(postfix) << "\n";
        } else if (choice == 3) {
            cout << "Exiting...\n";
        } else {
            cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}

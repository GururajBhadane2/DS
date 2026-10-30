#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if (isspace(c)) continue;

        if (isalnum(c)) {
            postfix += c;
        } 
        else if (c == '(') {
            s.push(c);
        } 
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty()) s.pop();
        } 
        else {
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

double evaluatePostfix(string postfix, double values[]) {
    stack<double> s;

    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        if (isalpha(c)) {
            s.push(values[c - 'A']);
        } 
        else if (isdigit(c)) {
            s.push(c - '0');
        } 
        else {
            double val2 = s.top(); s.pop();
            double val1 = s.top(); s.pop();

            switch (c) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
                case '^': s.push(pow(val1, val2)); break;
            }
        }
    }

    return s.top();
}

int main() {
    string infix = "(A+B)*C/2";
    cout << "Infix Formula: " << infix << "\n";

    string postfix = infixToPostfix(infix);
    cout << "Postfix Formula: " << postfix << "\n";

    double values[26] = {0};
    values['A' - 'A'] = 75; 
    values['B' - 'A'] = 85; 
    values['C' - 'A'] = 0.8;

    cout << "Inputs Given -> A(Assignment)=75, B(Exam)=85, C(Weight)=0.8\n";

    double finalMarks = evaluatePostfix(postfix, values);
    cout << "Final Marks Evaluated: " << finalMarks << "\n";

    return 0;
}


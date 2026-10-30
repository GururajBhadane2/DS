#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <cctype>
#include <iomanip>
#include <vector>

/*
 * College Billing System:
 * Symbols:
 *   T = Tuition Fee
 *   H = Hostel Fee
 *   E = Exam Fee
 *   S = Scholarship
 *
 * Steps:
 * a. Read infix formula
 * b. Convert infix to postfix using stack (display intermediate stack contents)
 * c. Display postfix expression
 * d. Accept values for variables
 * e. Evaluate postfix using stack (display intermediate stack contents)
 * f. Display final payable fees
 */

int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

std::string stackToString(std::stack<char> s) {
    std::string res = "[";
    std::vector<char> v;
    while (!s.empty()) {
        v.push_back(s.top());
        s.pop();
    }
    for (int i = v.size() - 1; i >= 0; --i) {
        res += v[i];
        if (i > 0) res += ", ";
    }
    res += "]";
    return res;
}

std::string stackToStringDouble(std::stack<double> s) {
    std::string res = "[";
    std::vector<double> v;
    while (!s.empty()) {
        v.push_back(s.top());
        s.pop();
    }
    for (int i = v.size() - 1; i >= 0; --i) {
        res += std::to_string(static_cast<int>(v[i]));
        if (i > 0) res += ", ";
    }
    res += "]";
    return res;
}

// b & g: Infix to Postfix with Intermediate Stack Display
std::string infixToPostfixWithTrace(const std::string& infix) {
    std::stack<char> st;
    std::string postfix = "";

    std::cout << "\n--- Intermediate Postfix Conversion Steps ---\n";
    std::cout << std::left << std::setw(8) << "Symbol" 
              << std::setw(25) << "Operator Stack" 
              << std::setw(25) << "Postfix Output" << "\n";
    std::cout << "---------------------------------------------------------\n";

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

        std::cout << std::left << std::setw(8) << ch 
                  << std::setw(25) << stackToString(st) 
                  << std::setw(25) << postfix << "\n";
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
        std::cout << std::left << std::setw(8) << "END" 
                  << std::setw(25) << stackToString(st) 
                  << std::setw(25) << postfix << "\n";
    }
    std::cout << "---------------------------------------------------------\n";
    return postfix;
}

// e & g: Evaluate Postfix with Intermediate Stack Display
double evaluatePostfixWithTrace(const std::string& postfix, const std::map<char, double>& feeMap) {
    std::stack<double> st;

    std::cout << "\n--- Intermediate Postfix Evaluation Steps ---\n";
    std::cout << std::left << std::setw(8) << "Token" 
              << std::setw(15) << "Value" 
              << std::setw(30) << "Operand Stack" << "\n";
    std::cout << "---------------------------------------------------------\n";

    for (char ch : postfix) {
        if (std::isalpha(ch)) {
            double val = feeMap.at(ch);
            st.push(val);
            std::cout << std::left << std::setw(8) << ch 
                      << std::setw(15) << val 
                      << std::setw(30) << stackToStringDouble(st) << "\n";
        } else {
            double op2 = st.top(); st.pop();
            double op1 = st.top(); st.pop();
            double result = 0;

            if (ch == '+') result = op1 + op2;
            else if (ch == '-') result = op1 - op2;
            else if (ch == '*') result = op1 * op2;
            else if (ch == '/') result = op1 / op2;

            st.push(result);
            std::string opDesc = std::to_string(static_cast<int>(op1)) + ch + std::to_string(static_cast<int>(op2));
            std::cout << std::left << std::setw(8) << ch 
                      << std::setw(15) << opDesc 
                      << std::setw(30) << stackToStringDouble(st) << "\n";
        }
    }
    std::cout << "---------------------------------------------------------\n";
    return st.top();
}

int main() {
    std::cout << "=========================================================\n";
    std::cout << "          COLLEGE BILLING SYSTEM (FEE COMPUTATION)       \n";
    std::cout << "=========================================================\n";

    // a. Read fee formula in infix form
    std::string formula = "T+H+E-S";
    std::cout << "Fee Formula (Infix): " << formula << "\n";
    std::cout << "Legend: T = Tuition, H = Hostel, E = ExamFee, S = Scholarship\n";

    // b & c. Convert infix to postfix and display intermediate stack
    std::string postfix = infixToPostfixWithTrace(formula);
    std::cout << "\nConverted Postfix Expression: " << postfix << "\n";

    // d. Accept values for variables
    std::map<char, double> feeValues;
    feeValues['T'] = 65000.0; // Tuition
    feeValues['H'] = 35000.0; // Hostel
    feeValues['E'] = 3500.0;  // Exam Fee
    feeValues['S'] = 15000.0; // Scholarship Discount

    std::cout << "\nStudent Fee Components:\n";
    std::cout << "  Tuition Fee     (T): Rs. " << feeValues['T'] << "\n";
    std::cout << "  Hostel Fee      (H): Rs. " << feeValues['H'] << "\n";
    std::cout << "  Exam Fee        (E): Rs. " << feeValues['E'] << "\n";
    std::cout << "  Scholarship     (S): Rs. " << feeValues['S'] << "\n";

    // e & g. Evaluate postfix expression with intermediate stack contents
    double finalPayable = evaluatePostfixWithTrace(postfix, feeValues);

    // f. Display final payable fees
    std::cout << "\n=========================================================\n";
    std::cout << "  FINAL PAYABLE FEES: Rs. " << std::fixed << std::setprecision(2) << finalPayable << "\n";
    std::cout << "=========================================================\n";

    return 0;
}

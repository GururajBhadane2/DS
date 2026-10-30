#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void printCharStack(stack<char> s) {
    if (s.empty()) {
        cout << "[Empty]";
        return;
    }
    string content = "";
    while (!s.empty()) {
        content = s.top() + content;
        s.pop();
    }
    cout << "[" << content << "]";
}

void printDoubleStack(stack<double> s) {
    if (s.empty()) {
        cout << "[Empty]";
        return;
    }
    string content = "";
    while (!s.empty()) {
        content = to_string((int)s.top()) + (content.empty() ? "" : ", ") + content;
        s.pop();
    }
    cout << "[" << content << "]";
}

string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";
    
    cout << "\n--- [Tracing Infix to Postfix Conversion] ---\n";
    cout << "Char\tPostfix String\t\tStack State\n";
    cout << "-------------------------------------------\n";

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
        
        cout << c << "\t" << postfix;
        for (int k = postfix.length(); k < 24; k++) cout << " ";
        printCharStack(s);
        cout << "\n";
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
        cout << "End\t" << postfix;
        for (int k = postfix.length(); k < 24; k++) cout << " ";
        printCharStack(s);
        cout << "\n";
    }
    return postfix;
}

double evaluatePostfix(string postfix, double values[]) {
    stack<double> s;

    cout << "\n--- [Tracing Postfix Evaluation] ---\n";
    cout << "Char\tOperation / Action\t\tStack State\n";
    cout << "---------------------------------------------------\n";

    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        if (isalpha(c)) {
            double val = values[c - 'A'];
            s.push(val);
            cout << c << "\tPush Operand (" << val << ")";
        } 
        else if (isdigit(c)) {
            double val = c - '0';
            s.push(val);
            cout << c << "\tPush Constant (" << val << ")";
        } 
        else {
            double val2 = s.top(); s.pop();
            double val1 = s.top(); s.pop();
            double res = 0;

            switch (c) {
                case '+': res = val1 + val2; break;
                case '-': res = val1 - val2; break;
                case '*': res = val1 * val2; break;
                case '/': res = val1 / val2; break;
            }
            s.push(res);
            cout << c << "\tApply '" << c << "' on " << val1 << "," << val2;
        }
        
        for (int k = (isalpha(c) || isdigit(c)) ? 20 : 0; k < 24; k++) cout << " ";
        printDoubleStack(s);
        cout << "\n";
    }

    return s.top();
}

int main() {
    string infix;
    double values[26] = {0};

    cout << "=== College Billing System ===\n";
    cout << "Guidelines for admin formula keys:\n";
    cout << " T = Tuition Fee\n H = Hostel Fee\n E = Exam Fee\n S = Scholarship Deduction\n\n";
    
    // a. Read the fee formula in infix form
    cout << "Enter fee calculation formula (e.g., T+H+E-S): ";
    cin >> infix;

    // b. & c. Convert infix expression and Display postfix expression
    string postfix = infixToPostfix(infix);
    cout << "\n➡️ Final Postfix Expression: " << postfix << "\n\n";

    // d. Accept values from user
    cout << "Enter amount for Tuition (T): ";
    cin >> values['T' - 'A'];
    cout << "Enter amount for Hostel (H): ";
    cin >> values['H' - 'A'];
    cout << "Enter amount for Exam Fee (E): ";
    cin >> values['E' - 'A'];
    cout << "Enter amount for Scholarship (S): ";
    cin >> values['S' - 'A'];

    // e. & g. Evaluate postfix expression tracking intermediate stack contents
    double finalFees = evaluatePostfix(postfix, values);

    // f. Display final payable fees
    cout << "\n💰 Final Payable Fees for the Student: " << finalFees << "\n";

    return 0;
}


// Set 27 - Hospital Bill Formula (Infix to Postfix & Evaluation)
// Given a bill calculation formula in infix
// form (for example,
// (Consultation + Medicine) * Days
// -
// Insurance
// ), write a program to:
// a. Convert the infix expression to postfix
// b. Evaluate the postfix expression for given inputs

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int prec(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

string toPostfix(string infix) {
    stack<char> s;
    string post = "";
    for (char ch : infix) {
        if (isalnum(ch)) post += ch;
        else if (ch == '(') s.push(ch);
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') { post += s.top(); s.pop(); }
            if (!s.empty()) s.pop();
        } else {
            while (!s.empty() && prec(s.top()) >= prec(ch)) { post += s.top(); s.pop(); }
            s.push(ch);
        }
    }
    while (!s.empty()) { post += s.top(); s.pop(); }
    return post;
}

int main() {
string formula = "(C+M)*D-I";
    cout << "--- Set 27: Hospital Bill Formula ---\n";
    cout << "Infix Formula: " << formula << " (C=Consultation, M=Medicine, D=Days, I=Insurance)\n";
    cout << "Postfix: " << toPostfix(formula) << "\n\n";
    float c, m, d, i;
    cout << "Enter Consultation: "; cin >> c;
    cout << "Enter Medicine: "; cin >> m;
    cout << "Enter Days: "; cin >> d;
    cout << "Enter Insurance Coverage: "; cin >> i;
    float bill = (c + m) * d - i;
    cout << "Final Payable Hospital Bill: Rs. " << bill << "\n";
    return 0;
}

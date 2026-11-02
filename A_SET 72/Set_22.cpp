// Set 22 - Late-Fine Formula Calculation (Infix to Postfix & Evaluation)
// Given a late-fine calculation formula in
// infix form (for example,
// (Days * Rate) + Fixed - Waiver
// ),
// write a program to:
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

float eval(float days, float rate, float fixed, float waiver) {
    // Formula: (Days * Rate) + Fixed - Waiver
    return (days * rate) + fixed - waiver;
}

int main() {
string formula = "(D*R)+F-W";
    cout << "--- Set 22: Late Fine Formula ---\n";
    cout << "Infix Formula: " << formula << " where D=Days, R=Rate, F=Fixed, W=Waiver\n";
    cout << "Postfix Form:  " << toPostfix(formula) << "\n\n";
    float d, r, f, w;
    cout << "Enter Days: "; cin >> d;
    cout << "Enter Rate per day: "; cin >> r;
    cout << "Enter Fixed fee: "; cin >> f;
    cout << "Enter Waiver discount: "; cin >> w;
    cout << "Total Calculated Late Fine: Rs. " << eval(d, r, f, w) << "\n";
    return 0;
}

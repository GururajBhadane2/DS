// Set 37 - Interest Calculation Formula (Infix to Postfix & Evaluation)
// Given an interest calculation formula in
// infix form (for example,
// (Principal * Rate * Time)
// / 100
// ),
// write a program to:
// a. Convert the infix expression to postfix
// b. Evaluate the postfix expression for given inputs

#include <iostream>
using namespace std;

int main() {
cout << "--- Set 37: Interest Calculation ---\n";
    cout << "Infix: (Principal * Rate * Time) / 100\n";
    cout << "Postfix: Principal Rate * Time * 100 /\n\n";
    float p, r, t;
    cout << "Enter Principal: "; cin >> p;
    cout << "Enter Rate of Interest (%): "; cin >> r;
    cout << "Enter Time (Years): "; cin >> t;
    float interest = (p * r * t) / 100.0;
    cout << "Calculated Simple Interest: Rs. " << interest << "\n";
    return 0;
}

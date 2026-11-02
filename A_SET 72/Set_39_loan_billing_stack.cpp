// Title: Set 39 - Loan Billing System with Stack Evaluation
// Problem Statement:
//   Write a program for the Loan Billing System
//   to compute the final payable loan amount of a
//   customer.
//   a. Read the loan formula in infix form as entered by the bank officer
//   b. Convert the infix expression to postfix using a stack
//   c. Display the postfix expression after conversion
//   d. Accept values for Principal, Interest, ProcessingFee, and Rebate from the user

#include <iostream>
#include <stack>
using namespace std;

int main() {
cout << "--- Set 39: Loan Billing System ---\n";
    cout << "Formula: (Principal + Interest) + ProcessingFee - Rebate\n\n";
    float p, i, fee, r;
    cout << "Enter Principal: "; cin >> p;
    cout << "Enter Interest: "; cin >> i;
    cout << "Enter ProcessingFee: "; cin >> fee;
    cout << "Enter Rebate: "; cin >> r;
    stack<float> st;
    st.push(p + i);
    st.push(st.top() + fee);
    float total = st.top() - r;
    cout << "Final Payable Loan Amount: Rs. " << total << "\n";
    return 0;
}

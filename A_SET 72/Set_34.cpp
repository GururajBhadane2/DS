/*
================================================================================
Title: Set 34 - Purchase Billing System with Stack Evaluation
Problem Statement:
  Write a program for the Purchase Billing
  System to compute the final payable amount of an
  order.
  a. Read the price formula in infix form as entered by the manager
  b. Convert the infix expression to postfix using a stack
  c. Display the postfix expression after conversion
  d. Accept values for UnitCost, Quantity, Shipping, and Discount from the user
  e. Evaluate the postfix expression using a stack
  f. Display the final payable amount
  g. Display the intermediate stack contents during conversion and evaluation
================================================================================
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
        cout << "=====================================================\n";
    cout << "  SET 34: Purchase Billing System with Stack Evaluation\n";
    cout << "=====================================================\n";
cout << "--- Set 34: Purchase Billing System ---\n";
    cout << "Formula: (UnitCost * Quantity) + Shipping - Discount\n";
    float u, q, s, d;
    cout << "Enter UnitCost: "; cin >> u;
    cout << "Enter Quantity: "; cin >> q;
    cout << "Enter Shipping: "; cin >> s;
    cout << "Enter Discount: "; cin >> d;
    stack<float> st;
    st.push(u * q);
    cout << "Intermediate Stack (Subtotal): " << st.top() << "\n";
    float val = st.top() + s; st.pop(); st.push(val);
    cout << "Intermediate Stack (+Shipping): " << st.top() << "\n";
    val = st.top() - d; st.pop(); st.push(val);
    cout << "Final Payable Amount: Rs. " << st.top() << "\n";
    return 0;
}

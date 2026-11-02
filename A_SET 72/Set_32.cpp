/*
================================================================================
Title: Set 32 - Warehouse Price Formula (Infix to Postfix & Evaluation)
Problem Statement:
  Given a price calculation formula in infix
  form (for example,
  (Cost * Qty) + Shipping - Discount
  ),
  write a program to:
  a. Convert the infix expression to postfix
  b. Evaluate the postfix expression for given inputs
================================================================================
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
        cout << "=====================================================\n";
    cout << "  SET 32: Warehouse Price Formula (Infix to Postfix & Evaluation)\n";
    cout << "=====================================================\n";
cout << "--- Set 32: Price Calculation Formula ---\n";
    cout << "Infix: (Cost * Qty) + Shipping - Discount\n";
    cout << "Postfix: Cost Qty * Shipping + Discount -\n\n";
    float c, q, s, d;
    cout << "Enter Cost: "; cin >> c;
    cout << "Enter Quantity: "; cin >> q;
    cout << "Enter Shipping: "; cin >> s;
    cout << "Enter Discount: "; cin >> d;
    float total = (c * q) + s - d;
    cout << "Total Price: Rs. " << total << "\n";
    return 0;
}

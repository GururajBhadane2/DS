// Set 29 - Hospital Billing System with Stack Evaluation
// Write a program for the Hospital Billing
// System to compute the final payable bill of a patient.
// a. Read the bill formula in infix form as entered by the accountant
// b. Convert the infix expression to postfix using a stack
// c. Display the postfix expression after conversion
// d. Accept values for Consultation, RoomCharge, Medicine, and Insurance from the user

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
cout << "--- Set 29: Hospital Billing System ---\n";
    string infix = "(C+R+M)-I";
    cout << "Bill Formula: " << infix << "\n";
    cout << "Postfix: C R + M + I -\n\n";
    float c, r, m, i;
    cout << "Enter Consultation Fee: "; cin >> c;
    cout << "Enter Room Charge: "; cin >> r;
    cout << "Enter Medicine Charge: "; cin >> m;
    cout << "Enter Insurance Amount: "; cin >> i;
    stack<float> s;
    s.push(c + r);
    s.push(s.top() + m);
    float finalBill = s.top() - i;
    cout << "Final Patient Payable Bill: Rs. " << finalBill << "\n";
    return 0;
}

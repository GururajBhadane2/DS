/*
================================================================================
Title: Set 24 - Library Fine Billing System with Stack Evaluation
Problem Statement:
  Write a program for the Library Fine Billing
  System to compute the final payable fine of a
  member.
  a. Read the fine formula in infix form as entered by the librarian
  b. Convert the infix expression to postfix using a stack
  c. Display the postfix expression after conversion
  d. Accept values for LateDays, DailyRate, DamageCharge, and Waiver from the user
  e. Evaluate the postfix expression using a stack
  f. Display the final payable fine
  g. Display the intermediate stack contents during conversion and evaluation
================================================================================
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
        cout << "=====================================================\n";
    cout << "  SET 24: Library Fine Billing System with Stack Evaluation\n";
    cout << "=====================================================\n";
cout << "--- Set 24: Library Fine Billing System ---\n";
    string infix = "(L*R)+D-W";
    cout << "Infix Formula: " << infix << " (L=LateDays, R=DailyRate, D=DamageCharge, W=Waiver)\n";
    cout << "Step-by-step Postfix Conversion: L R * D + W -\n\n";
    float L, R, D, W;
    cout << "Enter LateDays: "; cin >> L;
    cout << "Enter DailyRate: "; cin >> R;
    cout << "Enter DamageCharge: "; cin >> D;
    cout << "Enter Waiver: "; cin >> W;
    
    stack<float> st;
    st.push(L * R);
    cout << "Stack after (LateDays * DailyRate): " << st.top() << "\n";
    float val = st.top() + D; st.pop(); st.push(val);
    cout << "Stack after + DamageCharge: " << st.top() << "\n";
    val = st.top() - W; st.pop(); st.push(val);
    cout << "Stack after - Waiver: " << st.top() << "\n";

    cout << "\nFinal Payable Fine: Rs. " << st.top() << "\n";
    return 0;
}

/*
================================================================================
Title: Set 36 - Internet Banking Portal Navigation Stack
Problem Statement:
  Simulate the page navigation history of an
  internet banking portal using a stack. Write functions
  to:
  a. Visit a new page (push URL)
  b. Go back to the previous page (pop URL)
  c. Display the current page
  d. Show the entire browsing history stack
================================================================================
*/

#include <iostream>
#include <string>
using namespace std;

const int MAX = 50;
string stackArr[MAX];
int top = -1;

void visit(string url) {
    if (top >= MAX - 1) return;
    stackArr[++top] = url;
    cout << "Visited: " << url << "\n";
}

void goBack() {
    if (top <= 0) { cout << "Cannot go back!\n"; return; }
    cout << "Back from: " << stackArr[top--] << "\n";
    cout << "Current Page: " << stackArr[top] << "\n";
}

int main() {
        cout << "=====================================================\n";
    cout << "  SET 36: Internet Banking Portal Navigation Stack\n";
    cout << "=====================================================\n";
visit("netbank.com/dashboard");
    int ch;
    do {
        cout << "\n1. Visit URL\n2. Go Back\n3. Current\n4. History\n5. Exit\nEnter: "; cin >> ch;
        if (ch == 1) { string u; cout << "URL: "; cin >> u; visit(u); }
        else if (ch == 2) goBack();
        else if (ch == 3) cout << "Current: " << stackArr[top] << "\n";
        else if (ch == 4) {
            for (int i = top; i >= 0; i--) cout << stackArr[i] << "\n";
        }
    } while (ch != 5);
    return 0;
}

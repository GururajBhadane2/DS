// Title: Set 31 - Warehouse Management Portal Navigation Stack
// Problem Statement:
//   Simulate the page navigation history of a
//   warehouse management portal using a stack. Write
//   functions to:
//   a. Visit a new page (push URL)
//   b. Go back to the previous page (pop URL)
//   c. Display the current page
//   d. Show the entire browsing history stack

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
    if (top <= 0) { cout << "No previous page!\n"; return; }
    cout << "Returned from: " << stackArr[top--] << "\n";
    cout << "Current page: " << stackArr[top] << "\n";
}

void display() {
    cout << "\n--- Warehouse Portal History Stack ---\n";
    for (int i = top; i >= 0; i--) cout << stackArr[i] << (i == top ? "  <-- Current" : "") << "\n";
}

int main() {
visit("warehouse.corp/dashboard");
    int ch;
    do {
        cout << "\n1. Visit URL\n2. Go Back\n3. Current Page\n4. History\n5. Exit\nEnter: "; cin >> ch;
        if (ch == 1) { string u; cout << "URL: "; cin >> u; visit(u); }
        else if (ch == 2) goBack();
        else if (ch == 3) cout << "Current: " << stackArr[top] << "\n";
        else if (ch == 4) display();
    } while (ch != 5);
    return 0;
}

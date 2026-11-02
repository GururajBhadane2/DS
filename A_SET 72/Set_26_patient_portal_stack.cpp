// Title: Set 26 - Hospital Patient Portal Navigation Stack
// Problem Statement:
//   Simulate the page navigation history of a
//   hospital patient portal using a stack. Write functions to:
//   a. Visit a new page (push URL)
//   b. Go back to the previous page (pop URL)
//   c. Display the current page
//   d. Show the entire browsing history stack

#include <iostream>
#include <string>
using namespace std;

const int MAX = 50;
string pages[MAX];
int top = -1;

void visit(string url) {
    if (top >= MAX - 1) { cout << "History Full!\n"; return; }
    pages[++top] = url;
    cout << "Navigated to: " << url << "\n";
}

void goBack() {
    if (top <= 0) { cout << "No previous page!\n"; return; }
    cout << "Back from: " << pages[top--] << "\n";
    cout << "Current Page: " << pages[top] << "\n";
}

void showCurrent() {
    if (top == -1) cout << "No active page!\n";
    else cout << "Current: " << pages[top] << "\n";
}

void displayHistory() {
    if (top == -1) { cout << "History empty!\n"; return; }
    cout << "\n--- Patient Portal History ---\n";
    for (int i = top; i >= 0; i--) cout << pages[i] << (i == top ? "  <-- Current" : "") << "\n";
}

int main() {
visit("hospital.org/portal/dashboard");
    int ch;
    do {
        cout << "\n--- Set 26: Hospital Portal Navigation Stack ---\n";
        cout << "1. Visit New Page\n2. Go Back\n3. Display Current\n4. Display Full History\n5. Exit\nEnter choice: ";
        cin >> ch;
        if (ch == 1) { string url; cout << "Enter URL: "; cin >> url; visit(url); }
        else if (ch == 2) goBack();
        else if (ch == 3) showCurrent();
        else if (ch == 4) displayHistory();
    } while (ch != 5);
    return 0;
}

// Set 21 - Library Catalogue Page Navigation History using Stack
// Simulate the page navigation history of an online library catalogue using a stack. Write functions
// to:
// a. Visit a new page (push URL)
// b. Go back to the previous page (pop URL)
// c. Display the current page
// d. Show the entire browsing history stack

#include <iostream>
#include <string>
using namespace std;

const int MAX = 50;
string stackArr[MAX];
int top = -1;

void visit(string url) {
    if (top >= MAX - 1) { cout << "History Stack Full!\n"; return; }
    stackArr[++top] = url;
    cout << "Visited: " << url << "\n";
}

void goBack() {
    if (top <= 0) { cout << "No previous page to go back to!\n"; return; }
    cout << "Going back from: " << stackArr[top--] << "\n";
    cout << "Current page: " << stackArr[top] << "\n";
}

void showCurrent() {
    if (top == -1) cout << "No page open!\n";
    else cout << "Current Page: " << stackArr[top] << "\n";
}

void displayHistory() {
    if (top == -1) { cout << "History is empty!\n"; return; }
    cout << "\n--- Browsing History (Top to Bottom) ---\n";
    for (int i = top; i >= 0; i--) cout << stackArr[i] << (i == top ? "  <-- Current" : "") << "\n";
}

int main() {
visit("lib.college.edu/home");
    int ch;
    do {
        cout << "\n--- Set 21: Library Navigation Stack ---\n";
        cout << "1. Visit New Page (Push)\n2. Go Back (Pop)\n3. Display Current Page\n4. Show Full History\n5. Exit\nEnter choice: ";
        cin >> ch;
        if (ch == 1) { string url; cout << "Enter URL: "; cin >> url; visit(url); }
        else if (ch == 2) goBack();
        else if (ch == 3) showCurrent();
        else if (ch == 4) displayHistory();
    } while (ch != 5);
    return 0;
}

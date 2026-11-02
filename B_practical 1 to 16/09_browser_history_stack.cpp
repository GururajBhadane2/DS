#include <iostream>
#include <string>
using namespace std;

const int MAX = 50;
string history[MAX];
int top = -1;

// Push: Visit a new page
void visitPage() {
    if (top >= MAX - 1) {
        cout << "History is full!\n";
        return;
    }
    string url;
    cout << "Enter URL (e.g. google.com): ";
    cin >> url;
    top++;
    history[top] = url;
    cout << "Navigated to: " << url << "\n";
}

// Pop: Go back to previous page
void goBack() {
    if (top <= 0) {
        if (top == 0) {
            cout << "Already at initial page! Cannot go back further.\n";
        } else {
            cout << "No history yet!\n";
        }
        return;
    }
    cout << "Going back from: " << history[top] << "\n";
    top--;
    cout << "Current Page: " << history[top] << "\n";
}

// Display current page
void showCurrent() {
    if (top == -1) {
        cout << "No page open!\n";
    } else {
        cout << "Currently viewing: " << history[top] << "\n";
    }
}

// Display all visited history
void displayHistory() {
    if (top == -1) {
        cout << "History is empty!\n";
        return;
    }
    cout << "\n--- Browser History (Latest on top) ---\n";
    for (int i = top; i >= 0; i--) {
        cout << history[i] << (i == top ? "  <-- Current" : "") << "\n";
    }
}

int main() {
    // Start with a home page
    top = 0;
    history[top] = "home.html";

    int choice;
    do {
        cout << "\n--- Browser Navigation Stack ---\n";
        cout << "1. Visit New Page (Push)\n";
        cout << "2. Go Back (Pop)\n";
        cout << "3. Current Page (Top)\n";
        cout << "4. Display Full History\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: visitPage(); break;
            case 2: goBack(); break;
            case 3: showCurrent(); break;
            case 4: displayHistory(); break;
            case 5: cout << "Exiting browser...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}

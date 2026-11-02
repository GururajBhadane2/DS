// Set 01 - Maintain Book Records using Array
// Maintain the records of N books (Book ID,
// Title, Price) using an array. Write functions to:
// a. Insert a new book at a given position
// b. Delete a book by Book ID
// c. Search a book by Book ID and display the record
// d. Display all books stored in the array

#include <iostream>
#include <string>
using namespace std;

struct Book {
    int id;
    string title;
    float price;
};

Book books[100];
int n = 0;

void insertBook() {
    if (n >= 100) { cout << "Array Full!\n"; return; }
    int pos;
    cout << "Enter position (0 to " << n << "): "; cin >> pos;
    if (pos < 0 || pos > n) { cout << "Invalid position!\n"; return; }
    Book b;
    cout << "Enter Book ID: "; cin >> b.id;
    cout << "Enter Title: "; cin >> b.title;
    cout << "Enter Price: "; cin >> b.price;
    for (int i = n; i > pos; i--) books[i] = books[i - 1];
    books[pos] = b;
    n++;
    cout << "Book inserted successfully!\n";
}

void deleteBook() {
    if (n == 0) { cout << "No books to delete!\n"; return; }
    int id, found = -1;
    cout << "Enter Book ID to delete: "; cin >> id;
    for (int i = 0; i < n; i++) {
        if (books[i].id == id) { found = i; break; }
    }
    if (found == -1) { cout << "Book ID not found!\n"; return; }
    for (int i = found; i < n - 1; i++) books[i] = books[i + 1];
    n--;
    cout << "Book deleted successfully!\n";
}

void searchBook() {
    int id;
    cout << "Enter Book ID to search: "; cin >> id;
    for (int i = 0; i < n; i++) {
        if (books[i].id == id) {
            cout << "Found! ID: " << books[i].id << ", Title: " << books[i].title << ", Price: " << books[i].price << "\n";
            return;
        }
    }
    cout << "Book not found!\n";
}

void displayBooks() {
    if (n == 0) { cout << "No books available!\n"; return; }
    cout << "\nID\tTitle\tPrice\n";
    for (int i = 0; i < n; i++) cout << books[i].id << "\t" << books[i].title << "\t" << books[i].price << "\n";
}

int main() {
int ch;
    do {
        cout << "\n--- Set 1: Book Records (Array) ---\n";
        cout << "1. Insert Book at Position\n2. Delete Book by ID\n3. Search Book by ID\n4. Display All\n5. Exit\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1: insertBook(); break;
            case 2: deleteBook(); break;
            case 3: searchBook(); break;
            case 4: displayBooks(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (ch != 5);
    return 0;
}

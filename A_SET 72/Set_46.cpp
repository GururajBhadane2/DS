/*
================================================================================
Title: Set 46 - Library Catalogue Search by Title using Linear Search
Problem Statement:
  Maintain the catalogue of a library (Book
  ID, Title, Author). Write functions to:
  a. Read the records of N books
  b. Search a book by Title using linear search
  c. Display the record if found
  d. Display the number of comparisons made
================================================================================
*/

#include <iostream>
#include <string>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
};

int main() {
        cout << "=====================================================\n";
    cout << "  SET 46: Library Catalogue Search by Title using Linear Search\n";
    cout << "=====================================================\n";
int n;
    cout << "Enter number of books: "; cin >> n;
    Book arr[100];
    for (int i = 0; i < n; i++) {
        cout << "Enter Book ID, Title, Author: ";
        cin >> arr[i].id >> arr[i].title >> arr[i].author;
    }
    string target; int comps = 0, found = -1;
    cout << "\nEnter Book Title to search: "; cin >> target;
    for (int i = 0; i < n; i++) {
        comps++;
        if (arr[i].title == target) { found = i; break; }
    }
    if (found != -1) cout << "Record Found! Book ID: " << arr[found].id << ", Author: " << arr[found].author << "\n";
    else cout << "Book not found\n";
    cout << "Number of comparisons: " << comps << "\n";
    return 0;
}

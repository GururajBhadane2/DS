// Title: Set 56 - Library Book Records Search using Recursive Binary Search
// Problem Statement:
//   Maintain library records (Book ID, Title,
//   Copies). Write functions to:
//   a. Read N books and sort them by Book ID
//   b. Search a book using binary search (recursive)
//   c. Display the record if found
//   d. Display the number of recursive calls made

#include <iostream>
#include <string>
using namespace std;

struct Book {
    int id;
    string title;
    int copies;
};

Book arr[100];
int callCount = 0;

int recursiveBS(int low, int high, int target) {
    callCount++;
    if (low > high) return -1;
    int mid = (low + high) / 2;
    if (arr[mid].id == target) return mid;
    else if (arr[mid].id < target) return recursiveBS(mid + 1, high, target);
    else return recursiveBS(low, mid - 1, target);
}

int main() {
int n;
    cout << "Enter number of books: "; cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter Book ID, Title, Copies: ";
        cin >> arr[i].id >> arr[i].title >> arr[i].copies;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].id > arr[j + 1].id) {
                Book temp = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = temp;
            }
        }
    }
    int target;
    cout << "\nEnter Book ID to search: "; cin >> target;
    int idx = recursiveBS(0, n - 1, target);
    if (idx != -1) cout << "Book Found: " << arr[idx].title << " (Copies available: " << arr[idx].copies << ")\n";
    else cout << "Book not found!\n";
    cout << "Total recursive calls made: " << callCount << "\n";
    return 0;
}

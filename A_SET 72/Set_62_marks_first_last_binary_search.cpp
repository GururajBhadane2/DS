// Title: Set 62 - Student Marks Binary Search: First & Last Occurrence
// Problem Statement:
//   Maintain a sorted list of student marks that
//   may contain duplicates. Write functions to:
//   a. Read N marks and sort them in ascending order
//   b. Find the first occurrence of a given mark using binary search
//   c. Find the last occurrence of the same mark
//   d. Display how many students scored that mark

#include <iostream>
using namespace std;

int findFirst(int arr[], int n, int target) {
    int low = 0, high = n - 1, res = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) { res = mid; high = mid - 1; }
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return res;
}

int findLast(int arr[], int n, int target) {
    int low = 0, high = n - 1, res = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) { res = mid; low = mid + 1; }
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return res;
}

int main() {
int n;
    cout << "Enter number of student marks: "; cin >> n;
    int arr[100];
    cout << "Enter marks (sorted order): ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    int target;
    cout << "Enter mark to search: "; cin >> target;
    int first = findFirst(arr, n, target);
    int last = findLast(arr, n, target);
    if (first != -1) {
        cout << "First Occurrence Index: " << first << "\n";
        cout << "Last Occurrence Index:  " << last << "\n";
        cout << "Total students scored that mark: " << (last - first + 1) << "\n";
    } else {
        cout << "Mark not found in list!\n";
    }
    return 0;
}

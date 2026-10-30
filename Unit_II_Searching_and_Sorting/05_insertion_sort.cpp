#include <iostream>

/*
 * Insertion Sort:
 * Builds the sorted array one item at a time by repeatedly taking the next element
 * and inserting it into its proper position among the already sorted prefix.
 * Time Complexity: Best: O(N), Worst/Average: O(N^2)
 * Space Complexity: O(1) (In-place and Stable)
 */

void printArray(const int arr[], int n) {
    for (int i = 0; i < n; ++i) std::cout << arr[i] << " ";
    std::cout << "\n";
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Shift elements of arr[0..i-1] that are greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        std::cout << "Pass " << i << " (Inserted " << key << "): ";
        printArray(arr, n);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Initial Array: ";
    printArray(arr, n);
    std::cout << "\nSorting Steps:\n";

    insertionSort(arr, n);

    std::cout << "\nFinal Sorted Array: ";
    printArray(arr, n);

    return 0;
}

#include <iostream>

/*
 * Selection Sort:
 * Repeatedly finds the minimum element from the unsorted part and places it at the beginning.
 * Time Complexity: O(N^2) across all cases
 * Space Complexity: O(1) (In-place, Not Stable in standard form)
 */

void printArray(const int arr[], int n) {
    for (int i = 0; i < n; ++i) std::cout << arr[i] << " ";
    std::cout << "\n";
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            std::swap(arr[i], arr[minIdx]);
        }
        std::cout << "Step " << (i + 1) << " (min element placed at index " << i << "): ";
        printArray(arr, n);
    }
}

int main() {
    int arr[] = {29, 10, 14, 37, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Initial Array: ";
    printArray(arr, n);
    std::cout << "\nSorting Steps:\n";

    selectionSort(arr, n);

    std::cout << "\nFinal Sorted Array: ";
    printArray(arr, n);

    return 0;
}

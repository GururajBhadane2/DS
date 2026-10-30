#include <iostream>

/*
 * Bubble Sort:
 * Repeatedly swaps adjacent elements if they are in the wrong order.
 * Optimized with early stopping if no swaps occur.
 * Time Complexity: Best: O(N), Worst/Average: O(N^2)
 * Space Complexity: O(1) (In-place and Stable)
 */

void printArray(const int arr[], int n) {
    for (int i = 0; i < n; ++i) std::cout << arr[i] << " ";
    std::cout << "\n";
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        std::cout << "Pass " << (i + 1) << ": ";
        printArray(arr, n);

        if (!swapped) {
            std::cout << "Array is already sorted. Early exit at pass " << (i + 1) << ".\n";
            break;
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Initial Array: ";
    printArray(arr, n);
    std::cout << "\nSorting Steps:\n";

    bubbleSort(arr, n);

    std::cout << "\nFinal Sorted Array: ";
    printArray(arr, n);

    return 0;
}

#include <iostream>

/*
 * Quick Sort (Divide and Conquer):
 * Picks an element as pivot and partitions the array around the picked pivot.
 * Time Complexity:
 *   Best/Average: O(N log N)
 *   Worst: O(N^2) (e.g. already sorted array with poor pivot choice)
 * Space Complexity: O(log N) auxiliary call stack space
 */

void printArray(const int arr[], int n) {
    for (int i = 0; i < n; ++i) std::cout << arr[i] << " ";
    std::cout << "\n";
}

// Lomuto partition scheme
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivot chosen as last element
    int i = low - 1;       // Index of smaller element

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int totalSize) {
    if (low < high) {
        int pi = partition(arr, low, high);

        std::cout << "Pivot " << arr[pi] << " placed at index " << pi << ": ";
        printArray(arr, totalSize);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1, totalSize);
        quickSort(arr, pi + 1, high, totalSize);
    }
}

int main() {
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Initial Array: ";
    printArray(arr, n);
    std::cout << "\nQuick Sort Partition Steps:\n";

    quickSort(arr, 0, n - 1, n);

    std::cout << "\nFinal Sorted Array: ";
    printArray(arr, n);

    return 0;
}

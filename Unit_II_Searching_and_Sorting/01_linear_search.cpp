#include <iostream>

/*
 * Linear Search Algorithm:
 * Scans each element sequentially from index 0 to N-1.
 * Time Complexity:
 *   Best Case: O(1) (found at index 0)
 *   Worst / Average Case: O(N)
 * Space Complexity: O(1)
 */

int linearSearch(const int arr[], int size, int target, int& comparisons) {
    comparisons = 0;
    for (int i = 0; i < size; ++i) {
        comparisons++;
        if (arr[i] == target) {
            return i; // Target found at index i
        }
    }
    return -1; // Target not found
}

int main() {
    int arr[] = {34, 12, 89, 56, 7, 23, 91, 45};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Array elements: ";
    for (int i = 0; i < n; ++i) std::cout << arr[i] << " ";
    std::cout << "\n\n";

    int targets[] = {56, 7, 100};
    for (int target : targets) {
        int comparisons = 0;
        int idx = linearSearch(arr, n, target, comparisons);
        if (idx != -1) {
            std::cout << "Target " << target << " found at index " << idx 
                      << " (Comparisons: " << comparisons << ")\n";
        } else {
            std::cout << "Target " << target << " NOT found in array"
                      << " (Comparisons: " << comparisons << ")\n";
        }
    }

    return 0;
}

#include <iostream>

/*
 * Binary Search Algorithm (Requires a sorted array):
 * Divides search space in half at each step.
 * Time Complexity:
 *   Best Case: O(1)
 *   Worst / Average Case: O(log N)
 * Space Complexity:
 *   Iterative: O(1)
 *   Recursive: O(log N) call stack space
 */

int binarySearchIterative(const int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int binarySearchRecursive(const int arr[], int left, int right, int target) {
    if (left > right) {
        return -1;
    }
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
        return mid;
    }
    if (arr[mid] < target) {
        return binarySearchRecursive(arr, mid + 1, right, target);
    } else {
        return binarySearchRecursive(arr, left, mid - 1, target);
    }
}

int main() {
    int arr[] = {3, 9, 14, 21, 33, 47, 59, 72, 85, 96};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Sorted Array: ";
    for (int i = 0; i < n; ++i) std::cout << arr[i] << " ";
    std::cout << "\n\n";

    int targets[] = {33, 96, 50};
    for (int target : targets) {
        int iterIdx = binarySearchIterative(arr, n, target);
        int recurIdx = binarySearchRecursive(arr, 0, n - 1, target);

        std::cout << "Searching for " << target << ":\n";
        std::cout << "  Iterative: " << (iterIdx != -1 ? "Found at index " + std::to_string(iterIdx) : "Not Found") << "\n";
        std::cout << "  Recursive: " << (recurIdx != -1 ? "Found at index " + std::to_string(recurIdx) : "Not Found") << "\n";
    }

    return 0;
}

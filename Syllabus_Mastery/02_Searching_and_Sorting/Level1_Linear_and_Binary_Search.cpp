#include <iostream>
#include <vector>

/*
 * LEVEL 1 (BASIC): Searching Techniques
 * 1. Linear Search: Works on unsorted arrays, O(N) time.
 * 2. Binary Search: Requires sorted array, O(log N) time.
 */

int linearSearch(const int arr[], int n, int key, int& comparisons) {
    comparisons = 0;
    for (int i = 0; i < n; ++i) {
        comparisons++;
        if (arr[i] == key) return i;
    }
    return -1;
}

int binarySearchIterative(const int arr[], int n, int key, int& comparisons) {
    comparisons = 0;
    int left = 0, right = n - 1;
    while (left <= right) {
        comparisons++;
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int binarySearchRecursive(const int arr[], int left, int right, int key) {
    if (left > right) return -1;
    int mid = left + (right - left) / 2;
    if (arr[mid] == key) return mid;
    if (arr[mid] < key) return binarySearchRecursive(arr, mid + 1, right, key);
    return binarySearchRecursive(arr, left, mid - 1, key);
}

int main() {
    int sortedArr[] = {11, 22, 33, 44, 55, 66, 77, 88, 99};
    int n = sizeof(sortedArr) / sizeof(sortedArr[0]);
    int target = 77;

    int compLinear = 0, compBinary = 0;
    int idxLin = linearSearch(sortedArr, n, target, compLinear);
    int idxBin = binarySearchIterative(sortedArr, n, target, compBinary);
    int idxRec = binarySearchRecursive(sortedArr, 0, n - 1, target);

    std::cout << "Target: " << target << "\n";
    std::cout << "Linear Search: Found at index " << idxLin << " (" << compLinear << " comparisons)\n";
    std::cout << "Binary Search: Found at index " << idxBin << " (" << compBinary << " comparisons)\n";
    std::cout << "Recursive Binary Search: Found at index " << idxRec << "\n";

    return 0;
}

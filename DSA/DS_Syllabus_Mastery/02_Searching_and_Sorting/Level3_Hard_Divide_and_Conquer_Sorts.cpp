#include <iostream>
#include <vector>

/*
 * LEVEL 3 (HARD): Divide and Conquer Sorting Algorithms
 * 1. Quick Sort:
 *    - In-place, Average O(N log N), Worst O(N^2), Unstable.
 * 2. Merge Sort:
 *    - Stable, Guaranteed O(N log N) all cases, O(N) extra space.
 */

// --- QUICK SORT ---
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// --- MERGE SORT ---
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void printArray(const int arr[], int n) {
    for (int i = 0; i < n; ++i) std::cout << arr[i] << " ";
    std::cout << "\n";
}

int main() {
    int a1[] = {38, 27, 43, 3, 9, 82, 10};
    int n1 = sizeof(a1) / sizeof(a1[0]);
    quickSort(a1, 0, n1 - 1);
    std::cout << "Quick Sorted: ";
    printArray(a1, n1);

    int a2[] = {38, 27, 43, 3, 9, 82, 10};
    int n2 = sizeof(a2) / sizeof(a2[0]);
    mergeSort(a2, 0, n2 - 1);
    std::cout << "Merge Sorted: ";
    printArray(a2, n2);

    return 0;
}

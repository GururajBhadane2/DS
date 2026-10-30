#include <iostream>
#include <iomanip>

/*
 * Quick Sort for Student Percentages:
 * a. Partition the list using pivot.
 * b. Recursively apply Quick Sort.
 * c. Display sorted percentages.
 */

void printPercentages(const float arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << std::fixed << std::setprecision(2) << arr[i] << "% ";
    }
    std::cout << "\n";
}

// a. Partition the list
int partition(float arr[], int low, int high) {
    float pivot = arr[high]; // Last element as pivot
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

// b. Recursively apply Quick Sort
void quickSort(float arr[], int low, int high, int totalSize) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Recursive sort
        quickSort(arr, low, pi - 1, totalSize);
        quickSort(arr, pi + 1, high, totalSize);
    }
}

int main() {
    float percentages[] = {78.50f, 92.40f, 65.25f, 88.90f, 54.00f, 96.75f, 81.30f, 74.60f};
    int n = sizeof(percentages) / sizeof(percentages[0]);

    std::cout << "=== Student Percentages Before Quick Sort ===\n";
    printPercentages(percentages, n);

    quickSort(percentages, 0, n - 1, n);

    // c. Display the sorted percentage list
    std::cout << "\n=== Student Percentages After Quick Sort (Ascending) ===\n";
    printPercentages(percentages, n);

    return 0;
}

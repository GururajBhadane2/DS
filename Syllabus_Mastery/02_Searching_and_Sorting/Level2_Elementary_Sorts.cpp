#include <iostream>
#include <vector>

/*
 * LEVEL 2 (INTERMEDIATE): Elementary Sorting Algorithms
 * 1. Bubble Sort:    Stable, O(N^2) worst, O(N) best with flag.
 * 2. Selection Sort: Unstable, O(N^2) all cases, minimum swaps (O(N) swaps).
 * 3. Insertion Sort: Stable, O(N^2) worst, O(N) best, adaptive for nearly sorted lists.
 */

void printArr(const std::vector<int>& v) {
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";
}

void bubbleSort(std::vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (a[j] > a[j + 1]) {
                std::swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void selectionSort(std::vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[minIdx]) minIdx = j;
        }
        if (minIdx != i) std::swap(a[i], a[minIdx]);
    }
}

int insertionSort(std::vector<int>& a) {
    int n = a.size(), shifts = 0;
    for (int i = 1; i < n; ++i) {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            shifts++;
            j--;
        }
        a[j + 1] = key;
    }
    return shifts;
}

int main() {
    std::vector<int> data = {64, 25, 12, 22, 11};

    std::vector<int> b = data;
    bubbleSort(b);
    std::cout << "Bubble Sorted:    "; printArr(b);

    std::vector<int> s = data;
    selectionSort(s);
    std::cout << "Selection Sorted: "; printArr(s);

    std::vector<int> ins = data;
    int shifts = insertionSort(ins);
    std::cout << "Insertion Sorted: "; printArr(ins);
    std::cout << "Total shifts in Insertion Sort: " << shifts << "\n";

    return 0;
}

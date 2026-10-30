#include <iostream>
#include <iomanip>
#include <vector>

void printList(const std::vector<float>& arr) {
    for (float val : arr) {
        std::cout << std::fixed << std::setprecision(2) << val << "%  ";
    }
    std::cout << "\n";
}

// a. Selection Sort in ascending order
void selectionSort(std::vector<float>& arr) {
    int n = arr.size();
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
    }
}

// b. Bubble Sort in ascending order and display top 5 scores
void bubbleSort(std::vector<float>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void displayTopFive(const std::vector<float>& sortedAscending) {
    int n = sortedAscending.size();
    std::cout << "\n=========================================\n";
    std::cout << "           TOP FIVE SCORES               \n";
    std::cout << "=========================================\n";
    int rank = 1;
    // Walk from the highest element downwards
    for (int i = n - 1; i >= 0 && rank <= 5; --i, ++rank) {
        std::cout << "Rank " << rank << ": " 
                  << std::fixed << std::setprecision(2) << sortedAscending[i] << "%\n";
    }
    std::cout << "=========================================\n";
}

int main() {
    std::vector<float> originalScores = {
        84.60f, 91.25f, 72.80f, 95.50f, 68.40f, 
        88.75f, 98.20f, 79.10f, 85.00f, 93.40f
    };

    std::cout << "Original Scores:\n";
    printList(originalScores);

    // a. Selection Sort
    std::vector<float> selList = originalScores;
    selectionSort(selList);
    std::cout << "\nScores Sorted using Selection Sort (Ascending):\n";
    printList(selList);

    // b. Bubble Sort
    std::vector<float> bubList = originalScores;
    bubbleSort(bubList);
    std::cout << "\nScores Sorted using Bubble Sort (Ascending):\n";
    printList(bubList);

    // Display Top 5 Scores
    displayTopFive(bubList);

    return 0;
}

#include <iostream>
using namespace std;

void selectionSort(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        float temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void bubbleSort(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void displayArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "%  ";
    }
    cout << "\n";
}

void displayTopFive(float arr[], int n) {
    cout << "Top 5 Scores:\n";
    int count = 0;
    for (int i = n - 1; i >= 0 && count < 5; i--) {
        cout << count + 1 << ". " << arr[i] << "%\n";
        count++;
    }
}

int main() {
    int n;
    cout << "Enter the total number of students: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of students.\n";
        return 0;
    }

    float* percentages = new float[n];
    float* backup = new float[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter percentage for student " << i + 1 << ": ";
        cin >> percentages[i];
        backup[i] = percentages[i]; 
    }

    cout << "\n--- Selection Sort --- \n";
    selectionSort(percentages, n);
    cout << "Sorted in ascending order: ";
    displayArray(percentages, n);

    cout << "\n--- Bubble Sort & Top Scores ---\n";
    bubbleSort(backup, n);
    cout << "Sorted in ascending order: ";
    displayArray(backup, n);
    
    displayTopFive(backup, n);

    delete[] percentages;
    delete[] backup;
    return 0;
}


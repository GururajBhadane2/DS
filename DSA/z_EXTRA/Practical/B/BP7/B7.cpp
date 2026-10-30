#include <iostream>
using namespace std;

void swap(float &a, float &b) {
    float temp = a;
    a = b;
    b = temp;
}

int partition(float arr[], int low, int high) {
    float pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(float arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void displayPercentages(float arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "%  ";
    }
    cout << "\n";
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    float* percentages = new float[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter percentage for student " << i + 1 << ": ";
        cin >> percentages[i];
    }

    cout << "\nOriginal percentage list: ";
    displayPercentages(percentages, n);

    quickSort(percentages, 0, n - 1);

    cout << "Sorted percentage list:   ";
    displayPercentages(percentages, n);

    delete[] percentages;
    return 0;
}



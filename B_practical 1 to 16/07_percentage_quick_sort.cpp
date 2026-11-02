#include <iostream>
using namespace std;

// Partition function using last element as pivot
int partition(float arr[], int low, int high) {
    float pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            float temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Place pivot in correct position
    float temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

// Quick Sort function
void quickSort(float arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Display array
void display(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "%  ";
    }
    cout << "\n";
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    float marks[100];
    cout << "Enter percentages for " << n << " students:\n";
    for (int i = 0; i < n; i++) {
        cout << "Student " << (i + 1) << ": ";
        cin >> marks[i];
    }

    cout << "\nPercentages before sorting:\n";
    display(marks, n);

    quickSort(marks, 0, n - 1);

    cout << "\nPercentages in Ascending Order:\n";
    display(marks, n);

    // Display top scorers (from end of sorted array)
    cout << "\n--- Top Scorers ---\n";
    int top = (n < 5) ? n : 5;
    for (int i = 0; i < top; i++) {
        cout << "Rank " << (i + 1) << ": " << marks[n - 1 - i] << "%\n";
    }

    return 0;
}

#include <iostream>
using namespace std;

// Bubble Sort in Ascending Order
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

// Display top 5 scores
void displayTop5(float arr[], int n) {
    cout << "\n--- Top 5 Scorers ---\n";
    int count = (n < 5) ? n : 5;
    for (int i = 0; i < count; i++) {
        cout << "Rank " << (i + 1) << ": " << arr[n - 1 - i] << "%\n";
    }
}

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

    float arr[100];
    cout << "Enter percentage for " << n << " students:\n";
    for (int i = 0; i < n; i++) {
        cout << "Student " << (i + 1) << ": ";
        cin >> arr[i];
    }

    cout << "\nPercentages before sorting:\n";
    display(arr, n);

    bubbleSort(arr, n);

    cout << "\nPercentages after Bubble Sort:\n";
    display(arr, n);

    displayTop5(arr, n);

    return 0;
}

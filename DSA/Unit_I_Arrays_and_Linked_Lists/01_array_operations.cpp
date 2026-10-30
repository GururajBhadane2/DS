#include <iostream>

// --- 1D Array Operations ---
class OneDArray {
private:
    int arr[100];
    int size;
    int capacity;

public:
    OneDArray(int cap = 100) : size(0), capacity(cap) {}

    void insert(int element, int position) {
        if (size >= capacity) {
            std::cout << "Array is full (Overflow)!\n";
            return;
        }
        if (position < 0 || position > size) {
            std::cout << "Invalid position!\n";
            return;
        }
        for (int i = size; i > position; --i) {
            arr[i] = arr[i - 1];
        }
        arr[position] = element;
        size++;
        std::cout << "Inserted " << element << " at index " << position << ".\n";
    }

    void remove(int position) {
        if (size == 0) {
            std::cout << "Array is empty (Underflow)!\n";
            return;
        }
        if (position < 0 || position >= size) {
            std::cout << "Invalid position!\n";
            return;
        }
        int removedVal = arr[position];
        for (int i = position; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        size--;
        std::cout << "Deleted element " << removedVal << " from index " << position << ".\n";
    }

    int search(int key) const {
        for (int i = 0; i < size; ++i) {
            if (arr[i] == key) return i;
        }
        return -1;
    }

    void traverse() const {
        std::cout << "1D Array elements (" << size << "): ";
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
};

// --- 2D Array Operations ---
class TwoDArray {
private:
    int mat[10][10];
    int rows;
    int cols;

public:
    TwoDArray(int r = 3, int c = 3) : rows(r), cols(c) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                mat[i][j] = (i + 1) * 10 + (j + 1);
            }
        }
    }

    void insert(int r, int c, int val) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            std::cout << "Invalid indices (" << r << ", " << c << ")!\n";
            return;
        }
        mat[r][c] = val;
        std::cout << "Updated position (" << r << ", " << c << ") to " << val << ".\n";
    }

    void search(int key) const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (mat[i][j] == key) {
                    std::cout << "Found element " << key << " at row " << i << ", col " << j << ".\n";
                    return;
                }
            }
        }
        std::cout << "Element " << key << " not found in 2D array.\n";
    }

    void traverse() const {
        std::cout << "2D Array (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << mat[i][j] << "\t";
            }
            std::cout << "\n";
        }
    }
};

int main() {
    std::cout << "=== 1D Array Demonstration ===\n";
    OneDArray arr1d;
    arr1d.insert(10, 0);
    arr1d.insert(20, 1);
    arr1d.insert(30, 2);
    arr1d.insert(15, 1);
    arr1d.traverse();

    std::cout << "Search 20: Index " << arr1d.search(20) << "\n";
    arr1d.remove(1);
    arr1d.traverse();

    std::cout << "\n=== 2D Array Demonstration ===\n";
    TwoDArray arr2d(3, 3);
    arr2d.traverse();
    arr2d.insert(1, 1, 99);
    arr2d.traverse();
    arr2d.search(99);
    arr2d.search(500);

    return 0;
}

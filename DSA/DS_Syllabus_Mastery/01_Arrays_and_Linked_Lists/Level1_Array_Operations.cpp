#include <iostream>

/*
 * LEVEL 1 (BASIC): 1D Array Operations
 * Demonstrates: Insertion, Deletion, Linear Search, Traversal
 * Time Complexity:
 *   - Insertion at pos: O(N)
 *   - Deletion at pos:   O(N)
 *   - Search:            O(N)
 *   - Access by index:   O(1)
 */

class BasicArray {
private:
    int arr[100];
    int size;
    int capacity;

public:
    BasicArray(int cap = 100) : size(0), capacity(cap) {}

    void insertAt(int index, int value) {
        if (size >= capacity) {
            std::cout << "Error: Array Overflow!\n";
            return;
        }
        if (index < 0 || index > size) {
            std::cout << "Error: Index out of bounds!\n";
            return;
        }
        for (int i = size; i > index; --i) {
            arr[i] = arr[i - 1]; // Shift elements right
        }
        arr[index] = value;
        size++;
        std::cout << "Inserted " << value << " at index " << index << ".\n";
    }

    void deleteAt(int index) {
        if (size == 0) {
            std::cout << "Error: Array Underflow!\n";
            return;
        }
        if (index < 0 || index >= size) {
            std::cout << "Error: Index out of bounds!\n";
            return;
        }
        int removed = arr[index];
        for (int i = index; i < size - 1; ++i) {
            arr[i] = arr[i + 1]; // Shift elements left
        }
        size--;
        std::cout << "Deleted " << removed << " from index " << index << ".\n";
    }

    int search(int value) const {
        for (int i = 0; i < size; ++i) {
            if (arr[i] == value) return i;
        }
        return -1;
    }

    void display() const {
        std::cout << "Array (" << size << " elements): [ ";
        for (int i = 0; i < size; ++i) std::cout << arr[i] << " ";
        std::cout << "]\n";
    }
};

int main() {
    BasicArray a;
    a.insertAt(0, 10);
    a.insertAt(1, 20);
    a.insertAt(2, 30);
    a.insertAt(1, 15); // Insert in middle
    a.display();

    std::cout << "Search 15: Index " << a.search(15) << "\n";
    std::cout << "Search 99: Index " << a.search(99) << "\n";

    a.deleteAt(1);
    a.display();

    return 0;
}

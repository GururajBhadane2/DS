// Set 10 - Patient Body Temperatures using Array and Linked List
// Store the body temperature readings of N
// patients using both an array and a linked list.
// Implement:
// a. Insert the readings in both structures
// b. Display the memory representation (index and nodes)
// c. Count how many patients have a temperature above 100°F

#include <iostream>
using namespace std;

struct Node {
    float temp;
    Node* next;
};

float arr[100];
int arrSize = 0;
Node* head = NULL;

void insertReading() {
    float t;
    cout << "Enter body temperature (in deg F): "; cin >> t;
    arr[arrSize++] = t;
    Node* newNode = new Node();
    newNode->temp = t;
    newNode->next = NULL;
    if (!head) head = newNode;
    else {
        Node* curr = head;
        while (curr->next) curr = curr->next;
        curr->next = newNode;
    }
    cout << "Temperature recorded in both structures!\n";
}

void displayMemory() {
    cout << "\n--- Array Representation ---\n";
    for (int i = 0; i < arrSize; i++) cout << "Index [" << i << "] -> Temp: " << arr[i] << " F\n";
    cout << "\n--- Linked List Representation ---\n";
    Node* curr = head;
    int idx = 0;
    while (curr) {
        cout << "Node " << idx++ << " (" << curr << ") -> Temp: " << curr->temp << " F\n";
        curr = curr->next;
    }
}

void countAbove100() {
    int count = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 100.0) count++;
    }
    cout << "Patients with temperature above 100 F: " << count << "\n";
}

int main() {
int ch;
    do {
        cout << "\n--- Set 10: Body Temperature Readings (Array & LL) ---\n";
        cout << "1. Insert Temperature Reading\n2. Display Memory Representation\n3. Count Temp > 100 F\n4. Exit\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1: insertReading(); break;
            case 2: displayMemory(); break;
            case 3: countAbove100(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (ch != 4);
    return 0;
}

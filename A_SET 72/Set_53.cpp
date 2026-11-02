// Set 53 - Online Store Product Catalogue using Binary Search
// Maintain the product catalogue of an online store (Product ID, Name, Price). Write functions to:
// a. Read N products and sort them by Product ID
// b. Search a product by Product ID using binary search
// c. Display the product details if found
// d. Display the number of comparisons made

#include <iostream>
#include <string>
using namespace std;

struct Product {
    int id;
    string name;
    float price;
};

int main() {
int n;
    cout << "Enter number of products: "; cin >> n;
    Product arr[100];
    for (int i = 0; i < n; i++) {
        cout << "Enter Product ID, Name, Price: ";
        cin >> arr[i].id >> arr[i].name >> arr[i].price;
    }
    // Sort by Product ID
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].id > arr[j + 1].id) {
                Product temp = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = temp;
            }
        }
    }
    int target, low = 0, high = n - 1, comps = 0, found = -1;
    cout << "\nEnter Product ID to search: "; cin >> target;
    while (low <= high) {
        comps++;
        int mid = (low + high) / 2;
        if (arr[mid].id == target) { found = mid; break; }
        else if (arr[mid].id < target) low = mid + 1;
        else high = mid - 1;
    }
    if (found != -1) cout << "Product Found: " << arr[found].name << " | Price: Rs." << arr[found].price << "\n";
    else cout << "Product not found!\n";
    cout << "Number of comparisons: " << comps << "\n";
    return 0;
}

// Title: Set 47 - Online Store Product Catalogue Search using Linear Search
// Problem Statement:
//   Maintain the product list of an online store
//   such as Amazon (Product ID, Name, Price). Write
//   functions to:
//   a. Read N products
//   b. Search a product by Name using linear search
//   c. Display the product details if found
//   d. Display "Out of catalogue" otherwise

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
    string target; int found = -1;
    cout << "\nEnter Product Name to search: "; cin >> target;
    for (int i = 0; i < n; i++) {
        if (arr[i].name == target) { found = i; break; }
    }
    if (found != -1) cout << "Product Details: ID " << arr[found].id << ", Price Rs." << arr[found].price << "\n";
    else cout << "Out of catalogue\n";
    return 0;
}

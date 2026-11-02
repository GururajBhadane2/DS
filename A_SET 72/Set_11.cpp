// Set 11 - Maintain Product Records using Array
// Maintain the records of N products (Product ID, Name, Quantity) using an array. Write functions
// to:
// a. Insert a new product at a given position
// b. Delete a product by Product ID
// c. Search a product by Product ID and display the record
// d. Display all products

#include <iostream>
#include <string>
using namespace std;

struct Product {
    int id;
    string name;
    int qty;
};

Product prods[100];
int n = 0;

void insertProduct() {
    if (n >= 100) { cout << "Array Full!\n"; return; }
    int pos;
    cout << "Enter position (0 to " << n << "): "; cin >> pos;
    if (pos < 0 || pos > n) { cout << "Invalid position!\n"; return; }
    Product p;
    cout << "Enter Product ID: "; cin >> p.id;
    cout << "Enter Product Name: "; cin >> p.name;
    cout << "Enter Quantity: "; cin >> p.qty;
    for (int i = n; i > pos; i--) prods[i] = prods[i - 1];
    prods[pos] = p;
    n++;
    cout << "Product inserted successfully!\n";
}

void deleteProduct() {
    if (n == 0) { cout << "No products to delete!\n"; return; }
    int id, found = -1;
    cout << "Enter Product ID to delete: "; cin >> id;
    for (int i = 0; i < n; i++) {
        if (prods[i].id == id) { found = i; break; }
    }
    if (found == -1) { cout << "Product ID not found!\n"; return; }
    for (int i = found; i < n - 1; i++) prods[i] = prods[i + 1];
    n--;
    cout << "Product deleted successfully!\n";
}

void searchProduct() {
    int id;
    cout << "Enter Product ID to search: "; cin >> id;
    for (int i = 0; i < n; i++) {
        if (prods[i].id == id) {
            cout << "Found! ID: " << prods[i].id << ", Name: " << prods[i].name << ", Qty: " << prods[i].qty << "\n";
            return;
        }
    }
    cout << "Product not found!\n";
}

void display() {
    if (n == 0) { cout << "No products available!\n"; return; }
    cout << "\nID\tName\tQuantity\n";
    for (int i = 0; i < n; i++) cout << prods[i].id << "\t" << prods[i].name << "\t" << prods[i].qty << "\n";
}

int main() {
int ch;
    do {
        cout << "\n--- Set 11: Product Records (Array) ---\n";
        cout << "1. Insert Product at Position\n2. Delete Product by ID\n3. Search Product by ID\n4. Display All\n5. Exit\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1: insertProduct(); break;
            case 2: deleteProduct(); break;
            case 3: searchProduct(); break;
            case 4: display(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (ch != 5);
    return 0;
}

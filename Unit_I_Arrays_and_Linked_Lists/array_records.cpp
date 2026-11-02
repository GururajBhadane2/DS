#include <iostream>
#include <string>
using namespace std;

// Maximum number of student records
const int MAX = 50;

// Structure to define a Student Record
struct Student {
  int roll;
  string name;
  float marks;
};

// Array of records and current count
Student records[MAX];
int n = 0; // Number of records currently in the array

// 1. INSERTION OPERATION
// Inserts a record at a given position (0 to n)
void insertRecord() {
  if (n >= MAX) {
    cout << "Array is Full! (Overflow)\n";
    return;
  }

  int pos;
  cout << "Enter position to insert (0 to " << n << "): ";
  cin >> pos;

  if (pos < 0 || pos > n) {
    cout << "Invalid position! Must be between 0 and " << n << ".\n";
    return;
  }

  Student s;
  cout << "Enter Roll No: ";
  cin >> s.roll;
  cout << "Enter Name: ";
  cin >> s.name;
  cout << "Enter Marks: ";
  cin >> s.marks;

  // Shift records to the right from end down to pos
  for (int i = n; i > pos; i--) {
    records[i] = records[i - 1];
  }

  // Place the new record at pos
  records[pos] = s;
  n++; // Increase count

  cout << "Record inserted successfully at position " << pos << "!\n";
}

// 2. DELETION OPERATION
// Deletes a record by Roll Number
void deleteRecord() {
  if (n == 0) {
    cout << "Array is Empty! (Underflow)\n";
    return;
  }

  int roll;
  cout << "Enter Roll No to delete: ";
  cin >> roll;

  int index = -1;
  // Find the record
  for (int i = 0; i < n; i++) {
    if (records[i].roll == roll) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    cout << "Student with Roll No " << roll << " not found!\n";
    return;
  }

  string deletedName = records[index].name;

  // Shift records to the left to overwrite the deleted record
  for (int i = index; i < n - 1; i++) {
    records[i] = records[i + 1];
  }
  n--; // Decrease count

  cout << "Deleted record of " << deletedName << " (Roll No " << roll << ")!\n";
}

// 3. SEARCH OPERATION
// Searches for a record by Roll Number
void searchRecord() {
  if (n == 0) {
    cout << "Array is empty!\n";
    return;
  }

  int roll;
  cout << "Enter Roll No to search: ";
  cin >> roll;

  for (int i = 0; i < n; i++) {
    if (records[i].roll == roll) {
      cout << "\n--- Record Found at Index " << i << " ---\n";
      cout << "Roll No : " << records[i].roll << "\n";
      cout << "Name    : " << records[i].name << "\n";
      cout << "Marks   : " << records[i].marks << "\n";
      return;
    }
  }

  cout << "Record with Roll No " << roll << " not found!\n";
}

// 4. DISPLAY OPERATION
// Displays all records in tabular format
void displayRecords() {
  if (n == 0) {
    cout << "No records to display! Array is empty.\n";
    return;
  }

  cout << "\n=========================================\n";
  cout << "Index\tRoll No\tName\tMarks\n";
  cout << "=========================================\n";
  for (int i = 0; i < n; i++) {
    cout << i << "\t" << records[i].roll << "\t" << records[i].name << "\t"
         << records[i].marks << "\n";
  }
  cout << "=========================================\n";
  cout << "Total Records: " << n << "\n";
}

int main() {
  int choice;
  do {
    cout << "\n--- Array Records Management ---\n";
    cout << "1. Insert Record\n";
    cout << "2. Delete Record\n";
    cout << "3. Search Record\n";
    cout << "4. Display All Records\n";
    cout << "5. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
      insertRecord();
      break;
    case 2:
      deleteRecord();
      break;
    case 3:
      searchRecord();
      break;
    case 4:
      displayRecords();
      break;
    case 5:
      cout << "Exiting...\n";
      break;
    default:
      cout << "Invalid choice! Please try again.\n";
    }
  } while (choice != 5);

  return 0;
}

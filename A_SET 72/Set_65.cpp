// Set 65 - College Lab Print Queue Simulation with Page Counting
// Simulate the print queue of a college lab
// using a simple queue. Each job has a Job ID and
// Number of Pages. Write functions to:
// a. Add a print job to the queue
// b. Remove and display the job being printed
// c. Display the job at the front
// d. Display all pending jobs and the total pages pending

#include <iostream>
using namespace std;

const int MAX = 20;
struct Job {
  int id;
  int pages;
};

Job q[MAX];
int front = -1, rear = -1;

void addJob() {
  if (rear == MAX - 1) {
    cout << "Print Queue Full!\n";
    return;
  }
  Job j;
  cout << "Enter Job ID: ";
  cin >> j.id;
  cout << "Enter Number of Pages: ";
  cin >> j.pages;
  if (front == -1)
    front = 0;
  q[++rear] = j;
  cout << "Print job #" << j.id << " added.\n";
}

void printJob() {
  if (front == -1 || front > rear) {
    cout << "No print jobs pending!\n";
    front = rear = -1;
    return;
  }
  cout << "Printed Job #" << q[front].id << " (" << q[front].pages
       << " pages)\n";
  front++;
  if (front > rear)
    front = rear = -1;
}

void display() {
  if (front == -1 || front > rear) {
    cout << "No pending jobs!\n";
    return;
  }
  cout << "Front Job: #" << q[front].id << " (" << q[front].pages
       << " pages)\n";
  int totalPages = 0;
  cout << "\nPending Print Queue:\n";
  for (int i = front; i <= rear; i++) {
    cout << "Job #" << q[i].id << " - " << q[i].pages << " pages\n";
    totalPages += q[i].pages;
  }
  cout << "Total Pages Pending: " << totalPages << "\n";
}

int main() {
int ch;
  do {
    cout << "\n--- Set 65: College Print Queue ---\n1. Add Print Job\n2. Print "
            "Next Job\n3. Display Queue & Total Pages\n4. Exit\nEnter: ";
    cin >> ch;
    if (ch == 1)
      addJob();
    else if (ch == 2)
      printJob();
    else if (ch == 3)
      display();
  } while (ch != 4);
  return 0;
}

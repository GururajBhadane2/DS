#include <iosteam>
using namespace std;
int main() {
  int a[100];
  int i, j, temp;

  cout << "enter Array : \t";
  for (i = 0; i < 5; i++) {
    cin >> a[i];
  }
  cout << "array is";
  for (i = 0; i < 5; i++) {
    cout << a[i] << "\t";
  }

  for (i = 0; i < 5; i++) {
    for (j = i + 1; j < 5; j++) {
      if (a[i] > a[j]) {
        temp = a[j];
        a[j] = a[i];
        a[i] = temp;
      }
    }
  }

  cout << "arry is";
  for (i = 0; i < 5; i++) {
    cout << a[i] << "\t";
  }
  return 0;
}
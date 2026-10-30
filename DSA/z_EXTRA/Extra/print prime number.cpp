#include<iostream>
int main()
{
  int i, j, count=0, number;

  // Ask the user for input
  std::cout << "Enter the limit to find prime numbers: ";
  std::cin >> number;

  for (i=0; i<=number; i++)
  { 
    count = 0;

    for (j=1; j<=i; j++)
    {
      if (i%j == 0)
      {
        count++;
      }
    }

    if (count == 2)
    {
      std::cout << i << "\n";
    }
  }

  return 0;
}

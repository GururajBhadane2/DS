#include<iostream>
using namespace std;
int main()
{
  int i,count=0;
  int number;
  
  cout<<"Enter the number";
  cin>>number;

  for(i=1;i<=number;i++)
  {
    if(number%i==0)
    {
      count++;
    }
  }

  if (count==2)
    cout<<number<<" is prime number";
  else
    cout<<number<<"is not Prime number";

  return 0;
}

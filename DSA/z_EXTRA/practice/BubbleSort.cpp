#include<iostream>
using namespace std;
int main()
{
  int a[100];
  int i,j,temp;
  
  cout<<"Enter Array : \t";
  for(i=0; i<5; i++)
  {
    cin>>a[i];
  }
  
  cout<<"Array is ";
  for(i=0; i<5; i++)
  {
    cout<<a[i]<<"\t";
  }
  
  for(i=0; i<5; i++)
  {
    for(j=i+1; j<5; j++)
    {
      if(a[i]>a[j])
      {
        temp=a[j];
        a[j]=a[i];
        a[i]=temp;
      }
    }  
  }
  cout<<"\n""Array is ";
  for(i=0; i<5; i++){
    cout<<a[i]<<"\t";
  }
  

  return 0;
}


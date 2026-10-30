#include<iostream>
using namespace std;
int binarySearch(int A[], int low, int high)
{
  int key,mid;
  
  
  while(low<=high)
  {
    mid=(low+(high-low))/2;
    
    if (key==A[mid])
      {
        return mid;
      }
    
    if (key>A[mid])
    {
      low=mid+1;
    }
    else
    {
      high=mid-1;
    }
  }
  
  return -1;
}
 
int main()
{
    
 
  int result = 0,i=0;
  int n;
  int A[100];
    
  cout<<"ENTER NUMBER OF ARRAY\t";
  cin>>n;
  
  cout<<"ENTER ARRAY \n";
  for (i=0;i<n;i++)
  {
    cin>>A[i];
  }
  
  cout << "ENTERED ARRAY ARE\t";
  for(i=0;i<n;i++)
  {
    cout<<A[i]<<"\t";
  }
  
  for(i=0; i<n-1; i++) 
  {
    for(int j=0; j<n-i-1; j++) 
    {
      if(A[j] > A[j+1]) 
      {
        int temp = A[j];
        A[j] = A[j+1];
        A[j+1] = temp;
      }
    }
  }
  
  cout << "\nSORTED ARRAY ARE\t";
  for(i=0;i<n;i++)
  {
    cout<<A[i]<<"\t";
  }
  int key;
  cout<<"\nEnter Element\t";
  cin>>key;
  result = binarySearch(A,0,n-1);
  if(result == -1)
  {
    cout<<"NOT FOUND"<<endl;
  }
  else
  {
    cout<<"FOUND"<<endl;
  }
  return 0;
}


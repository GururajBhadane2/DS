#include<iostream>
using namespace std;
int main(){
int partition(int A[],int low,int high)
{
int pivot=A[high];
int i=low-1;
for(int j=low;j<high;j++){
if(arr[j]<pivot){
i++;
swap(arr[i],arr[j]);
}
}
swap (arr[i+1],arr[high]);
return i+1;
}
void quickSort(int arr)


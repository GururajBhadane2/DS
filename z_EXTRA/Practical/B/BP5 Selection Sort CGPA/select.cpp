#include<iostream>
using namespace std;
 class Student
 {
 public:
 int roll;
 string name;
 float cgpa;
 
 void selectionSort(student s[], int n)
 {
 for(int i=0;i<n-1;i++)
 {
 int max=i;
 for(int j=i+1;j<n;j++)
 {
 if(s[j].cgpa>s[max].cgpa)
 {
 max=j;
 }
 }
 Student temp=s[i];
 s[i]=s[max]
 s[max]=temp;
 }
 }
 
 
 void insertionSort(student s[], int n)
 {
 int shifts = 0;
 for (int i=1; i<n; i++)
 {
 Student key=s[i];
 int j= i-1
 while(j>=0 && s[j].cgpa<key.cpga)
 {
 s[j+1]=s[j];
j--;
shifts++;
}
s[j+1]=key;
}
return shifts;
}
 

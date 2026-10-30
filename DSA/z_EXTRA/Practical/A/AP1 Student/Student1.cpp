#include<iostream>
using namespace std;

class student
{
  public :

  int  rollno;
  string name;
  string branch;
  string city;
   
};

int main ()
{
  student s1;
  cout<<"\n\nEnter  1st Roll No : \t";
  cin>>s1.rollno;
  cout<<"Enter  1st Name : \t";
  cin>>s1.name;
  cout<<"Enter  1st branch: \t";
  cin>>s1.branch;
  cout<<"Enter  1st city : \t";
  cin>>s1.city;
  
  
  student s2;
  cout<<"\n\nEnter 2nd  Roll No : \t";
  cin>>s2.rollno;
  cout<<"Enter 2nd Name : \t";
  cin>>s2.name;
  cout<<"Enter 2nd  branch : \t";
  cin>>s2.branch;
  cout<<"Enter 2nd city : \t";
  cin>>s2.city;
  
  
  cout<<"\n\nEnter  1st Roll No : "<<s1.rollno<<endl;
  cout<<"Enter  1st Name : "<<s1.name<<endl;
  cout<<"Enter  1st Branch : "<<s1.branch<<endl;
  cout<<"Enter  1st city : "<<s1.city<<endl;

  cout<<"\n\nEnter 2nd  Roll No : "<<s2.rollno<<endl;
  cout<<"Enter 2nd Name : "<<s2.name<<endl;
   cout<<"Enter 2nd  Branch : "<<s2.branch<<endl;
  cout<<"Enter 2nd City : "<<s2.city<<endl;
  


  return 0;  
}

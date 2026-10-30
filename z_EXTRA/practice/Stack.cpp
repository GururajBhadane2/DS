#include<iostream>
using namespace std;
#define MAX 5

class Stack
{
  public:
  int value;
  int top;
  int A[MAX];
  
  Stack(){
    top = -1;
  }
  
  bool isEmpty() {
    if (top==-1) return  true;
    return false; 
  }
  
  bool isFull() {
    if(top== MAX-1) return true;
      return false;
  }
  
  void push(int value)
  {
    if(isFull())
    cout << "Full";
    else{
    top++;
    A[top]=value;
    cout<< value <<" is added\n";
    
    }
  }//push
  
    void pop() { 
      if (isEmpty()) cout<<"Stack is Empty";
      else {
      cout << A[top] << " is deleted";
      top--;
      }
    }//pop
   
   void peek() {
    if (isEmpty()) cout<<"Stack is Empty";
    else cout << "TOP is " << A[top] ;
   }//peek 
  
  void display ()
  {
   if(isEmpty()) cout<<"Stack is Empty"<<endl;
    else{
       for(int i=top; i>=0; i--)  cout<<A[i]<<endl;     
      }
  }//display


};//Class Stack

int main ()
{

  Stack s1;
   cout<<" "<<endl;
  s1.push(10);
  s1.push(20);
  s1.push(30);
  s1.push(40);
  s1.push(50);
   cout<<" "<<endl;
  s1.display();
   cout<<" "<<endl;
  s1.pop();
   cout<<" "<<endl;
  s1.display();
  s1.peek();
   cout<<" "<<endl;
return 0;
} //main

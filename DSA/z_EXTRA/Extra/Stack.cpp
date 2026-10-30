#include<iostream>
using namespace std;
#define MAX 100

class Stack
{
   public:
      int A[MAX];
      int top;
      Stack()
      { 
         top= -1;
      }
         
        void push (int value)
        {
            if(top == MAX-1)
            {
               cout<<"Stack is Overflow"<<endl;
            }
            else
            {
              top++;
              A[top]= value;
              cout<<value<<" is pushed into stack"<<endl;
            }
        
       }//push
       void pop()
       {
          if(top == -1)
          {
             cout<<"Stack is Underflow"<<endl;
          }
          else
          {
           cout<<A[top]<<" is Poped from Stack"<<endl;
           top--;
          }
       }//pop
        void peek()
        {
            if(top==-1)
            {
                cout<<"Stack is Empty"<<endl;
            }
            else
            {
                cout<<"Top element is: "<<A[top]<<endl;
            }
        }//peek
          

       void display()
       {
          if(top == -1)
          {
             cout<<"Stack is Empty"<<endl;
          } 
          else
          {
            for(int i=top; i>=0; i--)  cout<<A[i]<<endl;     
          }
        } //display
}; // class
/*
int  main()
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
}


 

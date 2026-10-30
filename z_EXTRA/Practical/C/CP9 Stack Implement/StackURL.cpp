#include<iostream>
using namespace std;
#define MAX 100

class Stack
{
   public:
      string A[MAX];
      int top;
      Stack()
      { 
         top= -1;
      }
         
        void push (string value)
        {
            if(top == MAX-1)
            {
               cout<<"History is Full"<<endl;
            }
            else
            {
              top++;
              A[top]= value;
              cout<<value<<" is recently visited"<<endl;
            }
        
       }//push
       void pop()
       {
          if(top == -1)
          {
             cout<<"No history found"<<endl;
          }
          else
          {
           cout<<A[top]<<" is deleted from history"<<endl;
           top--;
          }
          
       }//pop
       
        void peek()
        {
            if(top==-1)
            {
                cout<<"No history found"<<endl;
            }
            else
            {
                cout<<"Current page: "<<A[top]<<endl;
            }
        }
       
       void display()
       {
          if(top == -1)
          {
             cout<<"No history found"<<endl;
          } 
          else
          {
            for(int i=top; i>=0; i--)  cout<<A[i]<<endl;     
          }
        } //display
}; // class
/*
int main()
{   
    int n;
    string U;
    Stack s1;

    cout<<" "<<endl;
    cout<<"1. Visit a new page (push URL)\n"<<endl;
  
    
    cout<<"\n2. Go back to the previous page (pop URL)"<<endl;
    s1.pop();
    
    
    cout<<"3. Display the current page"<<endl;
    s1.peek();
    
     
    cout<<"4. Show the entire browsing history stack\n"<<endl;
    s1.display();
    
    cout<<"5. EXIT"<<endl;
   
   do
   {
        cout<<"Enter Choice"<<endl;
        cin>>n;
         switch(choice)
      {
        case 1:
          cout << " SITE NAME \t";
          cin >> U;
          s1.push(U);          
        break;
  
        case 2:
        
        break;
  
        case 3:
        
        break;
  
        case 4:
        cout<<"Exit\n \n";
        break;
        
        default: 
        cout<<"Select Proper Option \n";
        cout<<"----------------------------------------------------------------------------------- \n";
        break;
  
      }
    } while (choice != 5 );
   }
    return 0;
}



*/
int main()
{
    Stack s1;

    cout<<" "<<endl;
    cout<<"a. Visit a new page (push URL)\n"<<endl;
    s1.push("Google.com");
    s1.push("Youtube.com");
    s1.push("Github.com");
    s1.push("ChatGPT.com");
    
    cout<<"\nb. Go back to the previous page (pop URL)"<<endl;
    s1.pop();
    
     cout<<" "<<endl;
    cout<<"c. Display the current page"<<endl;
    s1.peek();
    
     cout<<" "<<endl;
    cout<<"d. Show the entire browsing history stack\n"<<endl;
    s1.display();
    cout<<" "<<endl;
    cout<<" "<<endl;
    return 0;
}


int  main()
{
int i,n,V, A[MAX];
  Stack s1;

  cout<<"Enter Nth Number\t";
  cin>>n;
  
  for(i=0; i<n; i++){ 
    cin>>V; 
  }
  for(i=0; i<n; i++) { 
    s1.push(V);
  }
    
  
 cout<<" "<<endl;
 
  s1.display();
  //s1.pop();
 // s1.display();
return 0;
} //main



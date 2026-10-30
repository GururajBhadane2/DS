#include<iostream>
using namespace std;

class Node
{
  public:
    int data;
    Node *next;
    Node(int value)
      {
        data = value;
        next = NULL;
      }
}; //class node
             		
class LinkedList
{
  public:
    Node *head;
    LinkedList()
  {
    head = NULL;
  }

  void add(int value)
  {
    Node *n1 = new Node(value);
    if(head==NULL)
    {
      head = n1;
      return;
    }

    Node *temp = head;
    while(temp->next!=NULL)
      {  
        temp = temp->next;
      }
      temp->next = n1;
}// Add

void display()
{
  Node *temp = head;
  if(head == NULL)
  {
    cout<<"LL is empty";
    return;
  }
  while(temp!=NULL)
    {
      cout<<temp->data<<"->";
      temp=temp->next;
    }
      cout<<"Null";
}//display
};//Class LinkedList

int main()
{
  LinkedList l1;

  
    int Attendance ;
    int choice;
    int c;
  
  cout<<"\n1. Insert Attendance \n2. Update Attendance \n3.Calculate Attendance \n4.Display complete Attendance List \n5.Exit";
  
  do
  {
    cout<<"\nEnter option\t";
    cin>>choice;
  
    switch(choice)
    {
      case 1:
        cout<<" Insert Attendance\t";
        cin>>c;  
          l1.add(c);
        break;
      
      case 2:
        cout<<" Update Attendance ";
          l1.add(1);
          l1.add(12);
          l1.add(30);
          l1.display();
        break;
      
      case 3:
      {
        cout<<"--- Calculate Attendance ---\n";
        if(l1.head == NULL) {
            cout << "Attendance list is empty.\n";
            break;
        }
        
        Node *temp = l1.head;
        int totalDays = 0;
        int presentDays = 0; 
        
        while(temp != NULL) {
            totalDays++;
            if(temp->data > 0) {
                presentDays++;
            }
            temp = temp->next;
        }
        
        double percentage = (double)presentDays / totalDays * 100;
        
        cout << "Total Records: " << totalDays << endl;
        cout << "Present Count: " << presentDays << endl;
        cout << "Attendance Percentage: " << percentage << "%\n";
        break;
      }
      
      case 4:
        cout<<" Display complete Attendance List ";
        l1.display();
        break;
      
      case 5:
        cout<<" Exit "<<endl;
        break;
    }
    
  }while (choice !=5); 
  
  
  return 0; 
}

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
}; //class Node


class LinkedList
{
    public:
        Node *head;
        LinkedList()
        {
            head = NULL;
        }

        void add()
        {
            Node *n1 = new Node(value)
            if (head == NULL)
            {
                head = n1;
                return;
            }
            Node *temp = head;
            while (temp -> next != NULL)
            {
                temp = temp->next;
            }
            temp->next = n1;
        }//add()
        void display()
        {
            Node *temp = head;
            if(head == NULL)
            {
                cout<<"LinkedList is Empty";
                return;
            }
            while(temp!=NULL)
            {
                cout<<temp->data<<"->";
                temp=temp->next;
            }
            cout<<"NULL";
        } //display()
}; //LinkedList 

int main()
{
    LinkedList l1;
    l1.add(1);
    l1.add(2);
    l1.display();

int Attendance ;
  int choice;
  
  cout<<"1. Insert Attendance \n2. Update Attendance \n3.Calculate Attendance \n4.Display complete Attendance List \n5.Exit";
  
  do
  {
    cout<<"\nEnter option\t";
    cin>>choice;
  
    switch(choice)
    {
      case 1;
        cout<<" Insert Attendance";
        break;
      
      case 2;
        cout<<" Update Attendance ";
        break;
      
      case 3;
        cout<<" Calculate Attendance";
        break;
      
      case 4;
        cout<<" Display complete Attendance List ";
        break;
      
      case 5;
        cout<<" Exit ";
        break;
    }
    
  }while (choice !=5); 
  
  
  
  return 0; 
}

//***SBI ATM***
//1.Balance Enquiry
//2.Cash Deposit
//3.Cash Withdraw
//4.Exit
//Enter your choice : 


#include<iostream>
using namespace std;
int main ()
{
  int choice;
  float Balance=0.00;
  float Cash_Deposit;
  float Cash_Withdraw;
  
      cout<<"***SBI ATM*** \n1.Balance Enquiry \n2.Cash Deposit \n3.Cash Withdraw \n4.Exit\n";
 do {
      cout<<"\nEnter your choice:   ";
      cin>>choice;
  
      switch(choice)
      {
        case 1:
        cout<<"Balance Enquiry:\n"<<Balance<<"\n";
        
        break;
  
        case 2:
        cout<<"Cash Deposit:\n";
        cin>>Cash_Deposit;
        Balance += Cash_Deposit; 
        cout<<"\nCash Deposit Successfully \nso, New balance is "<<Balance<<"/-\n";
        break;
  
        case 3:
        cout<<"Cash Withdraw:\n"; 
        cin>>Cash_Withdraw;
        if(Balance>=Cash_Withdraw){
          Balance -= Cash_Withdraw;
          cout<<"Cash Withdraw successfully, ENJOY!\n";
          }
        else
        cout<<"Sorry low Balance\n";
        break;
  
        case 4:
        cout<<"Exit\n \n";
        cout<<"----------------------------------------------------------------------------------- \n";
        cout<<"---------------------T-H-A-N-K---Y-O-U---V-I-S-I-T---A-G-I-A-N--------------------- \n";
        cout<<"----------------------------------------------------------------------------------- \n\n";
        break;
        
        default: 
        cout<<"Select Proper Option \n";
        cout<<"----------------------------------------------------------------------------------- \n";
        break;
  
      }
    } while (choice != 4 );

  return 0;
}
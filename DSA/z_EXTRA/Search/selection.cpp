#include<iostream> 
using namespace std; 
int main() 
{   
    int a[5];   
    int i, j, min, temp;   
      
    cout << "Enter Array :\n";    
    for(i=0;i<5;i++) 
    {     
        cin>>a[i];   
    }    
    for(i=0;i<4;i++) 
    {         
        min=i;
        for(j=i+1;j<5;j++) 
        { 
            if(a[j] < a[min]) 
            {  
                min=j;         
            }
        }       
       temp=a[min];
       a[min]=a[i];
       a[i]=temp;
    }   
    
    cout << "\nSELECTION SORTED ARRAY :\t";   
    for(i=0;i<5;i++) 
    {     
        cout<<a[i]<<"\t";   
    }     
    return 0; 
}


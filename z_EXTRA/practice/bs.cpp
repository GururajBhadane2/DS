#include<iostream>
using namespace std;

void selectionSort(float a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
                min=j;
        }

        float temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
}

void bubbleSort(float a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                float temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

void display(float a[],int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

void topFive(float a[],int n)
{
    cout<<"Top Five Scores: ";
    int count=(n<5)?n:5;

    for(int i=n-1;i>=n-count;i--)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main()
{
    int n;

    cout<<"Enter number of students: ";
    cin>>n;

    float a[n],b[n];

    cout<<"Enter percentages:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }

    selectionSort(a,n);
    cout<<"\nSelection Sort: ";
    display(a,n);
    topFive(a,n);

    bubbleSort(b,n);
    cout<<"\nBubble Sort: ";
    display(b,n);
    topFive(b,n);

    return 0;
}



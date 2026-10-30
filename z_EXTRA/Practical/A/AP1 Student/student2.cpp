#include<iostream>
using namespace std;

class student
{
public:
    int rollno;
    string name;
    string branch;
    string city;
};

int main()
{
    int n;

    cout << "Enter the number of students: ";
    cin >> n;

    student s[n];  
    
    for(int i = 0; i < n; i++)
    {
        cout << "\nEnter details of Student " << i + 1 << endl;

        cout << "Roll No : ";
        cin >> s[i].rollno;

        cout << "Name : ";
        cin >> s[i].name;

        cout << "Branch : ";
        cin >> s[i].branch;

        cout << "City : ";
        cin >> s[i].city;
    }

    
    cout << "\n Student Details \n";

    for(int i = 0; i < n; i++)
    {
        cout << "\nStudent " << i + 1 << endl;
        cout << "Roll No : " << s[i].rollno << endl;
        cout << "Name    : " << s[i].name << endl;
        cout << "Branch  : " << s[i].branch << endl;
        cout << "City    : " << s[i].city << endl;
    }

    return 0;
}

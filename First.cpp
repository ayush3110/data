// first

#include<iostream>
using namespace std;

int main()
{
    int n1, n2;
    cout<<"Enter number of data for set A: ";
    cin>>n1;
    cout<<"Enter number of data for set B: ";
    cin>>n2;
    
    char a[n1], b[n2];
    int c[26] = {0}, d[26] = {0};

    cout<<"Enter data for set A:"<<endl;
    for(int i=0; i<n1; i++)
    {
        cin>>a[i];
        a[i]=toupper(a[i]);
        c[a[i] - 'A'] += 1;
    }

    cout<<"Enter data for set B:"<<endl;
    for(int i=0; i<n2; i++)
    {
        cin>>b[i];
        b[i]=toupper(b[i]);
        d[b[i] - 'A'] += 1;
    }

    int th;
    cout << "Enter Your Threshold Value : ";
    cin >> th;
    cout << "Items and it's Occurence :" << endl;
    for (int i = 0; i < 26; i++)
    {
        if (c[i] + d[i] > 0)
        {
            cout << char(i + 'A') << " : " << (c[i] + d[i]) << endl;
        }
    }
    cout << "Items that are more than Threshold Value : " << endl;
    for (int i = 0; i < 26; i++)
    {
        if (c[i] + d[i] >= th)
        {
            cout << char(i + 'A') << endl;
        }
    }
    cout << "Cartesian Product of Given Set is : " << endl;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            cout << " ( " << a[i] << " , " << b[j] << " ), ";
        }
        cout << endl;
    }
    return 0;
}
// mean, meadian, mode and standared deviation

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"How many data you want to insert: ";
    cin>>n;
    int set[n];
    cout<<"Enter data:"<<endl;

    for(int i=0; i<n; i++)
    {
        cin>>set[i];
    }

    //! Mean
    int sum=0;
    for(int i=0; i<n; i++)
    {
        sum += set[i];
    }

    double mean = sum / double(n);

    cout<<"Mean : "<<mean<<endl;

    //! Median
    sort(set, set + n);
    double median;
    // int extra = 0;

    if(n%2 == 0)
        median = (set[(n-1)/2] + set[((n-1)/2) + 1]) / 2.0;
    else
        median = set[(n + 1) / 2];

    cout<<"Median : "<< median<<endl;

    //! mode

    sort(set, set + n);
    int mcount = 1;
    int mode = set[0];
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (set[i] == set[i - 1])
            count++;
        else
        {
            if (count > mcount)
            {
                mcount = count;
                mode = set[i - 1];
            }
            count = 1;
        }
    }
    if (count > mcount)
    {
        mcount = count;
        mode = set[n - 1];
    }
    
    cout<<"Mode : "<<mode<<endl;

    //! standred deviation
    double sD = 0.0;

    for(int i = 0; i < n; i++) {
        sD += pow(set[i] - mean, 2);
    }

    double standredDeviation = sqrt(sD/double(n));
    cout<<"Standred Deviation : "<<standredDeviation;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

float findMean(vector<float> v)
{
    int size = v.size();
    float sum = 0;
    for (int i = 0; i < size; i++)
        sum += v[i];
    return (float)sum / size;
}

float findMedian(vector<float> v)
{
    int ans = 0;
    sort(v.begin(), v.end());
    if (v.size() == 2)
        return (v[0] + v[1]) / 2;

    if (v.size() % 2 == 0)
        return (v[v.size() / 2 - 1] + v[(v.size() / 2)]) / 2;
    else
        return v[v.size() / 2];
}

// float findMode(vector<float> v)
// {
//     sort(v.begin(), v.end());
//     int mCount = 1, ans = v[0], count = 1;
//     for (int i = 1; i < v.size(); i++)
//     {
//         if (v[i] == v[i - 1])
//         {
//             count++;
//             if (count > mCount)
//             {
//                 mCount = count;
//                 ans = v[i];
//             }
//         }
//         else
//         {
//             count = 1;
//         }
//     }
//     return ans;
// }

// float findSD(vector<float> v, float mean)
// {
//     float sd = 0.0;

//     for (int i = 0; i < v.size(); i++)
//     {
//         sd += pow(v[i] - mean, 2);
//     }

//     return sqrt(sd / v.size());
// }

void display(vector<float> bin[], int numOfBin)
{
    for (int i = 0; i < numOfBin; i++)
    {
        cout << "\nBin " << i + 1 << " : ";
        for (int j = 0; j < bin[i].size(); j++)
        {
            cout << bin[i][j] << " ";
        }
    }
}

int main()
{
    int n, numOfBin, numOfVal;
    vector<float> values;

    cout << "Enter Number of Value You Want to Insert : ";
    cin >> n;
    cout << "Enter Values : ";
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        values.push_back(temp);
    }

    cout << "Enter Number of Bin : ";
    cin >> numOfBin;

    vector<float> bin[numOfBin], tempBin[numOfBin];

    while (values.size() % numOfBin != 0)
    {
        values.push_back(0);
    }

    sort(values.begin(), values.end());

    cout << "\n";
    numOfVal = values.size() / numOfBin;
    int k = 0;
    for (int i = 0; i < numOfBin; i++)
    {
        for (int j = 0; j < numOfVal; j++)
        {
            bin[i].push_back(values[k++]);
            tempBin[i].push_back(values[k - 1]);
        }
    }
    
    cout << "Partition into (equal-frequency) bins : \n";
    display(bin, numOfBin);

    cout << "\n\n";
    cout << "Smoothing by bin Mean's : \n";
    for (int i = 0; i < numOfBin; i++)
    {
        float mean = findMean(bin[i]);
        for (int j = 0; j < numOfVal; j++)
        {
            bin[i][j] = mean;
        }
    }
    display(bin, numOfBin);
    for (int i = 0; i < numOfBin; i++)
        bin[i] = tempBin[i];

    cout << "\n\n";
    cout << "Smoothing by bin Median : \n";
    for (int i = 0; i < numOfBin; i++)
    {
        float median = findMedian(bin[i]);
        for (int j = 0; j < numOfVal; j++)
        {
            bin[i][j] = median;
        }
    }
    display(bin, numOfBin);
    for (int i = 0; i < numOfBin; i++)
        bin[i] = tempBin[i];

    // cout << "\n\n";
    // cout << "Smoothing by bin Mode : \n";
    // for (int i = 0; i < numOfBin; i++)
    // {
    //     float mode = findMode(bin[i]);
    //     for (int j = 0; j < numOfVal; j++)
    //     {
    //         bin[i][j] = mode;
    //     }
    // }
    // display(bin, numOfBin);
    // for (int i = 0; i < numOfBin; i++)
    //     bin[i] = tempBin[i];

    // cout << "\n\n";
    // cout << "Smoothing by Standard Deriation : \n";
    // for (int i = 0; i < numOfBin; i++)
    // {
    //     float tempMean = findMean(bin[i]);
    //     float sd = findSD(bin[i], tempMean);
    //     for (int j = 0; j < numOfVal; j++)
    //     {
    //         bin[i][j] = sd;
    //     }
    // }
    // display(bin, numOfBin);
    // for (int i = 0; i < numOfBin; i++)
    //     bin[i] = tempBin[i];
    cout << "\n\n";
    cout << "Smoothing by bin boundaries : \n";
    for (int i = 0; i < numOfBin; i++)
    {
        int min = *min_element(bin[i].begin(), bin[i].end());
        int max = *max_element(bin[i].begin(), bin[i].end());
        for (int j = 0; j < bin[i].size(); j++)
        {
            int minDiff = abs(bin[i][j] - min), maxDiff = abs(bin[i][j] - max);
            bin[i][j] = maxDiff < minDiff ? max : min;
        }
    }
    display(bin, numOfBin);
    for (int i = 0; i < numOfBin; i++)
        bin[i] = tempBin[i];

    return 0;
}

// Enter Number of Value You Want to Insert : 9
// Enter Values : 4 8 15 21 21 24 25 28 34
// Enter Number of Bin : 3

// Partition into (equal-frequency) bins :

// Bin 1 : 4 8 15
// Bin 2 : 21 21 24
// Bin 3 : 25 28 34

// Smoothing by bin Mean's :

// Bin 1 : 9 9 9
// Bin 2 : 22 22 22
// Bin 3 : 29 29 29

// Smoothing by bin Median :

// Bin 1 : 8 8 8
// Bin 2 : 21 21 21
// Bin 3 : 28 28 28

// Smoothing by bin Mode :

// Bin 1 : 4 4 4
// Bin 2 : 21 21 21
// Bin 3 : 25 25 25

// Smoothing by Standard Deriation :

// Bin 1 : 4.54606 4.54606 4.54606
// Bin 2 : 1.41421 1.41421 1.41421
// Bin 3 : 3.74166 3.74166 3.74166

// Smoothing by bin boundaries :

// Bin 1 : 4 4 15
// Bin 2 : 21 21 24
// Bin 3 : 25 25 34
#include <bits/stdc++.h>
using namespace std;

void output(double bin1[], double bin2[], double bin3[], int finalratio)
{
    cout<<endl;
    cout<<"Output:"<<endl;
    cout<<"Bin 1: ";
    for(int i=0; i<finalratio; i++)
        cout<<bin1[i]<<" ";

    cout<<endl<<"Bin 2: ";
    for(int i=0; i<finalratio; i++)
        cout<<bin2[i]<<" ";

    cout<<endl<<"Bin 3: ";
    for(int i=0; i<finalratio; i++)
        cout<<bin3[i]<<" ";

    cout<<endl<<endl;
}

double mean(double array[], int finalratio)
{
    int sum = 0;

    for(int i=0; i<finalratio; i++)
        sum += array[i];

    double mean = sum / double(finalratio);

    return mean;
}

double median(double array[], int finalratio)
{
    sort(array, array + finalratio);
    double median;

    if(finalratio % 2 == 0)
        median = (array[(finalratio - 1) / 2] + array[((finalratio - 1) / 2) + 1]) / 2.0;
    else
        median = array[(finalratio - 1) / 2];

    return median;
}

double mode(double array[], int finalratio)
{
    sort(array, array + finalratio);
    int mcount = 1;
    int mode = array[0];
    int count = 1;
    for (int i = 1; i < finalratio; i++)
    {
        if (array[i] == array[i - 1])
            count++;
        else
        {
            if (count > mcount)
            {
                mcount = count;
                mode = array[i - 1];
            }
            count = 1;
        }
    }
    if (count > mcount)
    {
        mcount = count;
        mode = array[finalratio - 1];
    }
    
    return mode;
}

double SD(double array[], int finalratio)
{
    double sD = 0.0;

    for(int i = 0; i < finalratio; i++) {
        sD += pow(array[i] - mean(array, finalratio), 2);
    }

    double standredDeviation = sqrt(sD/double(finalratio));

    return standredDeviation;
}

double* boundaris(double array[], int finalratio)
{
    double min = *min_element(array, array + finalratio);
    double max = *max_element(array, array + finalratio);

    for(int i=0; i<finalratio; i++)
    {
        if((array[i] - min) < (max - array[i]))
            array[i] = min;
        else
            array[i] = max;
    }

    return array;
}

void binningByMean(double bin1[], double bin2[], double bin3[], int finalratio)
{
    double mean1 = mean(bin1, finalratio);
    double mean2 = mean(bin2, finalratio);
    double mean3 = mean(bin3, finalratio);

    for(int i=0; i<finalratio; i++)
    {
        bin1[i] = mean1;
        bin2[i] = mean2;
        bin3[i] = mean3;
    }
    cout<<"==>Binning by mean:"<<endl;
    output(bin1, bin2, bin3, finalratio);
}

void binningByMedian(double bin1[], double bin2[], double bin3[], int finalratio)
{
    double median1 = median(bin1, finalratio);
    double median2 = median(bin2, finalratio);
    double median3 = median(bin3, finalratio);

    for(int i=0; i<finalratio; i++)
    {
        bin1[i] = median1;
        bin2[i] = median2;
        bin3[i] = median3;
    }
    cout<<"==>Binning by median:"<<endl;
    output(bin1, bin2, bin3, finalratio);
}

void binningByMode(double bin1[], double bin2[], double bin3[], int finalratio)
{
    double mode1 = mode(bin1, finalratio);
    double mode2 = mode(bin2, finalratio);
    double mode3 = mode(bin3, finalratio);

    for(int i=0; i<finalratio; i++)
    {
        bin1[i] = mode1;
        bin2[i] = mode2;
        bin3[i] = mode3;
    }
    cout<<"==>Binning by mode:"<<endl;
    output(bin1, bin2, bin3, finalratio);
}

void binningBySD(double bin1[], double bin2[], double bin3[], int finalratio)
{
    double sd1 = SD(bin1, finalratio);
    double sd2 = SD(bin2, finalratio);
    double sd3 = SD(bin3, finalratio);

    for(int i=0; i<finalratio; i++)
    {
        bin1[i] = sd1;
        bin2[i] = sd2;
        bin3[i] = sd3;
    }
    cout<<"==>Binning by standred deviation:"<<endl;
    output(bin1, bin2, bin3, finalratio);
}

void binningByBoundaries(double bin1[], double bin2[], double bin3[], int finalratio)
{
    bin1 = boundaris(bin1, finalratio);
    bin2 = boundaris(bin2, finalratio);
    bin3 = boundaris(bin3, finalratio);

    cout<<"==>Binning by boundaries:"<<endl;
    output(bin1, bin2, bin3, finalratio);
}

int main()
{
    int n;
    cout<<"How many data : ";
    cin>>n;

    double a[n];

    cout<<"Enter data : ";
    for(int i=0; i<n; i++)
        cin>>a[i];

    double ratio = n/3.0;
    int finalratio = ratio;

    if(ratio - int(ratio) > 0)
        finalratio++;

    int finalsize = 3 * finalratio;

    int b[finalsize] = {0};

    for(int i=0; i<finalsize; i++)
        b[i] = a[i];

    sort(b, b + finalsize);

    double bin1[finalratio];
    double bin2[finalratio];
    double bin3[finalratio];

    for(int i=0; i<finalsize; i++)
    {
        if(i<finalratio)
            bin1[i % finalratio] = b[i];
        else if(i>=finalratio && i< 2*finalratio)
            bin2[i % finalratio] = b[i];
        else
            bin3[i % finalratio] = b[i];
    }

    output(bin1, bin2, bin3, finalratio);

    cout<<"Choose methode for binning : "<<endl;
    cout<<"1. Binning by mean \n2. Binning by median \n3. Binning by mode \n4. Binning by standred deviation \n5. Binning by boundaries"<<endl;
    cout<<"Enter your choice : ";
    int ch=0;
    cin>>ch;

    switch (ch)
    {
        case 1:
            // Binning by mean
            binningByMean(bin1, bin2, bin3, finalratio);
            break;
        
        case 2:
            // Binning by mean
            binningByMedian(bin1, bin2, bin3, finalratio);
            break;
        
        case 3:
            // Binning by mean
            binningByMode(bin1, bin2, bin3, finalratio);
            break;
        
        case 4:
            // Binning by mean
            binningBySD(bin1, bin2, bin3, finalratio);
            break;
        
        case 5:
            // Binning by mean
            binningByBoundaries(bin1, bin2, bin3, finalratio);
            break;
        
        default:
            cout<<"Enter wrong input."<<endl;
            break;
    }

    return 0;
}
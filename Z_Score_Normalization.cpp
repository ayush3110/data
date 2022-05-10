#include<bits/stdc++.h>
using namespace std;

double mean(vector<double> array, int n)
{
    int sum = 0;

    for(int i=0; i<n; i++)
        sum += array[i];

    double mean = sum / double(n);

    return mean;
}

double SD(vector<double> array, int n)
{
    double sD = 0.0;

    for(int i = 0; i < n; i++) {
        sD += pow(array[i] - mean(array, n), 2);
    }

    double standredDeviation = sqrt(sD/double(n));

    return standredDeviation;
}

double z_score(double v, double ad, double sigma)
{
    double vd = (v - ad) / sigma;
    return vd;
}

void call_z_score(vector<double> v1, vector<double> &v2)
{
    double m = mean(v1, v1.size());
    double sd = SD(v1, v1.size());
    for(auto elm: v1)
        v2.push_back(z_score(elm, m, sd));
    cout<<"Z-score normalization: ";
}

void print(vector<double> old, vector<double> upd)
{
    cout<<endl<<endl;
    cout<<"Old"<<"\t\t"<<"New"<<endl<<endl;
    for(int i=0; i<old.size() - 1; i++)
    {
        cout<<old[i]<<"\t\t"<<upd[i]<<endl;
    }
    cout<<endl;
}

int main()
{
    vector<double> v1;
    string fname;
    int choice=0;
    cout<<"Enter file name: ";
    cin>>fname;
    cout<<"Choose attribute:"<<endl<<"1. Age"<<endl<<"2. Salary"<<endl;
    cin>>choice;

    int co;
    if(choice==1)
        co=1;
    else
        co=2;

    fstream fin;
    string line;
    fin.open(fname, ios::in);
    int step = 0;
    while (!fin.eof())
    {
        fin >> line;

        if(step > 0)
        {
            int i=0,f=0,e=0,flag=0,flag2=0;
            int count = 0;
            while(i<line.length())
            {
                if(count == co && flag == 0)
                {
                    f=i;
                    flag = 1;
                }

                if((count > co || i==line.length()-1) && flag2 == 0)
                {
                    if(count > co)
                        e = i - 2;
                    if(i==line.length()-1)
                        e=i;
                    flag2=1;
                }

                if(line[i]==',')
                    count++;

                i++;
            }
            char ch[80]={' '};

            int len = e - f + 1;
            line.copy(ch, len, f);
            string st = ch;
            v1.push_back(stoi(st));
        }

        step++;
    }

    vector<double> v2;

    call_z_score(v1, v2);
    

    print(v1, v2);

    return 0;
}
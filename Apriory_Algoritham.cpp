#include <bits/stdc++.h>
using namespace std;
int findInTransactions(set<set<int>> trns, set<int> tt)
{
    int count = 0;
    for (auto e = trns.begin(); e != trns.end(); e++)
    {
        set<int> s = *e;
        if (includes(s.begin(), s.end(), tt.begin(), tt.end()))
            count++;
    }

    return count;
}

void reduse(set<set<int>> trns, set<set<int>> &kk, int support, int len)
{

    for (auto i = kk.begin(); i != kk.end(); i++)
    {
        set<int> temp = *i;

        if (temp.size() == len)
        {
            int sp = findInTransactions(trns, temp);
            if (sp < support)
            {
                kk.erase(i);
            }
        }
    }
}

void printSet(set<set<int>> kk, set<set<int>> trns)
{
    for (auto i = kk.begin(); i != kk.end(); i++)
    {
        set<int> temp1 = *i;
        for (auto j = temp1.begin(); j != temp1.end(); j++)
        {

            cout << *j << " ";
        }
        cout << "Counts : " << findInTransactions(trns, temp1) << endl;
    }
}
void findPermutations(set<set<int>> &s, int k)
{
    set<set<int>> kk;
    for (auto i = s.begin(); i != s.end(); i++)
    {
        set<int> temp = *i;
        if (temp.size() == k - 1)
        {
            kk.insert(temp);
        }
    }
    if (kk.size() == 0)
        return;

    for (auto i = kk.begin(); i != kk.end(); i++)
    {
        for (auto j = kk.begin(); j != kk.end(); j++)
        {
            set<int> temp1 = *i;
            set<int> temp2 = *j;
            set<int> hh;
            merge(temp1.begin(), temp1.end(), temp2.begin(), temp2.end(), inserter(hh, hh.begin()));
            if (hh.size() == k)
                s.insert(hh);
        }
    }
}

int main()
{
    int n;
    cout<<"How many item you want to insert : ";
    cin >> n;
    vector<vector<int>> t;
    set<set<int>> ff;
    set<set<int>> trans;
    map<set<int>, int> mp;
    for (int i = 0; i < n; i++)
    {
        int k;
        cout<<"How many data you want you to insert in transaction no "<<i + 1<<" : ";
        cin >> k;
        cout << "Enter elements : ";
        vector<int> vv;
        set<int> vvv;
        for (int j = 0; j < k; j++)
        {
            int l;
            cin >> l;
            vvv.insert(l);
            
            set<int> c;
            c.insert(l);
            ff.insert(c);
            mp[c]++;
        }
        trans.insert(vvv);
        t.push_back(vv);
    }

    int ll = ff.size();
    int cl = 0;
    int spll = 2;
    int support;
    cout << "Enter mininmum support : ";
    cin >> support;
    while (ll != cl)
    {
        cl = ll;
        findPermutations(ff, spll);
        reduse(trans, ff, spll, support);

        spll++;
        ll = ff.size();
    }
    printSet(ff, trans);

    return 0;
}

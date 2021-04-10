
#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct db
{
    string process;
    int mx[200],allocate[200],need[200];
    bool finish;
};

int main()
{
    int n,maxResource[200],i,j,available[200],subClass,c[200];
    cout<<"Enter number of sub class : ";
    cin>>subClass;
    cin>>n;
    for(i=0; i<subClass; i++)
    {
        cin>>maxResource[i];
        available[i] = maxResource[i];
    }

    db banker[n+2];

    vector<string>safeSequence;

    for(i=0; i<n; i++)
    {
        cin>>banker[i].process;
        for(j=0; j<subClass; j++)
            cin>>banker[i].allocate[j];

        for(j=0; j<subClass; j++)
            cin>>banker[i].mx[j];
        for(j=0; j<subClass; j++)
        {
            c[j] = banker[i].mx[j]-banker[i].allocate[j];
            if(c[j]<=0)
                c[j] = 0;

            banker[i].need[j] = c[j];

            available[j]-=banker[i].allocate[j];
        }

        banker[i].finish = false;
    }
    for(i=0; i<n; i++)
    {
        int f = 1;
        for(int j=0; j<n; j++)
        {
            int x = 0;
            for(int k=0; k<subClass; k++)
            {
                if(banker[j].need[k]<=available[k])
                    ++x;
            }
            if(x==subClass && banker[j].finish==false)
            {
                safeSequence.push_back(banker[j].process);
                f = 0;
                banker[j].finish = true;
                for(int k=0; k<subClass; k++)
                    available[k]+=banker[j].allocate[k];
            }
        }
        if(f)
            break;
    }
    int sz = safeSequence.size();

    cout<<"< ";
    if(sz>0)
        cout<<safeSequence[0];
    for(i=1; i<sz; i++)
        cout<<" , "<<safeSequence[i];
    if(sz==n)
        cout<<" >"<<endl;
    else
        cout<<endl<<"Deadlock can't avoid......"<<endl;
}
/*
3
5
10 5 7
p1  0 1 0   7 5 3
p2  2 0 0   3 2 2
p3  3 0 2   9 0 2
p4  2 1 1   2 2 2
p5  0 0 2   2 4 3
*/


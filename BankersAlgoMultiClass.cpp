#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct db
{
    string process;
    int mxA,mxB,mxC,allocateA,allocateB,allocateC,needA,needB,needC;
    bool finish;
};

int main()
{
    int n,maxResourceA,maxResourceB,maxResourceC,i,j,availableA,availableB,availableC;
    cin>>n;
    cin>>maxResourceA>>maxResourceB>>maxResourceC;
    db banker[n+2];
    vector<string>safeSequence;
    availableA = maxResourceA;
    availableB = maxResourceB;
    availableC = maxResourceC;
    for(i=0; i<n; i++)
    {
        cin>>banker[i].process;
        cin>>banker[i].allocateA;
        cin>>banker[i].allocateB;
        cin>>banker[i].allocateC;

        cin>>banker[i].mxA;
        cin>>banker[i].mxB;
        cin>>banker[i].mxC;

        int cA = banker[i].mxA-banker[i].allocateA;
        if(cA<=0)
            cA = 0;
        int cB = banker[i].mxB-banker[i].allocateB;
        if(cB<=0)
            cB = 0;
        int cC = banker[i].mxC-banker[i].allocateC;
        if(cC<=0)
            cC = 0;
        banker[i].needA = cA;
        banker[i].needB = cB;
        banker[i].needC = cC;

        availableA-=banker[i].allocateA;
        availableB-=banker[i].allocateB;
        availableC-=banker[i].allocateC;

        banker[i].finish = false;
    }
    for(i=0; i<n; i++)
    {
        int c = 1;
        for(int j=0; j<n; j++)
        {
            if(banker[j].needA<=availableA && banker[j].needB<=availableB  && banker[j].needC<=availableC && banker[j].finish==false)
            {
                safeSequence.push_back(banker[j].process);
                availableA+=banker[j].allocateA;
                availableB+=banker[j].allocateB;
                availableC+=banker[j].allocateC;
                c = 0;
                banker[j].finish = true;
            }
        }
        if(c)
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
5
10 5 7
p1  0 1 0   7 5 3
p2  2 0 0   3 2 2
p3  3 0 2   9 0 2
p4  2 1 1   2 2 2
p5  0 0 2   2 4 3
*/


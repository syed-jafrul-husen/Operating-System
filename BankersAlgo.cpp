#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct db
{
    string process;
    int mx,allocate,need,available;
    bool finish;
};

int main()
{
    int maxResource,n,i;

    cin>>n;
    cin>>maxResource;
    db banker[n+2];
    vector<string>safeSequence;
    int available = maxResource;
    for(i=0; i<n; i++)
    {
        cin>>banker[i].process;
        cin>>banker[i].mx;
        cin>>banker[i].allocate;
        int c = banker[i].mx-banker[i].allocate;
        if(c<=0)
            c = 0;
        banker[i].need = c;
        available-=banker[i].allocate;
        banker[i].finish = false;
    }
    for(i=0; i<n; i++)
    {
        int c = 1;
        for(int j=0; j<n; j++)
        {
            if(banker[j].need<=available && banker[j].finish==false)
            {
                safeSequence.push_back(banker[j].process);
                available = available+banker[j].allocate;
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
3
12
p1 10 5
p2 4 2
p3 9 2

3
12
p1 10 5
p2 11 0
p3 15 2
*/

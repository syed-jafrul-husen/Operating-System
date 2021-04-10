#include<bits/stdc++.h>
using namespace std;

struct data
{
    string p;
    int aT,bT,rT,wT,tAt;
};

bool cmp(data x,data y)
{
   if(x.aT<y.aT) return true;
   return false;
}

int main()
{
    int n,i,t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>n;
        data fcfs[n+2];
        for(i=0; i<n; i++)
        {
            cin>>fcfs[i].p;
            cin>>fcfs[i].aT;
            cin>>fcfs[i].bT;
        }
        sort(fcfs,fcfs+n,cmp);
        for(i=n; i>=1; i--)
        {
           fcfs[i].p = fcfs[i-1].p;
           fcfs[i].aT = fcfs[i-1].aT;
           fcfs[i].bT = fcfs[i-1].bT;
        }
        //for(i=1; i<=n; i++)
            //cout<<fcfs[i].p<<" "<<fcfs[i].aT<<" "<<fcfs[i].bT<<endl;
        int gantChart[n+3];
        gantChart[0] = fcfs[1].aT;
        for(i=1; i<=n; i++)
        {
            gantChart[i] = gantChart[i-1]+fcfs[i].bT;
        }
        printf("\n\nGANT CHART:  ");
        for(i=0; i<=n; i++)
        {
            cout<<gantChart[i]<<" ";
        }
        for(i=1; i<=n; i++)
        {
            fcfs[i].rT = gantChart[i-1] - fcfs[i].aT;
            fcfs[i].tAt = gantChart[i] - fcfs[i].aT;
            fcfs[i].wT = fcfs[i].tAt - fcfs[i].bT;
        }
        printf("\n\n");
        cout<<"Process"<<"\t "<<"ArriveTime"<<"\t"<<"BurstTime"<<"\t";
        cout<<"ResponseTime"<<"\t"<<"WaitingTime"<<"\t"<<"TurnAroundTime"<<endl;
        for(i=1; i<=n; i++)
        {
            cout<<"   "<<fcfs[i].p<<" ";
            printf("%7d %15d %18d %12d %13d\n",fcfs[i].aT,fcfs[i].bT,fcfs[i].rT,fcfs[i].wT,fcfs[i].tAt);

        }
        cout<<endl<<endl;
    }
}

/*
2

5
p1 0 24
p2 0 3
p3 0 3
p4 0 1
p5 0 1

4
p1 0 8
p2 1 4
p3 2 9
p4 3 5
*/



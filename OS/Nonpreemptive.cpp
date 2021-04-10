#include<bits/stdc++.h>
using namespace std;
struct process{

    string p;
    int art,bt,rt,wt,tat,ft=0,st;

};

bool compare(process a, process b)
{
   if(a.art!=b.art)
    return a.art<b.art;
}
int main()
{
    process a[100];int s=0;
    for(int i=0;i<5;i++)
    {
        cin>>a[i].p>>a[i].art>>a[i].bt;

    }
    sort(a,a+5,compare);
    float rtn=0,wtn=0,tatt=0;

    for(int i=0;i<5;i++)
    {
        s+=a[i].bt;
        a[i].ft=s;
    }
     a[0].st=a[0].art;
    for(int i=1;i<5;i++)

    {

        a[i].st=a[i-1].bt;
    }

    for(int i=0;i<5;i++)
    {

        a[i].rt=a[i].st-a[i].art;
        a[i].tat=a[i].ft-a[i].art;
        a[i].wt=a[i].tat-a[i].bt;
        rtn+=a[i].rt;wtn+=a[i].wt;tatt+=a[i].tat;


    }
    cout<<endl;
    cout<<"ProcessTime      ArriveTime      BurstTime       ResponseTime      WaitingTime    TurnAroundTime"<<endl;

    for(int i=0;i<5;i++)
    {
        cout<<a[i].p<<"                  "<<a[i].art<<"                  "<<a[i].bt<<"               "<<a[i].rt<<"              "<<a[i].wt<<"              "<<a[i].tat<<"                "<<endl;
    }

    cout<<endl;

    float rrt=ceil(rtn/5);
    float wrt=ceil(wtn/5);
    float trt=ceil(tatt/5);

    if(rrt-rtn/5>=.5)cout<<rrt++<<endl;
    else cout<<rrt--<<endl;
    if(wrt-wtn/5>=.5)cout<<wrt++<<endl;
    else cout<<wrt--<<endl;
    if(trt-tatt/5>=.5)cout<<trt++<<endl;
    else cout<<trt--<<endl;




}


//p1 0 24
//p2 0 3
//p3 0 3
//p4 0 1
//p5 0 1


#include <bits/stdc++.h>
using namespace std;
struct RdRobin
{
    int pid, art, bt, rt, wt, tt, sum;
};
RdRobin arr[100];
int n,m,quanta,flag[100],complete[100],rq[100];
queue <RdRobin> q;
vector <RdRobin> v;

bool comp(RdRobin a, RdRobin b)
{
    return a.art<b.art;
}
int main()
{
    int i, j, k, t, p, rt_sum, wt_sum, tt_sum, cas=1;
    double a, b, c;
    a=b=c=0.0;
    rt_sum=wt_sum=tt_sum=0;
    while(!q.empty()) q.pop();
    for(i=0;i<n;i++) v.clear();
    scanf("%d",&n);
    for( i=0; i<n; i++)
    {
        arr[i].pid=i+1;
        scanf("%d %d", &arr[i].art, &arr[i].bt);
        arr[i].sum=arr[i].bt;
    }
    scanf("%d",&quanta);
    sort(arr,arr+n,comp);
    p=arr[0].art;
    q.push(arr[0]);
    rq[arr[0].pid]=1;
    for(i=1;i<n;i++)
    {
        if(p==arr[i].art)
        {
            q.push(arr[i]);
            rq[arr[i].pid]=1;
        }
    }
    t=arr[0].art;
    RdRobin a,b;
    while(!q.empty())
    {
        a=q.front();
        q.pop();
        p=a.pid();
        if(flag[p]==0 && complete[p]==0)
        {
            flag[p]=1;
            a.rt=t-a.art;
            if(a.bt>=quanta)
            {
                a.bt-=quanta;
                t+=quanta;
            }
            else
            {
                t+=a.bt;
                a.bt=0;
            }
            if(a.bt==0)
            {
                complete[p]=1;
                a.tt=t-a.art;
                a.wt=a.tt-a.sum;
                v.push_back(a);
            }
        }
        else if(flag[p]==1)
        {
            if
        }
    }
}

#include <bits/stdc++.h>
using namespace std;

struct RR
{
    int pid, at, bt, rt, wt, tt, sum;
};

RR arr[100];
int n, m, quanta, flag[100], complete[100], rq[100];
queue <RR> q;
vector <RR> v;

bool comp(RR a, RR b)
{
    return a.at<b.at;
}

bool comp1(RR a1, RR b1)
{
    return a1.pid<b1.pid;
}

int main()
{
    int i, j, k, t, p, rt_sum, wt_sum, tt_sum, cas=1;
    double a1, b1, c1;
    a1=b1=c1=0.0;
    rt_sum=wt_sum=tt_sum=0;
    while(!q.empty()) q.pop();
    for( i=0; i<n; i++) v.clear();
    scanf("%d", &n);
    for( i=0; i<n; i++)
    {
        arr[i].pid=i+1;
        scanf("%d %d", &arr[i].at, &arr[i].bt);
        arr[i].sum=arr[i].bt;
    }
    scanf("%d", &quanta);
    sort(arr, arr+n, comp);
    p=arr[0].at;
    q.push(arr[0]);
    rq[arr[0].pid]=1;
    for( i=1; i<n; i++)
    {
        if(p==arr[i].at)
        {
            q.push(arr[i]);
            rq[arr[i].pid]=1;
        }
    }
    t=arr[0].at;
    RR a, b;
    while(!q.empty())
    {
        a=q.front();
        q.pop();
        p=a.pid;
        if(flag[p]==0 && complete[p]==0)
        {
            flag[p]=1;
            a.rt=t-a.at;
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
                a.tt=t-a.at;
                a.wt=a.tt-a.sum;
                v.push_back(a);
            }
        }
        else if(flag[p]==1)
        {
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
                a.tt=t-a.at;
                a.wt=a.tt-a.sum;
                v.push_back(a);
            }
        }
        for( i=0; i<n; i++)
        {
            b=arr[i];
            if(rq[b.pid]==0 && b.at<=t && complete[b.pid]==0)
            {
                rq[b.pid]=1;
                q.push(b);
            }
        }
        if(complete[p]==0) q.push(a);
    }
    sort(v.begin(), v.end(), comp1);
    printf("Process Id\t Response Time\t Waiting Time\t Turn Around Time\t\n");
    for( i=0; i<v.size(); i++)
    {
        printf("%d\t\t %d\t\t %d\t\t %d\t\t\n", v[i].pid, v[i].rt, v[i].wt, v[i].tt);
        rt_sum+=v[i].rt;
        wt_sum+=v[i].wt;
        tt_sum+=v[i].tt;
    }
    a1=double(rt_sum)/double(n);
    b1=double(wt_sum)/double(n);
    c1=double(tt_sum)/double(n);

    if(a1-(int)a1 >=0.5) a1++;
    if(b1-(int)b1 >=0.5) b1++;
    if(c1-(int)c1 >=0.5) c1++;
    cout << int(a1) << " " << int(b1) << " " << int(c1) << endl;
    return 0;
}
/*
5
0 10
3 6
8 4
5 3
1 1
2
*/


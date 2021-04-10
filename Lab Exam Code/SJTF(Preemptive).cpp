#include <bits/stdc++.h>
using namespace std;
struct SJTF
{
    int pid, at, bt, rt, wt, tt, sum, sum1;
};
SJTF arr[100];
int n, m, mx, flag[100], complete[100];
vector <SJTF> v, v1, te;
vector<pair<int, int> > res;
bool comp(SJTF a, SJTF b)
{
    if(a.at==b.at) return a.bt<b.bt;
    return a.at<b.at;
}
bool comp1(SJTF a, SJTF b)
{
    if(a.bt==b.bt)
        return a.at<b.at && complete[a.pid]==0;
    return a.bt<b.bt && complete[a.pid]==0;
}
int main()
{
    int i, j, k, t, p, cnt, rt_sum, wt_sum, tt_sum, cas=1;
    double a1, b1, c1;
    cnt=0;
    a1=b1=c1=0.0;
    rt_sum=wt_sum=tt_sum=mx=0;
    scanf("%d", &n);
    for( i=0; i<n; i++)
    {
        cin>>arr[i].pid;
        scanf("%d %d", &arr[i].at, &arr[i].bt);
        arr[i].sum=arr[i].bt;
        mx=max( mx, arr[i].at);
    }
    sort(arr, arr+n, comp);
    SJTF a, b;
    p=arr[1].at;
    arr[0].rt=0;
    t=p;
    arr[0].bt-=(p-arr[0].at);
    res.push_back(make_pair(arr[0].rt, arr[0].pid));
    if(arr[0].bt==0)
    {
        complete[arr[0].pid]=1;
        a.rt=arr[0].rt;
        a.tt=t-a.rt;
        a.wt=a.tt-arr[0].sum;
        te.push_back(a);
        cnt++;
    }
    while(1)
    {
        if(cnt==n) break;
        v1.clear();
        m=p;
        for( i=0; i<n; i++)
        {
            if(arr[i].at<=m)
            {
                v1.push_back(arr[i]);
            }
        }
        sort(v1.begin(), v1.end(), comp1);
        if(complete[v1[0].pid]==0 && t!=mx)
        {
            p=v1[0].at;
            a.rt=t-p;
            res.push_back(make_pair(a.rt, v1[0].pid));
            t=p;
            arr[0].bt-=(p-arr[0].at);
            if(arr[0].bt==0)
            {
                complete[arr[0].pid]=1;
                a.rt=arr[0].rt;
                a.tt=t-a.rt;
                a.wt=a.tt-arr[0].sum;
                v.push_back(a);
                cnt++;
            }
        }
        else if(complete[v1[0].pid]==0 && t==mx)
        {
            p=v1[0].at;
            a.rt=t-p;
            res.push_back(make_pair(a.rt, v1[0].pid));
            t=p;
            arr[0].bt-=(p-arr[0].at);
            if(arr[0].bt==0)
            {
                complete[arr[0].pid]=1;
                a.rt=arr[0].rt;
                a.tt=t-a.rt;
                a.wt=a.tt-arr[0].sum;
                v.push_back(a);
                cnt++;
            }
        }
    }
    printf("Response Time\t\t Waiting Time\t\t Turn Around Time\t\t\n");
    for( i=0; i<n; i++)
    {
        printf("%d\t\t\t %d\t\t\t %d\t\t\t\n", arr[i].rt, arr[i].wt, arr[i].tt);
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
4
0 8
1 4
2 9
3 5
*/


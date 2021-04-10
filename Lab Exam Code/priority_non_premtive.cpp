#include <bits/stdc++.h>
using namespace std;

struct Priority
{
    int pid, art, bt, pt, rt, wt, tt, sum;
};
Priority arr[100];
int n,m;

bool comp(Priority a, Priority b)
{
    if(a.art==b.art)
    {
        if(a.pt==b.pt)
            return a.bt<b.bt;
        return a.pt>b.pt;
    }
    return a.art<b.art;
}

bool comp1(Priority a, Priority b)
{
    if(a.pt==b.pt)
    {
        if(a.bt==a.bt) return a.art<b.art &&a.art<=m;
        return a.bt<b.bt && a.art<=m;
    }
    return a.pt>b.pt && a.art<=m;
}

bool comp2(Priority a, Priority b)
{
    if(a.art!=b.art)
    {
        return a.art<b.art;
    }
}

int main()
{
    int i, j, k, t, p, rt_sum, wt_sum, tt_sum, cas=1;
    double a, b, c;
    a=b=c=0.0;
    rt_sum=wt_sum=tt_sum=0;
    cin>>n;
    for( i=0; i<n; i++)
    {
        arr[i].pid=i;
        cin>>arr[i].art>>arr[i].bt>>arr[i].pt;
    }
    sort(arr, arr+n, comp);
    arr[0].rt=arr[0].wt=0;
    arr[0].sum=arr[0].art+arr[0].bt;
    arr[0].tt=arr[0].bt;
    rt_sum+=arr[0].rt;
    wt_sum+=arr[0].wt;
    tt_sum+=arr[0].tt;
    for( i=1; i<n; i++)
    {
        m=arr[i-1].sum;
        sort(arr+i, arr+n, comp1);
        arr[i].sum=arr[i-1].sum+arr[i].bt;
        arr[i].rt=arr[i-1].sum-arr[i].art;
        arr[i].tt=arr[i].sum-arr[i].art;
        arr[i].wt=arr[i].tt-arr[i].bt;
        rt_sum+=arr[i].rt;
        wt_sum+=arr[i].wt;
        tt_sum+=arr[i].tt;
    }
    sort(arr, arr+n, comp2);
    printf("Response Time\t\t Waiting Time\t\t Turn Around Time\t\t\n");
    for( i=0; i<n; i++)
    {
        printf("%d\t\t\t %d\t\t\t %d\t\t\t\n", arr[i].rt, arr[i].wt, arr[i].tt);
    }
    a=double(rt_sum)/double(n);
    b=double(wt_sum)/double(n);
    c=double(tt_sum)/double(n);

    if(a-(int)a >=0.5) a++;
    if(b-(int)b >=0.5) b++;
    if(c-(int)c >=0.5) c++;
    cout << int(a) << " " << int(b) << " " << int(c) << endl;
    return 0;
}
/*
7
0 4 2
1 2 4
2 3 6
3 5 10
4 1 8
5 4 12
6 6 9
*/


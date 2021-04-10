#include <bits/stdc++.h>
using namespace std;
struct SJTF
{
    int pid, at, bt, rt, wt, tt, sum;
};
SJTF arr[100];
int n, m;
bool comp(SJTF a, SJTF b)
{
    if(a.at==b.at) return a.bt<b.bt;
    return a.at<b.at;
}
bool comp1(SJTF a, SJTF b)
{
    if(a.bt==b.bt)
        return a.at<b.at && a.at<=m;
    return a.bt<b.bt && a.at<=m;
}
int main()
{
    int i, j, k, t, p, rt_sum, wt_sum, tt_sum, cas=1;
    double a, b, c;
    a=b=c=0.0;
    rt_sum=wt_sum=tt_sum=0;
    scanf("%d", &n);
    for( i=0; i<n; i++)
    {
        arr[i].pid=i;
        scanf("%d %d", &arr[i].at, &arr[i].bt);
    }
    sort(arr, arr+n, comp);
    arr[0].rt=arr[0].wt=0;
    arr[0].sum=arr[0].at+arr[0].bt;
    arr[0].tt=arr[0].bt;
    rt_sum+=arr[0].rt;
    wt_sum+=arr[0].wt;
    tt_sum+=arr[0].tt;
    for( i=1; i<n; i++)
    {
        m=arr[i-1].sum;
        sort(arr+i, arr+n, comp1);
        arr[i].sum=arr[i-1].sum+arr[i].bt;
        arr[i].rt=arr[i-1].sum-arr[i].at;
        arr[i].tt=arr[i].sum-arr[i].at;
        arr[i].wt=arr[i].tt-arr[i].bt;
        rt_sum+=arr[i].rt;
        wt_sum+=arr[i].wt;
        tt_sum+=arr[i].tt;
    }
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
4
0 8
1 4
2 9
3 5
*/

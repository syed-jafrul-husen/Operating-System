#include <bits/stdc++.h>
using namespace std;
struct SJTF
{
    int pid, at, bt, rt, wt, tt, sum,btTemp;
    string process;
};
SJTF arr[100];
int n, m;

bool comp(SJTF a, SJTF b)
{
    if(a.at==b.at) return a.bt<b.bt;
    return a.at<b.at;
}

struct db
{
    int start,finish;
    string process;
};

int main()
{
    int i, j, k, t, p, rt_sum, wt_sum, tt_sum, cas=1;
    double a, b, c;
    a=b=c=0.0;
    rt_sum=wt_sum=tt_sum=0;
    scanf("%d", &n);
    int mxAt = 0;
    for( i=0; i<n; i++)
    {
        arr[i].pid=i;
        cin>>arr[i].process>>arr[i].at>>arr[i].bt;
        arr[i].btTemp = arr[i].bt;
        mxAt = max(mxAt,arr[i].at);
    }
    sort(arr, arr+n, comp);
    vector<db>gc;
    db pus = {arr[0].at,arr[0].at+1,arr[0].process};
    --arr[0].bt;
    gc.push_back( pus );
    for(i=0; i<mxAt; i++)
    {
        sort(arr, arr+n, comp);
        int temp;

    }


    return 0;
}
/*
4
0 8
1 4
2 9
3 5
*/

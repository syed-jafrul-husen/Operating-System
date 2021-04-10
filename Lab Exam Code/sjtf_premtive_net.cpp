#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[205][8],i,cnt=0,totalt,mn,n,temp[205];
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
        cnt+=a[i][2];
        a[i][6]=-1;
    }
    mn=a[0][1];
    for(i=0; i<n; i++)
    {
        if(mn>a[i][1])
            mn=a[i][1];
        temp[i]=a[i][2];
    }
    totalt=mn;
    cnt=cnt+mn;

    for(i=0; i<n; i++)
    {
        a[i][7] = -1;
    }

    while(totalt<cnt)
    {
        for(i=0; i<n; i++)
        {
            if(a[i][6]==-1 && a[i][1]<=totalt)
            {
                a[i][7]=totalt;
                mn=i;
                break;
            }
        }

        for(i=0; i<n; i++)
        {
            if(a[i][6]==-1 && a[i][1]<=totalt)
            {
                if(a[mn][2]>a[i][2])
                    mn=i;
            }
        }

        totalt++;
        a[mn][2]--;
        if(a[mn][2]==0)
        {
            a[mn][6]=0;
            a[mn][3]=totalt;

        }

    }

    for(i=0; i<n; i++)
    {

        a[i][4]=a[i][3]-a[i][1];
        a[i][5]=a[i][4]-temp[i];
        int st =
        printf("P%d %d %d %d %d\n",a[i][0],a[i][5],a[i][5],a[i][4],a[i][3]);
    }

    return 0;
}

/*
4
0 0 8
1 1 4
2 2 9
3 3 5
*/

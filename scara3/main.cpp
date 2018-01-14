#include <stdio.h>

FILE *f1 = fopen("scara3.in","r");
FILE *f2 = fopen("scara3.out","w");

const int N = 1205;

int n, k, l, i, j;
int a[N], e[N], pasi[N], cost[N];

void check(int s,int p,int c)
{
    if(pasi[s] > p)
    {
        pasi[s] = p;
        cost[s] = c;
    }

    else if(pasi[s] == p && cost[s] > c)
        cost[s] = c;
}

int main()
{
    fscanf(f1,"%d%d",&n,&k);
    while(k--)
    {
        fscanf(f1,"%d%d",&i,&j);
        a[i] = j;
    }
    fscanf(f1,"%d",&l);
    while(l--)
    {
        fscanf(f1,"%d%d",&i,&j);
        e[i] = j;
    }

    for(i=2;i<=n;i++)
        pasi[i] = N;

    pasi[1] = 1;
    for(i=1;i<n;i++)
    {
        if(a[i] != 0)
        {
            for(j=1;j<=a[i];j++)
            {
                check(i+j, pasi[i]+1, cost[i]);

                if(j+i >= n)
                    break;
            }
        }
        if(e[i] != 0)
        {
            for(j=2;j<=e[i]*2;j++)
            {
                check(i+j, pasi[i]+1, cost[i] + j/2 + j%2);

                if(j+i >= n)
                    break;
            }
        }
        check(i+1, pasi[i]+1, cost[i]);
    }

    fprintf(f2,"%d %d",pasi[n],cost[n]);

    return 0;
}

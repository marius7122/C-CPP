#include <stdio.h>

long i,k,n,v[5000005],d[5000005],p,u;
long long sum;

int main()
{
    FILE *f1,*f2;
    f1=fopen("deque.in","r");
    f2=fopen("deque.out","w");

    fscanf(f1,"%ld%ld",&n,&k);

    p=d[1]=1;u=0;
    for(i=1;i<=n;i++)
    {
        fscanf(f1,"%ld",&v[i]);

        while(v[i]<v[d[u]] && u>=p)
            u--;

        d[++u]=i;

        if(d[p]==i-k)
            p++;
        if(i>=k)
            sum+=v[d[p]];
    }

    fprintf(f2,"%lld",sum);
    return 0;
}
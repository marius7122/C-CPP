#include <stdio.h>

FILE *f1 = fopen("secv2.in","r");
FILE *f2 = fopen("secv2.out","w");

const int N = 50005;

int n, k, i, prim, auxSum, bestSum, bestPrim, bestUltim;
int v[N], sum[N];

int main()
{
    fscanf(f1,"%d%d",&n,&k);

    for(i=1;i<=k;i++)
    {
        fscanf(f1,"%d",&v[i]);
        sum[i] = sum[i-1] + v[i];
    }

    bestSum = sum[k];
    bestPrim = 1;
    bestUltim = k;

    prim = 1;
    auxSum = sum[k];
    for(i=k+1;i<=n;i++)
    {
        fscanf(f1,"%d",&v[i]);

        auxSum += v[i];

        if(sum[i - k] - sum[prim - 1] < 0)
        {
            auxSum -= sum[i - k] - sum[prim - 1];
            prim = i - k + 1;
        }

        if(auxSum > bestSum)
        {
            bestSum = auxSum;
            bestPrim = prim;
            bestUltim = i;
        }

    }

    fprintf(f2,"%d %d %d",bestPrim,bestUltim,bestSum);

    return 0;
}

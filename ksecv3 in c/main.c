#include <stdio.h>

int n, k, i, x, q;
long long sum, aux;
int sol[100005];

int main(void)
{
    FILE *f1 = fopen("ksecv3.in","r");
    FILE *f2 = fopen("ksecv3.out","w");

    fscanf(f1,"%d%d",&n,&k);
    for(i=1;i<=n;i++)
    {
        fscanf(f1,"%d",&x);
        sum += x;
    }

    fclose(f1);
    f1 = fopen("ksecv3.in","r");
    fscanf(f1,"%d%d",&n,&k);

    if(sum % k != 0)
    {
        fprintf(f2,"-1");
        return 0;
    }

    sum /= k;

    i=1;
    while(i<=n)
    {
        aux = 0;
        while(aux < sum && !feof(f1))
        {
            fscanf(f1,"%d",&x);
            aux += x;
            i++;
        }

        if(aux > sum)
        {
            fprintf(f2,"-1");
            return 0;
        }

        if(feof(f1) && aux != sum)
        {
            fprintf(f2,"-1");
            return 0;
        }

        sol[q++] = i-1;
    }

    for(i=0;i<k;i++)
        fprintf(f2,"%d ",sol[i]);

    return 0;
}

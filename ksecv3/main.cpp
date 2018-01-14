#include <stdio.h>

FILE *f1 = fopen("ksecv3.in","r");
FILE *f2 = fopen("ksecv3.out","w");

const int N = 100005;

int n, k, i, x, q;
long long sum, aux;
unsigned short sol[N];

int main()
{
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
            fclose(f2);
            f2 = fopen("ksecv3.out","w");
            fprintf(f2,"-1");
            return 0;
        }

        if(feof(f1) && aux != sum)
        {
            fclose(f2);
            f2 = fopen("ksecv3.out","w");
            fprintf(f2,"-1");
            return 0;
        }

        fprintf(f2,"%d ",i-1);
    }

    return 0;
}

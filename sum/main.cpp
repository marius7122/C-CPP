#include <stdio.h>

FILE *f1 = fopen("sum.in","r");
FILE *f2 = fopen("sum.out","w");

const int X = 100000;

int i, j, n, x, y, phi[X+5];
long long sol;

void generatePhi()
{
    for(i=1;i<=X;i++)
        phi[i] = i - 1;

    int q;
    for(i=2;i<=X/2;i++)
        for(j=2*i, q=1; j<=X; j+=i, q++)
            phi[j] -= phi[i];

}

int main()
{
    generatePhi();

    fscanf(f1,"%d",&n);

    while(n--)
    {
        fscanf(f1,"%d",&x);

        sol = 2LL * x * phi[x];

        fprintf(f2,"%lld\n",sol);
    }

    return 0;
}

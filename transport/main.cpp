#include <stdio.h>

#define OK printf("OK\n")

FILE *f1 = fopen("transport.in","r");
FILE *f2 = fopen("transport.out","w");

const int N = 16005;

int n,k,i;
int v[N],sum[N];

///returneaza indicele ultimului element din v <= nr
int bs(int v[N],int nr)
{
    int pas = 1 << 14;
    int sol = 0;

    while(pas)
    {
        if(sol + pas <= n && v[sol + pas] <= nr)
            sol += pas;

        pas >>= 1;
    }

    return sol;
}

///verifica daca vol este destul de mare pentru a face max k transporturi
bool check(int vol)
{
    int i = 0;
    int q = 0;

    while(i < n && q <= k)
    {
        i = bs(sum, sum[i] + vol);
        q++;
    }

    if(q == k + 1)
        return false;

    return true;
}

int main()
{
    fscanf(f1,"%d%d",&n,&k);
    for(i=1;i<=n;i++)
    {
        fscanf(f1,"%d",&v[i]);
        sum[i] = sum[i-1] + v[i];
    }

    int ok = 1;

    ///cautam o capacitate buna
    while(!check(ok))
        ok <<= 1;
        //printf("%d\n",ok);

    ///cautam capacitatea optima
    int pas = 1;
    int sol = 0;
    while (pas < ok)
        pas <<= 1;


    while(pas)
    {
        if(sol + pas < ok && !check(sol + pas))
            sol += pas;

        pas >>= 1;
    }

    fprintf(f2,"%d",sol + 1);



    return 0;
}

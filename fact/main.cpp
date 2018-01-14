#include <stdio.h>

FILE *f1 = fopen("fact.in","r");
FILE *f2 = fopen("fact.out","w");

int n,sol,pas,x;

int zeroNum(int x)
{
    int sol = 0;

    while(x)
    {
        x/=5;
        sol+=x;
    }

    return sol;
}

int main()
{

    fscanf(f1,"%d",&n);

    pas = 1<<30;

    while(pas)
    {
        if(zeroNum(sol + pas) < n)
            sol += pas;

        pas>>=1;
    }

    if(zeroNum(sol+1) != n)
        fprintf(f2,"-1");

    else
        fprintf(f2,"%d",sol+1);

    return 0;
}

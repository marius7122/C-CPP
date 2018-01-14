#include <stdio.h>

FILE *f1 = fopen("3cifre.in","r");
FILE *f2 = fopen("3cifre.out","w");

int n,cerinta,nrMin,nrMax,nrApMin,nrApMax;
unsigned nr,ap1,ap2,AP1,AP2;
int ap[1000];

void procAux(int aux)
{
    if(aux < 100)
        return;

    ap[aux]++;

    if(aux == nrMin)
    {
        nrApMin++;
        ap2 = aux;
    }
    if(aux < nrMin)
    {
        nrMin = aux;
        nrApMin = 1;
        ap1 = ap2 = nr;
    }

    if(aux == nrMax)
    {
        nrApMax++;
        AP2 = aux;
    }
    if(aux > nrMax)
    {
        nrMax = aux;
        nrApMax = 1;
        AP1 = AP2 = nr;
    }
}

void proceseaza(unsigned nr)
{
    int aux = 0;

    while(nr)
    {
        if(aux == 0)
        {
            aux = nr%1000;
            nr /= 1000;
        }
        else
        {
            aux = aux/10;
            aux = nr%10 * 100 + aux;
            nr /= 10;
        }

        procAux(aux);
    }
}

int main()
{
    nrMin = 1000;

    fscanf(f1,"%u%d",&n,&cerinta);
    for(int i=0;i<n;i++)
    {
        fscanf(f1,"%d",&nr);
        proceseaza(nr);
    }

    if(cerinta == 1)
    {
        fprintf(f2,"%d %d %u %u\n",nrMin,nrApMin,ap1,ap2);
        fprintf(f2,"%d %d %u %u\n",nrMax,nrApMax,AP1,AP2);
    }
    if(cerinta == 2)
    {
        int maxAp = 0;
        for(int i = 100;i<1000;i++)
            if(ap[i] > maxAp)
                maxAp = ap[i];

        for(int i = 100;i<1000;i++)
            if(ap[i] == maxAp)
                fprintf(f2,"%d ",i);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define swap(a,b) {int aux=a;a=b;b=aux;}

FILE *f1 = fopen("sdo.in","r");
FILE *f2 = fopen("sdo.out","w");

const int N = 3000005;
int n,k,sol,i;
int v[N];

void citeste()
{
    fscanf(f1,"%d%d",&n,&k);
    for(i=0;i<n;i++)
        fscanf(f1,"%d",&v[i]);
}

int partitie(int st,int dr)
{
    int p = rand() % (dr - st + 1) + st;
    swap(v[p],v[dr]);

    int i,j;
    i = st-1;
    j = dr;

    while(true)
    {
        do
        {
            i++;
        }while(i < dr && v[i] < v[dr]);
        do
        {
            j--;
        }while(j > st && v[j] > v[dr]);

        if(i < j)
            swap(v[i],v[j])
        else
        {
            swap(v[i], v[dr]);
            return i;
        }
    }
}

void selectieAleatoare(int st,int dr,int i)
{
    if(st == dr)
    {
        sol = v[st];
        return;
    }

    int p = partitie(st,dr);
    int k = p - st + 1;

    if(i>k)
        selectieAleatoare(p+1,dr,i-k);
    else
        selectieAleatoare(st,p,i);
}

int main()
{
    citeste();

    selectieAleatoare(0,n-1,k);

    fprintf(f2,"%d ",sol);
    return 0;
}

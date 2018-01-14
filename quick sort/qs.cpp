#include <stdio.h>
#include <stdlib.h>

#define swap(a,b) {int aux=a;a=b;b=aux;}

FILE *f1 = fopen("algsort.in","r");
FILE *f2 = fopen("algsort.out","w");

const int N = 500005;
int n,i;
int v[N];

void citeste()
{
    fscanf(f1,"%d",&n);
    for(i=0;i<n;i++)
        fscanf(f1,"%d",&v[i]);
}

void scrie()
{
    for(i=0;i<n;i++)
        fprintf(f2,"%d ",v[i]);
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

void sorteaza(int st,int dr)
{
    if(st >= dr)
        return;

    int p = partitie(st, dr);
    sorteaza(st,p);
    sorteaza(p+1,dr);
}

int main()
{
    citeste();
    sorteaza(0,n-1);
    scrie();

    return 0;
}

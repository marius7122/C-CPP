#include <stdio.h>
#include <stdlib.h>

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

int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

void sorteza()
{
    qsort(v,n,sizeof(int),cmp);
}

int main()
{

    citeste();
    sorteza();
    scrie();

    return 0;
}

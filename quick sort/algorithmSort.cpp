#include <stdio.h>
#include <algorithm>

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

void sorteza()
{
    std::sort(v, v+n);
}

int main()
{

    citeste();
    sorteza();
    scrie();

    return 0;
}

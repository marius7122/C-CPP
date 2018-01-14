#include <stdio.h>
#include <string.h>

const int L = 2510;
struct huge
{
    int l;
    char cif[L];
};

FILE *f1 = fopen("biti2.in","r");
FILE *f2 = fopen("biti2.out","w");

const int p2 = 1<<20;

huge x;
int n, ord;
bool sch[p2];

void genereazaSch()
{
    int i,j,p=1;
    for(i=1;i<p2;)
    {
        for(j=0;j<p;j++,i++)
            sch[i] = !sch[i-p];

        p*=2;
    }
}

inline int div(int d)
{
    int i, r=0;

    for(i=x.l-1; i>=0; i--)
    {
        r = 10 * r + x.cif[i];
        x.cif[i] = r / d;
        r %= d;
    }

    while(x.l && !x.cif[x.l-1])
        x.l--;

    return r;
}

inline void citeste()
{
    fscanf(f1,"%s\n",x.cif);

    x.l = strlen(x.cif);

    int i,j;
    char aux;
    for(i=0, j=x.l - 1; i<=j; i++, j--)
    {
        x.cif[i] -= '0';
        if(i != j)
            x.cif[j] -= '0';

        aux = x.cif[i];
        x.cif[i] = x.cif[j];
        x.cif[j] = aux;
    }

}

int main()
{
    fscanf(f1,"%d\n",&n);

    genereazaSch();

    while(n--)
    {
        citeste();

        ord = 0;

        while(x.l)
        {
            int d = div(p2);
            if(sch[d])
                ord = 1-ord;
        }

        fprintf(f2,"%d\n",ord);
    }

    return 0;
}

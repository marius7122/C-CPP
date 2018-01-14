#include <stdio.h>
#include <string.h>

FILE *f1 = fopen("next.in","r");
FILE *f2 = fopen("next.out","w");

const int max_cif = 1000005;

char nr[max_cif],aux;
long long d, r;
int i, j, l;

///nr += d - r
void add()
{
    int i, R=0;

    r = d - r;

    for(i=0; i<l; i++)
    {
        nr[i] += r%10 + R;
        r/=10;
        R = nr[i] / 10;
        nr[i] %= 10;
    }

    if(R)
        nr[++l - 1] = R;
}

///r <- nr % d
void mod()
{
    r = 0;
    for(int i = l-1; i>=0; i--)
        r = (r*10 + nr[i])%d;
}


int main()
{
    fscanf(f1,"%s\n%lld",nr, &d);
    l = strlen(nr);

    for(i=0, j=l-1; i<=j; i++, j--)
    {
        nr[i] = nr[i] - '0';
        if(i != j)
            nr[j] = nr[j] - '0';

        aux = nr[i];
        nr[i] = nr[j];
        nr[j] = aux;
    }

    mod();
    if(r != 0)
        add();

    for(i = l-1; i >= 0; i--)
        fprintf(f2,"%d",nr[i]);



    return 0;
}

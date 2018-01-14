#include <stdio.h>

FILE *f1 = fopen("par.in","r");
FILE *f2 = fopen("par.out","w");

int n,st,pasi;
char c;

int main()
{
    fscanf(f1,"%d\n",&n);

    while(n--)
    {
        fscanf(f1,"%c",&c);

        if(c == ')')
            st--;
        if(c == '(')
            st++;

        if(st<0)
            pasi++,
            st+=2;
    }

    if(st%2)
        fprintf(f2,"-1");
    else
        fprintf(f2,"%d",pasi + st/2);

    return 0;
}

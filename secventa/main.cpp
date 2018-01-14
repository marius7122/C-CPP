#include <stdio.h>

FILE *f1 = fopen("secventa.in","r");
FILE *f2 = fopen("secventa.out","w");

const int buffSize = 100000;
char buff[buffSize];
int buffPoz;
inline void citeste(int &nr)
{
    ///inca nu am citit nimic
    if(buff[0] == 0)
        fread(buff,1,buffSize,f1);

    char semn = '+';
    while(buff[buffPoz]<'0' || buff[buffPoz]>'9')
    {
        semn = buff[buffPoz];
        if(++buffPoz == buffSize)
            fread(buff,1,buffSize,f1),
            buffPoz = 0;
    }
    nr = 0;
    while(buff[buffPoz]>='0' && buff[buffPoz]<='9')
    {
        nr = nr * 10 + buff[buffPoz] - '0';
        if(++buffPoz == buffSize)
            fread(buff,1,buffSize,f1),
            buffPoz = 0;
    }
    if(semn == '-')
        nr *= -1;
}

const int N = 500005;

int n,k,i,prim,ultim,sol,solPrim,solUltim;
int v[N], d[N];

int main()
{
    //fscanf(f1,"%d%d",&n,&k);
    citeste(n);
    citeste(k);

    sol = v[0] = -30001;
    for(i=1;i<=n;i++)
    {
        //fscanf(f1,"%d",&v[i]);
        citeste(v[i]);

        if(i - d[prim] >= k)
            prim++;

        while(prim <= ultim && v[i] < v[d[ultim]])
            ultim--;
        d[++ultim] = i;

        if(i >= k && v[d[prim]] > sol)
        {
            sol = v[d[prim]];
            solPrim = i-k+1;
            solUltim = i;
        }
    }

    fprintf(f2,"%d %d %d",solPrim, solUltim, sol);

    return 0;
}

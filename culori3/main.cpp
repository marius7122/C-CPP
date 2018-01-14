#include <stdio.h>

FILE * f1 = fopen("culori3.in","r");
FILE * f2 = fopen("culori3.out","w");

const int CIF = 5001;
const int N = 5001;

class huge
{
    public:
    char cif[CIF];
    int l;

    void afis(char c)
    {
        for(int i=l-1; i>=0; i--)
            printf("%d",cif[i]);
        printf("%c",c);
    }

    inline void atr(int n)
    {
        while(n)
        {
            cif[l++] = n%10;
            n /= 10;
        }
    }

    inline void atrHuge(huge x)
    {
        for(int i=0;i<x.l;i++)
            cif[i] = x.cif[i];
        l = x.l;
    }

    inline void add(huge x)
    {
        int i, r = 0;

        if(x.l > l)
        {
            for(i = l; i<x.l; i++)
                cif[i] = 0;
            l = x.l;
        }
        else
            for(i = x.l; i<=l; i++)
                x.cif[i] = 0;


        for(i=0;i<l;i++)
        {
            cif[i] += x.cif[i] + r;
            r = cif[i]/10;
            cif[i] %= 10;
        }

        if(r)
            cif[l++] = r;
    }
};

/*
 * d[i][j] = in cate moduri se poate ajunge la o configuratie de j scanduri care se termina cu scandura i
 * i : 0-alb; 1-albastru; 2-rosu; 3-verde; 4-galben
 * pentru eficenta memorez doar 2 coloane in d
*/
huge d[3][2], sol;
int n, i, ord;

int main()
{
    fscanf(f1,"%d",&n);

    for(i=0;i<3;i++)
        d[i][0].atr(1);

    for(i=1, ord=1; i<n; i++, ord=1-ord)
    {
        ///alb
        d[0][ord].atrHuge(d[1][1-ord]);
        ///albastru
        d[1][ord].atrHuge(d[0][1-ord]);
        d[1][ord].add(d[2][1-ord]);
        ///rosu
        d[2][ord].atrHuge(d[1][1-ord]);
        d[2][ord].add(d[1][1-ord]);

        /* este necesar sa generam numai o jumatate
        ///verde
        d[3][ord].atrHuge(d[2][1-ord]);
        d[3][ord].add(d[4][1-ord]);
        ///galben
        d[4][ord].atrHuge(d[3][1-ord]);*/
    }

    ord = 1 - ord;

    sol.atrHuge(d[2][ord]);
    for(i=0;i<2;i++)
    {
        sol.add(d[i][ord]);
        sol.add(d[i][ord]);
    }

    for(i=sol.l-1; i>=0; i--)
        fprintf(f2,"%d",sol.cif[i]);

    return 0;
}

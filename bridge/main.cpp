#include <stdio.h>

FILE *f1 = fopen("bridge.in","r");
FILE *f2 = fopen("bridge.out","w");

const int N = 4005;
const int mod = 666013;

int n, m, i, j, x, k, nrt;
int sc[N], dest[N], d[N][N];
///d[i][j] -> in cate moduri se ajunge pe scandura j in i pasi

int main()
{
    fscanf(f1,"%d%d",&n,&m);
    for(i=1;i<=n;i++)
        fscanf(f1,"%d",&sc[i]);
    for(i=1;i<=n;i++)
        if(sc[i] == 3)
            fscanf(f1,"%d",&dest[i]);

    d[1][1] = 1;
    if(sc[2] == 0 || (sc[2] == 3 && (sc[dest[2]] == 0 || sc[dest[2]] == 3)))
        d[1][2] = 1;
    
    for(i=2;i<N;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(sc[j] == 0 || sc[j] == 1)
                d[i][j] += d[i-1][j];

            if(sc[j] == 0 || sc[j] == 1)
            {
                d[i][j+1] += d[i-1][j];
                if(sc[j+2] == 0 || sc[j+2] == 3)
                    d[i][j+2] += d[i-1][j];
            }

            if(sc[j] == 3 && sc[dest[j]] != 1)
            {
                d[i][dest[j]] += d[i-1][j];
            }

            if(sc[j] == 2 || (sc[j] == 3 && (sc[dest[j]] == 1 || sc[dest[j]] == 2)))
                d[i][j] = 0;

            while(d[i][j] > mod)
                d[i][j] -= mod;
        }
    }

    while(m--)
    {
        fscanf(f1,"%d%d",&x,&k);

        fprintf(f2,"%d\n",d[k][x]);
    }

    return 0;
}

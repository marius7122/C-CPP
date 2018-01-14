#include <stdio.h>

FILE *f1 = fopen("in.txt","r");
FILE *f2 = fopen("out.txt","w");

const int N = 2005;


int n,m;
bool g[N][N];


void invers()
{
    int i,j,x,y;

    fscanf(f1,"%d%d",&n,&m);
    for(i=0;i<m;i++)
    {
        fscanf(f1,"%d%d",&x,&y);
        g[x][y] = g[y][x] = true;
    }

    for(i=1;i<n;i++)
        for(j=i+1;j<=n;j++)
            if(!g[i][j])
                fprintf(f2,"%d %d\n",i,j),
                printf("%d %d\n",i,j);
}

int main()
{
    invers();
    return 0;
}

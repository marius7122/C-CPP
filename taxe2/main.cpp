#include <stdio.h>
#include <queue>

using namespace std;

struct point
{
    char x,y;
};

FILE * f1 = fopen("taxe2.in","r");
FILE * f2 = fopen("taxe2.out","w");

const int N = 105;
const int MAX = 10100;


int d[N][N],c[N][N];
int n,s,i,j;

queue<point> coada;
bool inCoada[N*N];

int dirX[] = {0,1,0,-1};
int dirY[] = {1,0,-1,0};
int dir;

void init()
{
    for(i=0;i<=n+1;i++)
        c[0][i] = c[n+1][i] = MAX;
    for(i=1;i<=n;i++)
        c[i][0] = c[i][n+1] = MAX;

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            d[i][j] = MAX;

}

void afis(int mat[N][N])
{
    int i,j;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d ",mat[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main()
{
    fscanf(f1,"%d%d",&s,&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            fscanf(f1,"%d",&c[i][j]);

    init();

    int li = 0, ls = 0, C, E;
    point p;
    int X,Y;

    coada.push({1,1});
    inCoada[1] = true;
    d[1][1] = c[1][1];


    while(!coada.empty())
    {
        p = coada.front();

        for(dir=0;dir<4;dir++)
        {
            X = p.x + dirX[dir];
            Y = p.y + dirY[dir];
            C = c[X][Y] + d[p.x][p.y];
            E = (X-1) * n + Y;

            if(C < d[X][Y] && C <= s)
            {
                if(!inCoada[E])
                {
                    coada.push({X,Y});
                    inCoada[E] = true;
                }
                d[X][Y] = C;

            }
        }

        E = (p.x-1) * n + p.y;

        inCoada[E] = false;
        coada.pop();
    }

    int sol;

    sol = s - d[n][n];

    if(sol < 0)
        sol = -1;

    fprintf(f2,"%d",sol);

    p.x = p.y = 100;


    return 0;
}

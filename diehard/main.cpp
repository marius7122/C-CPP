#include <stdio.h>
#include <vector>

const int N = 1001;
const int inf = 10000000;

FILE *f1 = fopen("diehard.in","r");
FILE *f2 = fopen("diehard.out","w");

int n,m,i,j;
int d[N][N];
short v[N];

bool checkPos(int x,int y)
{
    if(x < 0 || y >= m || x >= n)
        return false;
    return true;
}

int dirX[] = {-1, 0, 1};
int dirY[] = {0, -1, 0};
void drum(int x,int y)
{
    char ord;

    if(y == 0)
    {
        fprintf(f2,"%d ",x+1);
        return;
    }

    int X,Y,dir,min=inf,pmin;

    for(dir=0;dir<3;dir++)
    {
        X = x + dirX[dir];
        Y = y + dirY[dir];

        if(checkPos(X,Y))
            if(d[X][Y] < min)
            {
                min = d[X][Y];
                pmin = dir;
            }
    }

    drum(x+dirX[pmin], y+dirY[pmin]);

    if(pmin == 0) ord = 'S';
    if(pmin == 1) ord = 'E';
    if(pmin == 2) ord = 'N';

    fprintf(f2,"%c",ord);
}

void verificaNod(int x,int y)
{
    int dir,X,Y,min=inf;
    for(dir=0;dir<3;dir++)
    {
        X = x + dirX[dir];
        Y = y + dirY[dir];

        if(checkPos(X,Y))
            if(d[X][Y] < min)
                min = d[X][Y];
    }

    d[x][y] = v[x] + min;
}

void creeazaMatrice()
{
    int i,j;
    for(j=1;j<m;j++)
    {
        for(i=0;i<n;i++)
        {
            v[i] = d[i][j];
            d[i][j] = inf;
        }

        for(i=0;i<n;i++)
            verificaNod(i,j);
        for(i=n-1;i>=0;i--)
            verificaNod(i,j);
    }
}

int main()
{
    fscanf(f1,"%d%d",&n,&m);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            fscanf(f1,"%d",&d[i][j]);
        }

    creeazaMatrice();

    int min=0;
    for(i=1;i<n;i++)
        if(d[i][m-1] < d[min][m-1])
            min = i;


    fprintf(f2,"%d\n",d[min][m-1]);

    drum(min,m-1);

    return 0;
}

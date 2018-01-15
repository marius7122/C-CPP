#include <stdio.h>
#include <vector>
#include <algorithm>

const int N = 1005;
const int inf = 10000000;

struct ind
{
    int x,i;
}v[N];

bool cmp(ind a,ind b)
{
    return a.x < b.x;
}


FILE *f1 = fopen("diehard.in","r");
FILE *f2 = fopen("diehard.out","w");

int n,m,i,j;
int d[N][N];
short mat[N][N];

bool checkPos(int x,int y)
{
    if(x < 0 || y >= m || x >= n)
        return false;
    return true;
}

int dirX[] = {-1, 0, 1};
int dirY[] = {0, 1, 0};
void dfs(int x, int y)
{
    int X,Y,c;
    for(int dir=0;dir<3;dir++)
    {
        X = x + dirX[dir];
        Y = y + dirY[dir];

        if(!checkPos(X,Y))
            continue;

        c = d[x][y] + mat[X][Y];
        if(d[X][Y] > c)
        {
            d[X][Y] = c;
            dfs(X,Y);
        }
    }
}

std::vector<char> ord;
int start;
void drum(int x,int y)
{
    //printf("%d %d\n",x,y);

    if(y == 0)
    {
        start = x;
        return;
    }

    int X,Y;

    //est
    X = x; Y = y-1;
    //printf("\t%d %d\n",X,Y);
    if(checkPos(X,Y) && d[X][Y] + mat[x][y] == d[x][y])
    {
        ord.push_back('E');
        drum(X,Y);
    }

    //nord
    X = x+1; Y = y;
    //printf("\t%d %d\n",X,Y);
    if(checkPos(X,Y) && d[X][Y] + mat[x][y] == d[x][y])
    {
        ord.push_back('N');
        drum(X,Y);
    }

    //sud
    X = x-1; Y = y;
    //printf("\t%d %d\n",X,Y);
    if(checkPos(X,Y) && d[X][Y] + mat[x][y] == d[x][y])
    {
        ord.push_back('S');
        drum(X,Y);
    }
}

int main()
{
    fscanf(f1,"%d%d",&n,&m);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            fscanf(f1,"%d",&mat[i][j]);

            if(j)
                d[i][j] = inf;
            else
            {
                d[i][j] = mat[i][j];
                v[i].i = i;
                v[i].x = mat[i][j];
            }
        }

    for(i=0;i<n;i++)
        dfs(i,0);

    int min = 0;
    for(i=1;i<n;i++)
        if(d[i][m-1] < d[min][m-1])
            min = i;

    drum(min, m-1);

    fprintf(f2,"%d\n%d ",d[min][m-1],start+1);
    for(i=ord.size()-1;i>=0;i--)
        fprintf(f2,"%c",ord[i]);

    return 0;
}

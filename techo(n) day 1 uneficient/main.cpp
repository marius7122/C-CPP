#include <stdio.h>
#include <vector>
using namespace std;

struct muchie
{
    int x,y;
};

FILE *f1 = fopen("in.txt","r");
FILE *f2 = fopen("out.txt","w");

const int N = 4005;
const int M = 1000005;

int n,m,i;
bool g[N][N];
vector<muchie> muchiiAdaugate;

void citeste()
{
    fscanf(f1,"%d%d",&n,&m);

    int i,x,y;
    for(i=0;i<m;i++)
    {
        fscanf(f1,"%d%d",&x,&y);
        g[x][y] = g[y][x] = true;
    }
}

int main()
{
    citeste();

    if(n <= 3 && (n*(n-1))/2 == m)
    {
        for(i=n+1;i<=5;i++)
        {
            int x,y;
            x = i;
            y = i-n;
            g[x][y] = g[y][x] = true;

            muchiiAdaugate.push_back({x,y});
        }

        fprintf(f2,"%d %d\n",5-n, muchiiAdaugate.size());

        for(i=0;i<muchiiAdaugate.size();i++)
            fprintf(f2,"%d %d\n",muchiiAdaugate[i].x, muchiiAdaugate[i].y);

        for(i=n+1;i<=5;i++)
            fprintf(f2,"%d\n",i);
        for(i=n;i;i--)
            fprintf(f2,"%d\n",i);
    }

    return 0;
}

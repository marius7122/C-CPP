#include <stdio.h>
#include <queue>
#include <vector>

#define N 50005
#define inf 1000000005

using namespace std;

struct arc
{
    int x,cost;
}aux;

queue<int> coada;
vector<arc> g[N];

int n,m,x,i,nod,y,dist;
int d[N],viz[N];

bool incoada[N];
 
 
void afisG()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        printf("%d: ",i);
        for(j=0;j<g[i].size();j++)
            printf("%d-%d ",g[i][j].x,g[i][j].cost);
        printf("\n");
    }
}
int main()
{
    FILE *f1,*f2;
    f1=fopen("bellmanford.in","rs");
    f2=fopen("bellmanford.out","w");
 
    fscanf(f1,"%d%d",&n,&m);
    for(i=0;i<m;i++)
    {
        fscanf(f1,"%d%d%d",&x,&aux.x,&aux.cost);
        g[x].push_back(aux);
    }
 
    for(i=2;i<=n;i++)
        d[i]=inf;
 
 
    coada.push(1);
    incoada[1]=true;
    d[1]=0;
 
    while(!coada.empty())
    {
        nod=coada.front();
        coada.pop();
        incoada[nod]=false;
 
        if(viz[nod]==n)
        {
            fprintf(f2,"Ciclu negativ!");
            return 0;
        }
 
 
        for(int i=0;i<g[nod].size();i++)
        {
            y=g[nod][i].x;
            dist=g[nod][i].cost;
 
            if(d[y]>d[nod]+dist)
            {
                viz[y]++;
                d[y]=d[nod]+dist;
                if(!incoada[y])
                {
                    coada.push(y);
                    incoada[y]=true;
                }
            }
        }
    }
 
    for(i=2;i<=n;i++)
        fprintf(f2,"%d ",d[i]);
 
    return 0;
}
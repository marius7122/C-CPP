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

FILE* f1=fopen("dijkstra.in","r");
FILE* f2=fopen("dijkstra.out","w");

const int buff_size = 100000;
char buff[buff_size];
int buff_poz;
inline void read(int &x)
{
    if(buff[0] == 0)
        fread(buff, 1, buff_size, f1);

    while(buff[buff_poz]<'0' || buff[buff_poz]>'9')
        if(++buff_poz == buff_size)
        {
            fread(buff, 1, buff_size, f1);
            buff_poz = 0;
        }

    x = 0;
    while(buff[buff_poz]>='0' && buff[buff_poz]<='9')
    {
        x = x*10 + buff[buff_poz] - '0';

        if(++buff_poz == buff_size)
        {
            fread(buff, 1, buff_size, f1);
            buff_poz = 0;
        }
    }
}

queue<int> coada;
vector<arc> g[N];
int n,m,x,i,nod,y,dist;
int d[N];
bool incoada[N];


int main()
{
    read(n);read(m);

    for(i=0;i<m;i++)
    {
        read(x);read(aux.x);read(aux.cost);

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

        //printf("%d ",nod);

        for(int i=0;i<g[nod].size();i++)
        {
            y=g[nod][i].x;
            dist=g[nod][i].cost;

            if(d[y]>d[nod]+dist)
            {
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
        if(d[i]!=inf)
            fprintf(f2,"%d ",d[i]);
        else
            fprintf(f2,"0 ");

    return 0;
}

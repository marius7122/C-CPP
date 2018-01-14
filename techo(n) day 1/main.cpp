#include <stdio.h>
#include <vector>

struct muchie
{
    int x,y;
};

using namespace std;

FILE *f1 = fopen("in.txt","r");
FILE *f2 = fopen("out.txt","w");

const int N = 2005;
const int M = 1000005;

vector<muchie> muchiiAdaugate;
vector<int> aux[N];
int comp[N];

bool g[N][N];
int n,m,totalMuchii, noduriAdaugate;
int valNoi[N];

void citeste();
void conex();
void dfs(int,int);
void adaugaNoduri();
int main()
{
    citeste();
    conex();
    adaugaNoduri();


    return 0;
}

void citeste()
{
    fscanf(f1,"%d%d",&n,&m);
    totalMuchii = m;

    int i,x,y;
    for(i=0;i<m;i++)
    {
        fscanf(f1,"%d%d",&x,&y);
        g[x][y] = g[y][x] = true;
    }
}

///face graful conex
void conex()
{
    int i;
    vector<int> c;

    for(i=1;i<=n;i++)
        if(!comp[i])
        {
            dfs(i, i);
            c.push_back(i);
        }

    for(i=1;i<c.size();i++)
    {
        //fac legatura intre doua componente conexe

        muchiiAdaugate.push_back({c[i-1],c[i]});

        g[c[i-1]][c[i]] = g[c[i]][c[i-1]] = true;

        totalMuchii++;
    }
}

void dfs(int nod, int c)
{
    comp[nod] = c;
    for(int i=1;i<=n;i++)
        if(g[nod][i] && !comp[i])
            dfs(i, c);
}

void adaugaNoduri()
{
    int pos = n * (n-1) / 2;
    noduriAdaugate = 0;

    while(pos / 2 < totalMuchii)
    {
        totalMuchii++;
        pos += n;
        n++;
        noduriAdaugate++;

        aux[noduriAdaugate].push_back(n);
        aux[n].push_back(noduriAdaugate);
    }
}

void creeazaGrafNou()
{

}


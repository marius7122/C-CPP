#include <stdio.h>
#include <vector>
 
FILE *f1 = fopen("lca.in","r");
FILE *f2 = fopen("lca.out","w");
 
const int buff_size = 10000;
 
int buff_poz;
char buff[buff_size];
 
inline void citeste(int &x)
{
    x=0;
 
    while(buff[buff_poz] < '0' || buff[buff_poz] > '9')
        if(++buff_poz == buff_size || buff[buff_poz] == 0)
        {
            fread(buff,1,buff_size,f1);
            buff_poz = 0;
        }
 
 
 
    while(buff[buff_poz] >= '0' && buff[buff_poz] <= '9')
    {
        x = x*10 + buff[buff_poz] - '0';
 
        if(++buff_poz == buff_size || buff[buff_poz] == 0)
        {
            fread(buff,1,buff_size,f1);
            buff_poz = 0;
        }
    }
}
 
 
const int N = 100005;
const int LOG = 17;
 
int n,q,i,j,x,y,p;
int euler[2*N],rmq[LOG][2*N],lvl[N],prim[N],ultim[N],log[N];
 
std::vector<int> g[N];
 
inline int getmax(int a,int b)
{
    if(lvl[a]>lvl[b])
        return a;
    return b;
}
inline int getmin(int a,int b)
{
    if(lvl[a]<lvl[b])
        return a;
    return b;
}
void dfs(int x,int ant,int l)
{
    int i,S,y;
 
    euler[++p] = x;
    prim[x] = ultim[x] = p;
 
    lvl[x] = l;
 
    S=g[x].size();
 
    for(i=0;i<S;i++)
    {
        y = g[x][i];
 
        if(y != ant)
        {
            dfs(y,x,l+1);
 
            euler[++p] = x;
            ultim[x] = p;
        }
    }
}
 
void prep()
{
    dfs(1,0,0);
 
    for(i=2;i<=p;i++)
        log[i] = log[i/2] + 1;
 
    for(i=1;i<=p;i++)
        rmq[0][i] = euler[i];
 
    ///rmq se face dupa lvl[euler[i]]
 
    for(i=1;(1<<i) <= p;i++)
        for(j=1;j<=p;j++)
        {
            rmq[i][j] = getmin(rmq[i-1][j] , rmq[i-1][j + (1<<(i-1))]);
        }
}
 
int query()
{
 
    x = prim[x];
    y = prim[y];
 
    if(x > y)
    {
        int aux = x;
        x = y;
        y = aux;
    }
 
    int lg = log[y-x+1];
    int dif = y - (1<<lg) + 1;
 
    return getmin(rmq[lg][x] , rmq[lg][dif]);
}
 
int main()
{
    citeste(n);
    citeste(q);
 
 
    for(i=2;i<=n;i++)
    {
        citeste(x);
 
        g[x].push_back(i);
        g[i].push_back(x);
    }
 
    prep();
 
 
    while(q--)
    {
        citeste(x);
        citeste(y);
 
 
        fprintf(f2,"%d\n",query());
    }
 
 
    return 0;
}
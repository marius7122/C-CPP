#include <stdio.h>
#include <vector>

FILE *f1 = fopen("fantasy.in","r");
FILE *f2 = fopen("fantasy.out","w");

const int N = 1005;

int t,n,d,c,v,i,x,y;
int D[N],C[N],V[N];
std::vector<int> g[N];

void dfs(int nod,int dist,int v[N])
{
    v[nod] = dist;

    int i,l,y;

    for(i=0, l=g[nod].size(); i<l; i++)
    {
        y = g[nod][i];

        if(v[y] > dist + 1)
            dfs(y,dist+1,v);
    }
}

int main()
{
    fscanf(f1,"%d",&t);

    while(t--)
    {
        //citire
        fscanf(f1,"%d%d%d%d",&n,&d,&c,&v);
        for(i=1;i<n;i++)
        {
            fscanf(f1,"%d%d",&x,&y);

            g[x].push_back(y);
            g[y].push_back(x);
        }

        for(i=1;i<=n;i++)
            D[i] = C[i] = V[i] = N;

        dfs(d,0,D);
        dfs(c,0,C);
        dfs(v,0,V);

        bool sol = false;

        for(i=1;i<=n && !sol;i++)
            if(V[i] == C[i]-1 && C[i] == D[i])
                for(int j=0;j<g[i].size() && !sol;j++)
                {
                    int y = g[i][j];

                    if(V[y] < C[y] && C[y] <= D[y])
                        sol = true;
                }
            else if(V[i] < C[i] && C[i] < D[i])
                sol = true;
            else if(V[i] < C[i]+1 && C[i] <= D[i])
                sol = true;

        if(sol)
            fprintf(f2,"DA\n");
        else
            fprintf(f2,"NU\n");

        //golire graf
        for(i=1;i<=n;i++)
            g[i].erase(g[i].begin(), g[i].end());

    }

    return 0;
}

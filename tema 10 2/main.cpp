#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

const int N = 101;

vector<int> g[N];
int n,m,i,x,y;
bool viz[N];

void dfs(int nod)
{
    viz[nod] = true;

    printf("%d ",nod);

    for(int i=0;i<g[nod].size();i++)
        if(!viz[g[nod][i]])
            dfs(g[nod][i]);
}

void bfs(int nod)
{
    queue<int> q;
    q.push(nod);
    viz[nod] = true;

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        printf("%d ",x);

        for(int i=0;i<g[x].size();i++)
        {
            int y = g[x][i];
            if(!viz[y])
            {
                q.push(y);
                viz[y] = true;
            }
        }
    }
}

int main()
{
    FILE *f1 = fopen("graf.txt","r");

    fscanf(f1,"%d%d",&n,&m);

    for(i=0;i<m;i++)
    {
        fscanf(f1,"%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int comp = 0;
    for(i=1;i<=n;i++)
        if(!viz[i])
        {
            printf("componenta conexa %d este: ",++comp);
            dfs(i);
            printf("\n");
        }



    return 0;
}

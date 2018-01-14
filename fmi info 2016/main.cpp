#include <stdio.h>

using namespace std;

struct nod
{
    int inf;
    nod *urm;
};

int n,m,p,i,x,y;
int l[100];
nod *g[100];
bool sters[100];



void sterge(int x)
{
    sters[x] = true;

    nod *i;

    i = g[x];

    int y;

    while(i != NULL)
    {
        y = i->inf;

        l[y]--;

        if(l[y] < p && !sters[y])
            sterge(y);

        i = i->urm;
    }

}

void add(int x,int y)   ///adauga muchia x-y
{
    nod *aux = new nod;

    aux->inf = y;
    aux->urm = g[x];

    g[x] = aux;
}

int main()
{
    scanf("%d%d%d",&n,&m,&p);

    for(i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);

        l[x] ++;
        l[y] ++;

        add(x,y);
        add(y,x);
    }


    for(i=1;i<=n;i++)
        if(l[i] < p)
            sterge(i);

    printf("\n");


    int cnt = 0;
    for(i=1;i<=n;i++)
        if(!sters[i])
        {
            printf("%d ",i);
            cnt++;
        }

    if(cnt == 0)
        printf("NU");



    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

const int N = 101;

bool g[N][N], n;

int grad(int nod)
{
    int s = 0;

    for(int i=1;i<=n;i++)
        s += g[nod][i];

    return s;
}

int numarMuchii()
{
    int nr = 0;
    int i,j;

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            nr += g[i][j];

    nr /= 2;
    return nr;
}

void afisGradMax()
{
    int G[N], max = 0;

    for(int i=1;i<=n;i++)
    {
        G[i] = grad(i);

        if(G[i] > max)
            max = G[i];
    }

    for(int i=1;i<=n;i++)
        if(G[i] == max)
            cout << i << ' ';
}

int main()
{

    return 0;
}

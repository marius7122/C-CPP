#include <stdio.h>

const int N = 1000;

int n,i;
int v[N];

void down(int nod)
{
    int l = nod << 1;
    int r = l + 1;

    int min = nod;

    if(l <= n && v[l] < v[min])
        min = l;
    if(r <= n && v[r] < v[min])
        min = r;

    if(min != nod)
    {
        int aux = v[min];
        v[min] = v[nod];
        v[nod] = aux;

        down(min);
    }
}

void buildHeap()
{
    int i;
    for(i=n/2;i;i--)
        down(i);
}

//returneaza nodul din varf
int decapiteaza()
{
    int vf = v[1];

    v[1] = v[n];
    n--;
    down(1);

    return vf;
}

void heapSort()
{
    buildHeap();
    for(i=n;i;i--)
        printf("%d ",decapiteaza());
}

int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&v[i]);

    heapSort();

    return 0;
}

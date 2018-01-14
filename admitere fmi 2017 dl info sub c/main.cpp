#include <stdio.h>

void FLIP(int n,int v[100],int i,int j)
{
    int aux;
    while(i<j)
    {
        aux = v[i];
        v[i] = v[j];
        v[j] = aux;

        i++;
        j--;
    }
}

int p2[20];
int v[100],n,i,j;

void divImpSort(int v[100],int p,int inc)
{
    int sf = inc + p2[p] - 1;

    //printf("%d %d\n",p,inc);

    //nu sunt in ordine
    if(v[inc] > v[sf])
        FLIP(n,v,inc,sf);

    //avem mai mult de 2 elemente
    if(p>1)
    {
        int mid = (inc + sf) / 2;

        divImpSort(v,p-1,inc);  //partea stanga
        divImpSort(v,p-1,mid+1);  //partea dreapta
    }
}

int main()
{
    //citeste
    printf("n = ");scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("v[%d] = ",i);
        scanf("%d",&v[i]);
    }

    //calculeaza puterile lui 2
    p2[0] = 1;
    i = 0;
    while(p2[i] < n)
        p2[++i] = p2[i-1] * 2;

    //sorteaza
    divImpSort(v,i,1);

    //afisaza
    printf("v = [");
    for(i=1;i<=n;i++)
        printf("%d ",v[i]);
    printf("]");

    return 0;
}

#include <stdio.h>

FILE *f1 = fopen("vila2.in","r");
FILE *f2 = fopen("vila2.out","w");

const int N = 100005;

int n,r,i,prim1,ultim1,prim2,ultim2,maxDif;
int v[N],max[N], min[N];

int main()
{
    fscanf(f1,"%d%d",&n,&r);
    r++;

    for(i=0;i<n;i++)
    {
        fscanf(f1,"%d",&v[i]);

        if(i - max[prim1] >= r)
            prim1++;
        if(i - min[prim2] >= r)
            prim2++;

        while(prim1 <= ultim1 && v[i] >= v[max[ultim1]])
            ultim1--;
        max[++ultim1] = i;

        while(prim2 <= ultim2 && v[i] <= v[min[ultim2]])
            ultim2--;
        min[++ultim2] = i;

        if(v[max[prim1]] - v[min[prim2]] > maxDif)
            maxDif = v[max[prim1]] - v[min[prim2]];
    }

    fprintf(f2,"%d",maxDif);

    return 0;
}

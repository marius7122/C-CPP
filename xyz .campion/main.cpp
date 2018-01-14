#include <stdio.h>

FILE *f1 = fopen("xyz.in","r");
FILE *f2 = fopen("xyz.out","w");

int x,y,z;
int sol,i;

int main()
{
    fscanf("%d%d%d",&x,&y,&z);

    sol = sol * 10 + y;

    for(i=1;i<x;i++)
        sol = sol * 10 + z;

    fprintf("%d",sol);

    return 0;
}

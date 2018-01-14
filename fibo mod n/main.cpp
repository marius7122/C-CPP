#include <stdio.h>

const int mod = 15315;

int a,b,c;

void getNextFibo()
{
    a = (b + c) % mod;
    c = b;
    b = a;
}


int findUpperLimit()
{
    int i = 3;
    b = c = 1;
    getNextFibo();
    while(c!=1 || b!=1)
    {
        getNextFibo();
        i++;
    }
    return i;
}

int fiboEl(int el)
{
    b = c = 1;
    if(el<=2)
    {
        //printf("%d-1\n",el);
        return 1;
    }

    for(int i=2;i<el;i++)
    {
        getNextFibo();
    }
    //printf("%d - %d\n",el,a);
    return a;
}

int main()
{
    b = c = 1;

    printf("%d\n",findUpperLimit());

    int x = findUpperLimit()-1;

    fiboEl(x);
    fiboEl(x+1);
    fiboEl(x+2);
    fiboEl(x+3);

    printf("%d %d\n",x-1);

    for(int i=1;i<50000;i++)
    {
        if(i % (x-1) != 0)
            if(fiboEl(i) != fiboEl(i%(x-1)))
                printf("\n\nERROR %d %d\n\n",i,i%(x-1));
    }

    return 0;
}

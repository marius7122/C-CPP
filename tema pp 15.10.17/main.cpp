#include <stdio.h>
#include <math.h>

#define abs(x) x<0?-x:x

int a,b,c,d;

///compara a^b cu c^d, a,b,c,d naturale
int cmpNat(int a,int b,int c,int d)
{
    double x1 = b * log10((double)a);
    double x2 = d * log10((double)c);

    if(x1 > x2)
        return 1;
    if(x1 < x2)
        return -1;
    return 0;
}

int cmpInt(int a,int b,int c,int d)
{
    if(a>0 && b>0 && c>0 && d>0)
        return cmpNat(a,b,c,d);

    if(a>0 && c>0)
    {
        if(b<0 && d<0)
            return -cmpNat(a,-b,c,-d);
        if(d<0)
            return 1;
        if(b<0)
            return -1;
    }

    if(a<0 && c<0)
    {
        if(b%2==0 && d%2==1)
            return 1;
        if(d%2==0 && b%2==1)
            return -1;
        if(d%2==1 && b%2==1)
            return -cmpNat(-a,b,-c,d);
        if(d%2==0 && b%2==0)
            return cmpNat(-a,b,-c,d);
    }

    if(a<0)
    {
        if(b%2==0)
            return cmpNat(-a,b,c,d);
    }

}

int main()
{

    return 0;
}

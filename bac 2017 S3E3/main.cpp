#include <stdio.h>

///subprogramul cerut
void subprogram(unsigned long &n)
{
    unsigned long p,sol;

    p = 1;sol = 0;

    while(n)
    {
        if(n%2 == 0)
        {
            sol += n%10/2 * p;
            p*=10;
        }

        sol += n%10 * p;

        n /= 10;p *= 10;
    }

    n = sol;
}

int main()
{

    unsigned long x = 2380;

    subprogram(x);

    printf("%u",x);

    return 0;
}

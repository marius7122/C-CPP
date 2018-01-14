#include <stdio.h>

long long n,k,rez[5];

int main()
{
    scanf("%lld%lld",&n,&k);

    rez[1] = 1;
    rez[2] = 1 + n * (n-1) / 2;
    rez[3] = rez[2] + n * (n-1) * (n-2) / 3;
    rez[4] = rez[3] + n * (n-1) * (n-2) * (n-3) / 8 * 3;

    printf("%lld",rez[k]);

    return 0;
}

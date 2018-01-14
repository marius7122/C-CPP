#include <stdio.h>
#include <stdarg.h>

void afis(int n, ...)
{
    int i;

    va_list arg;
    va_start(arg, n);

    for(i=0;i<n;i++)
    {
        printf("%d ",va_arg(arg, int));
    }
    va_end(arg);
}


int main()
{
    afis(6, 1,2,3,4,5);
    return 0;
}

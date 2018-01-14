#include <stdio.h>

void foo(int x)
{
    printf("%d\n",x);
}

int main()
{
    int x = 97;
    foo(x++);
    printf("%d",x);

    return 0;
}

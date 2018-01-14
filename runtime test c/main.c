#include <stdio.h>

int num_of_loops = 100000000;
int a,b,c;

int main()
{
    a = 3;
    b = 5;
    c = 0;

    int i;
    for(i = 0;i<num_of_loops;i++)
        c = a + b;

    return 0;
}

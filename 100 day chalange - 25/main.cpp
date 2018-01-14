///CEL MAI MIC NUMAR FORMAT NUMAI DIN 0 SI 1 CARE ESTE DIVIZIBIL CU 42
#include <stdio.h>

inline bool check(int x)
{
    while(x)
    {
        if(x%10 > 1)
            return false;

        x /= 10;
    }

    return true;
}

int main()
{

    int i;
    for(i=42;!check(i);i+=42);

    printf("%d",i);

    return 0;
}

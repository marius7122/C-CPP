#include <stdio.h>
#define LL long long

FILE *f1 = fopen("fences.in","r");
FILE *f2 = fopen("fences.out","w");

LL L,R,U,D,sol;
int t;

char c;

inline LL min(LL a,LL b)
{
    if(a<b)
        return a;
    return b;
}

int main()
{
    fscanf(f1,"%d\n",&t);

    while(t--)
    {
        U = D = L = R = 0;

        while(c!='L' && c!='R' && c!='U' && c!='D')
            fscanf(f1,"%c",&c);

        do
        {
            if(c == 'L') L++;
            else if(c == 'R') R++;
            else if(c == 'U') U++;
            else if(c == 'D') D++;
            else break;

            fscanf(f1,"%c",&c);

        }while(!feof(f1));

        sol = min(L,R) * min(U,D);

        fprintf(f2,"%lld\n",sol) ;
    }

    return 0;
}

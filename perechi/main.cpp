#include <stdio.h>

FILE *f1 = fopen("perechi.in","r");
FILE *f2 = fopen("perechi.out","w");


int cmmdc(int a,int b)
{
    while(a != b)
        if(a > b)
            a -= b;
        else
            b -= a;

    return a;
}
int cmmmc(int a,int b)
{
    return a*b/cmmdc(a,b);
}
int ap[1005];
void brute(int n)
{
    int i,j,q=0;

    for(i=1;i<=n;i++)
        if(n%i == 0)
            printf("%d %d\n",i,n),
            q++,
            ap[i]++,
            ap[n]++;

    printf("    %d\n",q);

    for(i=1;i<n;i++)
        for(j=i+1;j<n;j++)
            if(cmmmc(i,j) == n)
                printf("%d %d\n",i,j),
                q++,
                ap[i]++,ap[j]++;

    printf("%d\n",q);

    for(i=1;i<=n;i++)
        if(ap[i])
            printf("%d - %d\n",i,ap[i]);
}

int main()
{
    int x;
    scanf("%d",&x);
    brute(x);
    return 0;
}

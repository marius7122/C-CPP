#include <stdio.h>

FILE *f1 = fopen("trompeta.in","r");
FILE *f2 = fopen("trompeta.out","w");

const int N = 1000005;

char s[N],st[N];
int i,n,m,l;

int main()
{
    fscanf(f1,"%d%d\n",&n,&m);
    fscanf(f1,"%s",&s);

    l=1;

    for(i=0;i<n;i++)
    {
        while(l!=0 && st[l]<s[i] && n-i>m-l)
            l--;

        if(l < m)
            st[++l] = s[i];
    }

    fprintf(f2,"%s",st+1);

    return 0;
}

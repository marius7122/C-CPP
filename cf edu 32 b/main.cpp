#include <stdio.h>

int n,i,cnt[4];
char c;

int min(int a,int b)
{
    if(a < b)
        return a;
    return b;
}

int main()
{
    scanf("%d",&n);
    scanf("%c",&c);

    for(i=0;i<n;i++)
    {
        scanf("%c",&c);

        if(c == 'U')
            cnt[0] ++;
        if(c == 'D')
            cnt[1] ++;
        if(c == 'L')
            cnt[2] ++;
        if(c == 'R')
            cnt[3] ++;
    }

    printf("%d\n",2 * min(cnt[0],cnt[1]) + 2 * min(cnt[2],cnt[3]));

    return 0;
}

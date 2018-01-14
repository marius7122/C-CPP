#include <stdio.h>

FILE *f1 = fopen("parantezare.in","r");
FILE *f2 = fopen("parantezare.out","w");

const int L = 100005;

int i,n,m,q;
char s[L];
int inchisa[L];
int st[L/2];

int main()
{
    fscanf(f1,"%s",s);

    for(i=0; s[i] != 0; i++)
        if(s[i] == '(')
            st[++st[0]] = i;
        else if(s[i] == ')')
        {
            inchisa[st[st[0]]] = i;
            st[0]--;
        }

    fscanf(f1,"%d",&m);

    while(m--)
    {
        fscanf(f1,"%d",&q);
        fprintf(f2,"%d ",inchisa[q]);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

const int N = 100005;

int n,i,j,nr;
int lastAp[30], firstAp[30], nextAp[N];
char s[N];

int max(int a,int b)
{
    if(a > b)
        return a;
    return b;
}

int main()
{
    scanf("%s",s);

    i = 0;
    while(s[i] != '\0' && s[i] != '\n')
    {
        nr = s[i] - 'a';


        ///first aparition
        if(!lastAp[nr])
        {
            lastAp[nr] = i + 1;
            firstAp[nr] = i + 1;
        }
        else
        {
            nextAp[lastAp[nr] - 1] = i;
            lastAp[nr] = i + 1;
        }

        i++;
    }

    n = i;

    int bst = n;
    int aux;

    for(i='a';i<='z';i++)
    {
        nr = i - 'a';

        if(firstAp[nr])
        {
            aux = firstAp[nr];
            j = firstAp[nr] - 1;

            while(nextAp[j])
                aux = max(aux, nextAp[j] - j),
                j = nextAp[j];

            aux = max(aux, n - j);

            if(aux < bst)
                bst = aux;
        }
    }

    printf("%d",bst);

    return 0;
}

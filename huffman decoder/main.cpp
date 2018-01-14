#include <stdio.h>
#include <string.h>
using namespace std;

FILE *f1 = fopen("code.txt","r");

int n,i,l;

char code[100][100];
char simbols[100];
char mesage[1000];
char act[100];

bool egal(char *x, char *y)
{
    int i = 0;

    //printf("%s %s\n",x,y);

    if(strlen(x) != strlen(y))
        return false;

    do
    {
        if(x[i] != y[i])
            return false;
        i++;
    }while(x[i] && y[i]);

    if(x[i] != y[i])
        return false;

    printf("%s %s\n",x,y);

    return true;
}
int exist(char *c)
{
    int q;
    for(int i=0;i<n;i++)
        if(q = egal(c, code[i]))
        {
            return (int)simbols[i];
        }
    return -1;
}

int main()
{
    fscanf(f1,"%d\n",&n);
    for(i=0;i<n;i++)
    {
        fscanf(f1,"%c %s\n",&simbols[i], code[i]);
        //printf("%c %s\n",simbols[i], code[i]);
    }

    printf("codare: ");
    scanf("%s",mesage);

    for(i=0;i<strlen(mesage); i++)
    {
        //printf("%d ",i);
        act[l++] = mesage[i];

        int rez = exist(act);

        if(rez != -1)
        {
            printf("%c",rez);
            act[0] = '\0';
            l = 0;
        }
    }



    return 0;
}

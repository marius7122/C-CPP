#include <stdio.h>
#include <string.h>

void afisCoada(char c[],int nr)
{
    int i;

    printf("    -----------------------------------------\n");
    printf("C%d=|",nr);
    for(i=c[0]+1;i<=c[1];i++)
        printf("%c ",c[i]);
    printf("\n    -----------------------------------------\n\n");
}

void afisStiva(char s[])
{
    int i;

    for(i=s[0];i>0;i--)
        printf("    | %c |\n",s[i]);

    printf("     --- \n");
    printf("      S\n\n");
}

void breakLN()
{
    printf("______________________________________________\n\n");
}

void deseneazaPas(int pas,char c1[],char c2[],char s[],char mesaj[])
{
    printf("PASUL %d\n\n",pas);

    printf("%s\n\n",mesaj);

    afisCoada(c1,1);
    afisCoada(c2,2);
    afisStiva(s);

    breakLN();
}

const int N = 100;

char toDo[1000];
char c1[N],c2[N],s[N];
int i,pas = 1;

FILE *fp = freopen("rezolvare.txt", "w", stdout);

int main()
{
    fgets(toDo, sizeof(toDo), stdin);
    printf("\n");

    ///c1[0] - left ; c2[1] - right ...
    c1[0] = c1[1] = c2[0] = c2[1] = 1;

    while(i < strlen(toDo))
    {
        if(toDo[i] == '1')
        {
            if(c1[0]!=c1[1])
            {
                c2[++c2[1]] = c1[c1[1]];
                c1[1]--;
                deseneazaPas(pas,c1,c2,s,"Executat operatie 1");
            }
            else
                deseneazaPas(pas,c1,c2,s,"COADA C1 este VIDA!");
        }
        else if(toDo[i] == '2')
        {
            if(c2[0]!=c2[1])
            {
                s[++s[0]] = c2[c2[1]];
                c2[1]--;
                deseneazaPas(pas,c1,c2,s,"Executat operatie 2");
            }
            else
                deseneazaPas(pas,c1,c2,s,"COADA C2 ESTE VIDA!");
        }
        else if(toDo[i]>='A' && toDo[i]<='Z')
        {
            c1[++c1[1]] = toDo[i];
            deseneazaPas(pas,c1,c2,s,"Adaugat element in coada C1");
        }
        else
        {
            i++;
            continue;
        }

        pas++;
        i++;
    }

    return 0;
}

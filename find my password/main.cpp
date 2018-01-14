#include <stdio.h>
#include <string.h>


FILE *f1 = fopen("cuvinte.txt","r");
FILE *f2 = fopen("posibilitati.txt","w");

const int nr_cuv = 80000;

int l,q,i;
char cuv[101];


///cauta pe c in cuv
inline bool gasit(char c)
{
    for(int i=1;i<l;i++)
        if(cuv[i] == c)
            return true;

    return false;
}

inline bool cond()
{
            ///lungimea
    if(l<6 || l>8)
        return false;

            ///incepe cu ...
    //if(cuv[1] != 'S' && cuv[1] != 'A' && cuv[1] != 'C')
    //    return false;

    if(cuv[1] != 'S')
        return false;

    //if(cuv[2] != 'C')
    //    return false;

    //if(cuv[3] != 'N')
    //    return false;


            ///se termina cu ...
    //if(cuv[l-1] != 'R' || cuv[l-2] != 'A')
    //    return false;

            ///contine ...
    if(!gasit('R'))
        return false;

    //if(!gasit('E'))
    //    return false;

    //if(!gasit('C'))
    //    return false;

    return true;
}

int main()
{
    while(++q < nr_cuv)
    {
        fscanf(f1,"%s\n",cuv);

        l = strlen(cuv);

        if(cond() == true)
            printf("%s\n",cuv+1),
            fprintf(f2,"%s\n",cuv+1);
    }


    return 0;
}

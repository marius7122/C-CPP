#include <stdio.h>
#include <fstream>
#include <iostream>

using namespace std;

FILE *f = fopen("bac.txt","r");

unsigned n,i,ant,act,afisari;

int main()
{
    ifstream fCpp("bac.txt");

    while(!fCpp.eof())
    {
        int x;

        fCpp>>x;

        cout<<x<<' ';
    }

/*
    fscanf(f,"%d%d",&n,&act);

    //afisam elementele de la 1 la primul element
    for(i=1;i<act;i++)
    {
        printf("%d ",i);
        afisari ++;
    }

    do
    {
        ant = act;  //elementul actual devine anterior

        fscanf(f,"%d",&act);

        //afisam numerele din intervalul (ant,act)
        for(i=ant+1;i<act;i++)
        {
            printf("%d ",i);
            afisari ++;
        }


    }while(!feof(f));   //citim pana cand nu mai sunt numere in fisier

    //afisam elementele de la ultimul numar citit pana la n
    for(i=act+1;i<=n;i++)
    {
        printf("%d ",i);
        afisari ++;
    }

    if(afisari == 0)
        printf("Nu exista!");

    fclose(f);*/
    return 0;
}

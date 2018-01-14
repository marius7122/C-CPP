#include <stdio.h>

void citesteTotFisierul()
{
    ///deschide fisier
    FILE *f = fopen("numere.txt","r");


    int x;
    while(~fscanf(f,"%d",&x))  ///conditie sucara
        printf("%d ",x);

}

void printSucces()
{
    printf("%m");

    ///se pare ca nu merge...
}

void forSmen()
{

    int i = 0;

    while(i ++> 0)
        printf("%d ",i);


}

int main()
{
    forSmen();

    return 0;
}

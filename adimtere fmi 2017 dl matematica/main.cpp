#include <stdio.h>
#include <math.h>

//pentru localizare intr-o matrice
struct punct
{
    int lin,col;
};

//afla unde se gaseste x in matrice
punct aflaPos(unsigned x)
{
    punct sol;
    unsigned x1 = x - 1;

    //linia se obtine din rezolvarea ecuatiei (lin*(lin-1))/2 = x - 1
    sol.lin = (unsigned)((1 + sqrt(1 + 8 * x1))/2);

    //coloana se obtine din ecuatia x - ultimul element de pe linia lin-1
    sol.col = x - (sol.lin * (sol.lin - 1))/2;

    return sol;
}

//afla ce numar este x in functie de unde se afla in matrice
unsigned aflaX(punct pos)
{
    unsigned x;

    //ultimul element de pe linia pos.lin - 1
    x = (pos.lin * (pos.lin - 1))/2;

    x += pos.col;

    return x;
}

//afisaza drumul minim recursiv
void drum(punct pos, punct target)
{
    //afisaza unde suntem
    printf("%d ",aflaX(pos));

    //am ajuns in y
    if(pos.lin == target.lin && pos.col == target.col)
        return;

    //nu sunt pe aceiasi linie
    if(pos.lin != target.lin)
    {
        //sunt mai jos
        if(pos.lin > target.lin)
            pos.lin --;
        //sunt mai sus
        else
            pos.lin ++;

        //sunt mai in dreapta
        if(pos.col > target.col)
            pos.col --;
        //sunt mai in stanga
        else
            pos.col ++;
    }

    //sunt pe aceiasi linie
    if(pos.lin == target.lin)
    {
        //sunt mai in dreapta
        if(pos.col > target.col)
            pos.col --;
        //sunt mai in stanga
        else
            pos.col ++;
    }

    drum(pos,target);
}

unsigned x,y;
punct pos,target;

int main()
{
    printf("x = ");scanf("%u",&x);
    printf("y = ");scanf("%u",&y);

    pos = aflaPos(x);
    target = aflaPos(y);


    printf("Drumul minim de la %u la %u este : ",x,y);

    drum(pos,target);

    return 0;
}

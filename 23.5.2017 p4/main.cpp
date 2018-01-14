#include <iostream>

using namespace std;

int x,x_ant,q,corect;

///x = elementul actual
///x_ant = elementul anterior

int main()
{
    corect = 1; ///plecam de la presupunerea ca sirul este corect

    cout<<"x= ";cin>>x_ant;
    cout<<"x= ";cin>>x;
    ///facem 2 citiri ca sa putem sa deducem ratia

    q = x / x_ant;  ///ratia unei progresii aritmetice este impartirea a doua elemente consecutive

    ///cautam cat timp x nu e 0 si sirul este corect(daca am gasit un element care nu este in progresie inseamna ca tot sirul nu este in progresie)
    while(x!=0 && corect == 1)
    {
        cout<<"x= ";cin>>x;

        if(x != 0 && x_ant*q != x)  ///daca x este diferit de 0 si x nu este in progresie atunci nu mai avem progresie
            corect = 0;
    }

    if(corect == 1)
        cout<<"DA";

    else
        cout<<"NU";

    return 0;
}

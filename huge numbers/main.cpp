#include <stdio.h>

const int max_cif = 101;

inline char max(char a, char b)
{
    if(a > b)
        return a;
    return b;
}

class huge
{
    public:char cif[max_cif];

    private:void shiftRight(int dist)
    {
        printf("SHF:%d ",dist);

        cif[0] += dist;

        int i;

        for(i = cif[0]; i > dist; i--)
            cif[i] = cif[i-dist];

        for(i=1; i<=dist; i++)
            cif[i] = 0;
    }

    public:
    huge(char num[max_cif])
    {
        cif[0] = 0;
        while(num[cif[0]] != 0)
        {
            cif[cif[0] + 1] = num[cif[0]] - '0';
            cif[0]++;
        }

        for(int i = cif[0] + 1; i<max_cif; i++)
            cif[i] = 0;
    }

    void afis()
    {
        for(int i=1; i<=cif[0]; i++)
            printf("%d",cif[i]);
        printf("\n");
    }

    void add(int x)
    {
        char cifX[12];

        cifX[0] = 0;

        ///vad cate cifre are
        int cop = x;
        while(cop)
        {
            cop /= 10;
            cifX[0] ++;
        }

        ///creez un vector cu cifrele lui
        cop = cifX[0];
        while(cop)
        {
            cifX[cop--] = x%10;
            x /= 10;
        }

        ///adun la numarul din clasa pe x
        if(cifX[0] > cif[x])
        {
            shiftRight(cifX[0] - cif[0]);
        }

        ///afisez ce adun (se poate sterge)
        for(int i = 1; i<=cif[0]; i++)
            printf("%d",cif[i]);
        printf(" + ");
        for(int i = 1; i<=cifX[0]; i++)
            printf("%d",cifX[i]);
        printf(" = ");

        for(int i = cif[0]; i; i--)
        {
            cif[i] += cifX[i];

            if(cif[i] > 9)
            {
                ///daca trebuie sa adaugam un 1 in fata
                if(i == 1)
                {
                    shiftRight(1);
                    cif[1] = 1;
                    cif[2] -= 10;
                }

                else
                {
                    cif[i-1] ++;
                    cif[i] -= 10;
                }
            }
        }

        afis();
    }

    void addHuge(huge x)
    {
        if(x.cif[0] > cif[0])
            shiftRight(x.cif[0] - cif[0]);

        ///afisez ce adun (se poate sterge)
        for(int i = 1; i<=cif[0]; i++)
            printf("%d",cif[i]);
        printf(" + ");
        for(int i = 1; i<=x.cif[0]; i++)
            printf("%d",x.cif[i]);
        printf(" = ");

        for(int i = cif[0]; i; i--)
        {
            cif[i] += x.cif[i];

            if(cif[i] > 9)
            {
                if(i == 1)
                {
                    shiftRight(1);
                    cif[1] = 1;
                    cif[2] -= 10;
                }
                else
                {
                    cif[i-1] ++;
                    cif[i] -= 10;
                }
            }
        }

        afis();
    }


    ///to do: adauga inmultirea
};


int main()
{

    huge bigX = huge("123456789");
    huge bigY = huge("923456789");

    bigX.afis();
    bigY.afis();

    huge rez = huge("");

    rez.afis();

    rez.addHuge(bigX);
    rez.addHuge(bigY);
    rez.afis();
    printf("%d",rez.cif[0]);

    return 0;
}

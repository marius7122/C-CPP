#include <stdio.h>

FILE *f1 = fopen("input.txt","r");

///buff stuff
const int buffSize = 10000;
char buff[buffSize];
int buffPoz;
bool wasInitialized;

char getNextPosition()
{
    if(!wasInitialized)
    {
        fread(buff,1,buffSize,f1);
        wasInitialized = true;
    }


    if(++buffPoz == buffSize)
    {
        fread(buff,1,buffSize,f1);
        buffPoz = 0;
    }

    return buff[buffPoz];
}

void citesteIntreg(int &x)
{
    char c;

    ///cat timp nu e cifra
    while((c = getNextPosition()) < '0' || c > '9');

    x = 0;

    ///cat timp este cifra
    while(c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';

        c = getNextPosition();
    }
}

void citesteReal(float &x)
{
    char c;

    ///cat timp nu e cifra
    while((c = getNextPosition()) < '0' || c > '9');

    x = 0;

    ///citim partea intreaga
    while(c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';

        c = getNextPosition();
    }

    ///daca avem parte zecimala
    if(c == '.')
    {
        float fp = 0.1;

        c = getNextPosition();

        ///cat timp e cifra
        while(c >= '0' && c <= '9')
        {
            x = x + (c - '0') * fp;

            fp *= 0.1;

            c = getNextPosition();
        }
    }
}

int candidat,i;
float medie,mediaMea;

int maiMare,egal;

int main()
{
    printf("media mea = ");
    scanf("%f",&mediaMea);


    for(i=1;i <= 1014;i++)
    {
        citesteIntreg(candidat);
        citesteReal(medie);

        if(mediaMea < medie)
        {
            maiMare ++;
        }

        if(mediaMea == medie)
        {
            egal ++;
        }

        if(medie > 10)
            printf("%f ",medie);

    }

    printf(" Sunt %d cu medie mai mare \n Sunt %d cu medie egala\n",maiMare,egal);


    return 0;
}

#include <stdio.h>

FILE *f1 = fopen("img.bmp","rb");
FILE *f2 = fopen("mod.bmp","wb");

const int header = 54;

const int width = 800;
const int height = 600;

void increaseBrightness(int amount)
{
    int i,j,k;

    if(f1 == NULL)
    {
        printf("eroare la deschiderea fisierului de intrare!\n");
        return;
    }

    for(i=0;i<header;i++)
    {
        char aux;
        fread(&aux, 1, 1, f1);
        fwrite(&aux, 1, 1, f2);
    }

    unsigned char c;

    for(i=0;i<height;i++)
        for(j=0;j<width;j++)
            for(k=0;k<3;k++)
            {
                fread(&c, 1, 1, f1);

                if(c + amount > 255)
                    c = 255;
                else
                    c += amount;

                fwrite(&c,1,1,f2);
            }
}

void albNegru()
{
        int i,j,k;

    if(f1 == NULL)
    {
        printf("eroare la deschiderea fisierului de intrare!\n");
        return;
    }

    for(i=0;i<header;i++)
    {
        char aux;
        fread(&aux, 1, 1, f1);
        fwrite(&aux, 1, 1, f2);
    }

    unsigned char c;
    int medie;

    for(i=0;i<height;i++)
        for(j=0;j<width;j++)
        {
            medie = 0;
            for(k=0;k<3;k++)
            {
                fread(&c, 1, 1, f1);

                medie += c;

                //fwrite(&c,1,1,f2);
            }
            medie /= 3;
            c = medie;
            fwrite(&c,1,1,f2);
            fwrite(&c,1,1,f2);
            fwrite(&c,1,1,f2);
        }
}

void convertToTextFile(char *original, char *copy)
{
    FILE *f1 = fopen(original, "rb");
    FILE *f2 = fopen(copy, "w");

    int i,j,k;
    char c;

    for(i=0;i<header;i++)
    {
        fread(&c,1,1,f1);

        fprintf(f2,"%d ",c);
    }

    fprintf(f2,"\n");

    for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
        {
            for(k=0;k<3;k++)
            {
                fread(&c,1,1,f1);
                fprintf(f2,"%d ",c);
            }
            fprintf(f2,"\t");
        }
        fprintf(f2,"\n");
    }
}

int main()
{
    //albNegru();

    convertToTextFile("img.bmp", "img.txt");

    return 0;
}

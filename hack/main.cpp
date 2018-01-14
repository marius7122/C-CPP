#include <stdio.h>

bool mat[52][52];
void createMat()
{
    int i,j,m;
    i=m=0;
    while(i < 50)
    {
        if(m%2 == 0)
            for(j=0;j<50;j++)
                mat[i][j] = 1;

        if(m%4 == 3)
            mat[i][0] = 1;
        if(m%4 == 1)
            mat[i][49] = 1;

        i++;
        m++;
    }
}

void writeFile()
{
    FILE * f = fopen("hack.out","w");

    fprintf(f,"50 50 1 1\n");

    createMat();

    int i,j;
    for(i=0;i<50;i++)
    {
        for(j=0;j<50;j++)
            fprintf(f,"%d",mat[i][j]);
        fprintf(f,"\n");
    }

    fclose(f);
}

int main()
{
    createMat();
    writeFile();
    return 0;
}

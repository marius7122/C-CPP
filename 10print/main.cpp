#include <stdio.h>
#include <stdlib.h>

const int lines=100;
const int colums = 100;
const int numOfChar = 2;
char c[] = "/\\";

int main()
{
    int i,j;
    for(i=0;i<lines;i++)
    {
        for(j=0;j<colums;j++)
            printf("%c",c[rand() % numOfChar]);
        printf("\n");
    }

    return 0;
}

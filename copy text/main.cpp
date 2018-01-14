#include <stdio.h>

FILE *f1 = fopen("toReadText.txt","r");
FILE *f2 = fopen("resultFile.txt","w");

char c;
int i,n;

int main()
{
    fscanf(f1,"%c",&c);

    printf("number of prints = ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
        fprintf(f2,"%c",c);

    printf("%c",c);

    return 0;
}

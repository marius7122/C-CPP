#include <stdio.h>

void FLIP(int n,int v[100],int i,int j)
{
    int aux;
    while(i<j)
    {
        aux = v[i];
        v[i] = v[j];
        v[j] = aux;

        i++;
        j--;
    }
}

int v[100],n,i,j;
int gasit;

int main()
{
    //citeste
    printf("n = ");scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("v[%d] = ",i);
        scanf("%d",&v[i]);
    }


    //sorteaza
    for(i=n;i>1;i--)
    {
        //nu se afla pe pozitia corecta
        if(v[i] != i)
        {
            //nu se afla pe prima pozitie
            if(v[1] != i)
            {
                gasit = 0;

                //caut elementul i
                for(j=2;j<=i && !gasit;j++)
                    if(v[j] == i)
                    {
                        gasit = 1;
                        //il aduc pe prima pozitie
                        FLIP(n,v,1,j);
                    }
            }

            //aduc elementul i pe linia i
            FLIP(n,v,1,i);
        }
    }

    //afisaza
    for(i=1;i<=n;i++)
        printf("%d ",v[i]);
    printf("\n");

    return 0;
}

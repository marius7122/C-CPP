#include <stdio.h>

FILE *f1 = fopen("union.in","r");
FILE *f2 = fopen("union.out","w");

struct dim
{
    int lx,ly;
};

const int N = 30;

int t,n,m,k,i,j;
bool mat[N][N];
dim drMax[N][N];    //dreptunghi de arie maxima care se termina pe poz (i,j)
dim nul = {0,0};

void citire()
{
    char c;

    fscanf(f1,"%d%d%d\n",&n,&m,&k);

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            fscanf(f1,"%c",&c);

            if(c == '1')
                mat[i][j] = true;
            else
                mat[i][j] = false;
        }
        fscanf(f1,"\n");
    }
}

void bordare()
{
    for(i=0;i<=n+1;i++)
        mat[i][0] = mat[i][m+1] = false,
        drMax[i][0] = drMax[i][m+1] = nul;

    for(i=0;i<=m+1;i++)
        mat[0][i] = mat[n+1][i] = false,
        drMax[0][i] = drMax[n+1][i] = nul;
}

int min(int a,int b)
{
    if(a<b)
        return a;
    return b;
}
int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}

dim getDrMax()
{
    dim sol = nul,aux = nul;

    sol.lx = min(min(drMax[i-1][j].lx , drMax[i][j-1].lx) , drMax[i-1][j-1].lx) + 1;
    sol.ly = min(min(drMax[i-1][j].ly , drMax[i][j-1].ly) , drMax[i-1][j-1].ly) + 1;

    int S = sol.ly * sol.lx;

    if()


}

void afisDr()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            printf("(%d %d) ",drMax[i][j].lx,drMax[i][j].ly);

        printf("\n");
    }

    printf("\n");
}

void afisMat()
{
    int i,j;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            printf("%d ",mat[i][j]);
        printf("\n");
    }

    printf("\n");
}


int main()
{
    fscanf(f1,"%d",&t);

    while(t--)
    {
        citire();

        bordare();

        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            {
                drMax[i][j] = nul;

                if(mat[i][j])
                {
                    drMax[i][j] = getDrMax();
                }
            }

        afisDr();



    }


    return 0;
}

#include <stdio.h>

FILE *f1 = fopen("pav.in","r");
FILE *f2 = fopen("pav.out","w");

const int N = 600;

int n, cx, cy, p = 1;
int mat[N][N];

int cadr(int i1,int j1,int i,int j,int n)
{
    i = i - i1 + 1;
    j = j - j1 + 1;
    n /= 2;

    if(i <= n)
        if(j <= n)
            return 1;
        else
            return 2;
    if(j <= n)
        return 3;
    return 4;
}

//pozitia pe care incepe cadranul, pozitia libera, dimensiunea cadranului
void pav(int i,int j,int li,int lj,int n)
{
    //printf("%d %d %d %d %d\n",i,j,li,lj,n);

    if(n == 2)
    {
        if(!mat[i][j]) mat[i][j] = p;
        if(!mat[i][j+1]) mat[i][j+1] = p;
        if(!mat[i+1][j]) mat[i+1][j] = p;
        if(!mat[i+1][j+1]) mat[i+1][j+1] = p;
        p++;
        return;
    }

    int mn = n / 2;
    int mi = i + mn;
    int mj = j + mn;
    int c = cadr(i, j, li, lj, n);

    if(c == 1)
    {
        mat[mi-1][mj] = mat[mi][mj-1] = mat[mi][mj] = p++;

        pav(i,j, li,lj, mn);
        pav(i,mj, mi-1,mj , mn);
        pav(mi,j, mi,mj-1, mn);
        pav(mi,mj, mi,mj, mn);
    }
    if(c == 2)
    {
        mat[mi-1][mj-1] = mat[mi][mj-1] = mat[mi][mj] = p++;

        pav(i,j, mi-1,mj-1, mn);
        pav(i,mj, li,lj , mn);
        pav(mi,j, mi,mj-1, mn);
        pav(mi,mj, mi,mj, mn);
    }
    if(c == 3)
    {
        mat[mi-1][mj-1] = mat[mi-1][mj] = mat[mi][mj] = p++;

        pav(i,j, mi-1,mj-1, mn);
        pav(i,mj, mi-1,mj , mn);
        pav(mi,j, li,lj, mn);
        pav(mi,mj, mi,mj, mn);
    }
    if(c == 4)
    {
        mat[mi-1][mj-1] = mat[mi-1][mj] = mat[mi][mj-1] = p++;

        pav(i,j, mi-1,mj-1, mn);
        pav(i,mj, mi-1,mj , mn);
        pav(mi,j, mi,mj-1, mn);
        pav(mi,mj, li,lj, mn);
    }
}

int main()
{
    fscanf(f1,"%d%d%d",&n,&cx,&cy);
    n = 1 << n;
    mat[cx][cy] = -1;

    pav(1,1,cx,cy,n);

    mat[cx][cy] = 0;

    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            fprintf(f2,"%d%c",mat[i][j], (j==n)?'\n' : ' ');

    return 0;
}

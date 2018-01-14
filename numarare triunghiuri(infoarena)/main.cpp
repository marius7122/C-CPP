#include <stdio.h>
#include <algorithm>

FILE *f1 = fopen("nrtri.in","r");
FILE *f2 = fopen("nrtri.out","w");

const int N = 805;

int n,i,j,sum,sol;
int v[N];

///returneaza indicele celui ultimului numar <= nr
int bs(int nr)
{
    int pas = 1 << 10;
    int sol = 0;

    while(pas)
    {
        if(pas + sol < n && v[pas + sol] <= nr)
            sol += pas;

        pas /= 2;
    }

    return sol;
}

int main()
{
    fscanf(f1,"%d",&n);
    for(i=0;i<n;i++)
        fscanf(f1,"%d",&v[i]);

    std::sort(v,v+n);

    ///cat timp mai sunt posibilitati de creeare a unui triunghi (mai sunt cel putin 2 bete)
    for(i=0;i<n-2;i++)
        for(j=i+1;j<n-1;j++)
        {
            sum = v[i] + v[j];

            sol += bs(sum) - j;
        }

    fprintf(f2,"%d",sol);

    return 0;
}

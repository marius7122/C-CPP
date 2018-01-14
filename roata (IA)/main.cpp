#include <stdio.h>

FILE *f1 = fopen("roata.in","r");
FILE *f2 = fopen("roata.out","w");

const int N = 370;
const int P = 100010;

int n, p, i, j, min, q, next, ultimaCabina;
int r[P], ord[N];
bool gol[N];
long long sum;

int main()
{
    fscanf(f1,"%d%d",&n,&p);
    for(i=1;i<=p;i++)
    {
        fscanf(f1,"%d",&r[i]);
        sum += r[i];
    }

    fprintf(f2,"%lld\n",sum);

    //incarc caruselul
    for(i=1;i<=n && i<=p;i++)
        ord[i] = i;
    next = i;

    //marchez locurile goale
    for(i=p+1;i<=n;i++)
        gol[i] = true;

    for(i=1;i<=p;)
    {
        //caut minimul
        min = P;
        for(j=1;j<=n;j++)
            if(!gol[j] && r[ord[j]] < min)
                min = r[ord[j]];

        //scad minimul
        for(j=1;j<=n;j++)
        {
            if(gol[j])
                continue;

            r[ord[j]] -= min;

            if(r[ord[j]] == 0)
            {
                fprintf(f2,"%d ",ord[j]);
                ultimaCabina = j;
                i++;

                if(next > p)
                    gol[j] = true;
                else
                    ord[j] = next++;
            }
        }
    }
    fprintf(f2,"\n%d",ultimaCabina);

    return 0;
}

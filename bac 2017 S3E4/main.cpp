#include <stdio.h>

unsigned long x,lmax,lsecv,nrap;

int main()
{
    FILE * f = fopen("bac.txt","r");

    while(!feof(f))
    {
        fscanf(f,"%lu",&x);

        if(x%2 == 0)
        {
            lsecv = 1;

            while(!feof(f) && x%2 == 0)
            {
                fscanf(f,"%lu",&x);
                lsecv++;
            }

            lsecv--;

            if(lsecv == lmax)
                nrap++;

            else if(lsecv > lmax)
            {
                lmax = lsecv;
                nrap = 1;
            }
        }
    }

    if(lmax== 1 || lmax==0)
        nrap = 0;

    printf("%lu",nrap);

    return 0;
}

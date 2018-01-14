#include <stdio.h>

const int max_cif = 101;
class huge
{
    public:

    char cif[max_cif];
    int n;

    void afis()
    {
        for(int i = n-1; i >= 0; i--)
            printf("%d",cif[i]);
        printf("\n");
    }

    void atrib(int x)
    {
        n = 0;
        while(x > 0)
        {
            cif[n++] = x % 10;
            x /= 10;
        }
    }

    void atribHuge(huge x)
    {
        n = x.n;
        for(int i=0; i<n; i++)
            cif[i] = x.cif[i];
    }

    void addHuge(huge x)
    {
        int i, t = 0;

        if(n < x.n)
        {
            for(i=n;i<x.n;i++)
                cif[i] = 0;
            n = x.n;
        }
        else
            for(i=x.n;i<n;i++)
                x.cif[i] = 0;

        for(i=0;i<n;i++)
        {
            cif[i] += x.cif[i] + t;
            t = cif[i] / 10;
            cif[i] %= 10;
        }

        if(t)
            cif[n++] = t;
    }

    void subHuge(huge x)
    {
        int i, t = 0;

        for(i=x.n; i<n; i++)
            x.cif[i] = 0;

        for(i=0; i<n; i++)
        {
            cif[i] -= x.cif[i] + t;

            if(cif[i] < 0)
                t = 1;
            else
                t = 0;

            if(t)
                cif[i] += 10;
        }

        while(cif[n-1] == 0)
            n--;
    }

    void inmHuge(huge x)
    {
        int i,j,t = 0;
        int prod[max_cif + 1];

        prod[0] = n + x.n - 1;
        for(i=1; i<=prod[0] + 1; i++)
            prod[i] = 0;

        for(i=0; i<n; i++)
            for(j=0; j<x.n; j++)
                prod[i + j + 1] += cif[i] * x.cif[j];

        for(i=1; i<=prod[0]; i++)
        {
            prod[i] += t;
            t = prod[i] / 10;
            prod[i] %= 10;
        }

        if(t)
            prod[++prod[0]] = t;

        n = prod[0];
        for(i=0;i<n;i++)
            cif[i] = prod[i+1];
    }

    void div(int x)
    {
        int i, R = 0;

        for(i=n-1; i>=0; i--)
        {
            R = 10 * R + cif[i];
            cif[i] = R / x;
            R %= x;
        }

        while(n && cif[n-1] == 0)
            n--;
    }
};


int main()
{
    huge a,b;
    a.atrib(100000);
    b.atrib(999999999);

    a.afis();
    b.afis();

    a.div(10);

    a.afis();


    return 0;
}

#include <stdio.h>

FILE *f1 = fopen("elmaj.in","rb");
FILE *f2 = fopen("elmaj.out","w");

const int buff_size = 100000;
int buff_pos;
char buff[buff_size];
inline void citeste(int &x)
{
    while(buff[buff_pos] < '0' || buff[buff_pos] > '9')
        if(++buff_pos == buff_size)
        {
            fread(buff,1,buff_size,f1);
            buff_pos = 0;
        }

    x = 0;
    while(buff[buff_pos] >= '0' && buff[buff_pos] <= '9')
    {
        x = x * 10 + buff[buff_pos] - '0';
        if(++buff_pos == buff_size)
        {
            fread(buff,1,buff_size,f1);
            buff_pos = 0;
        }
    }
}

int el,ap,x,i,n;

int main()
{
    citeste(n);

    for(i=0;i<n;i++)
    {
        citeste(x);
        if(ap == 0)
        {
            el = x;
            ap = 1;
        }
        else
            if(x == el)
                ap++;
            else
                ap--;
    }

    f1 = fopen("elmaj.in","rb");
    fread(buff,1,buff_size,f1);
    buff_pos = 0;

    citeste(n);

    ap = 0;
    for(i=0;i<n;i++)
    {
        citeste(x);

        if(el == x)
            ap++;
    }

    if(ap > n/2)
        fprintf(f2,"%d %d",el,ap);
    else
        fprintf(f2,"-1");

    return 0;
}

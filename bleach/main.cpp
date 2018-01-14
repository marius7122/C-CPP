#include <stdio.h>
#include <set>

FILE *f1 = fopen("bleach.in","rb");
FILE *f2 = fopen("bleach.out","w");

const int buff_size = 100000;
int buff_pos;
char buff[buff_size];
bool unUsed = true;
inline void citeste(int &x)
{
    if(unUsed)
    {
        unUsed = false;
        fread(buff,1,buff_size,f1);
    }
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

const int N = 1000005;
const int maxP = 1000000000;

int n,k,i,x,pmin;
int p;
//int v[N];
std::multiset<int> heap;


inline void verifica(int el)
{
    if(p < el)
    {
        int dif = el - p;
        pmin += dif;
        p += dif;
    }
    if(p < maxP)
        p += el;
}

int main()
{
    //fscanf(f1,"%d%d",&n,&k);
    citeste(n);
    citeste(k);
    for(i=0;i<k;i++)
    {
        //fscanf(f1,"%d",&x);
        citeste(x);
        heap.insert(x);
    }
    for(i=k;i<n;i++)
    {
        citeste(x);
        heap.insert(x);

        //v[i-k] = *heap.begin();
        verifica(*heap.begin());
        heap.erase(heap.begin());
    }
    for(i=0;i<k;i++)
    {
        //v[n-k+i] = *heap.begin();
        verifica(*heap.begin());
        heap.erase(heap.begin());
    }

    fprintf(f2,"%d",pmin);
    return 0;
}

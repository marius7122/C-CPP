#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

struct nr
{
    char nume[50];
    int n;
    char numar[50][50];
};

nr v[10];
int n;

void citesteNR2(int i,int j)
{
    char c;
    cin>>c;
    int l = 0;
    while(c >= '0' && c <= '9')
    {
        v[i].numar[j][l++] = c;
        cin>>c;
    }


}

void citesteNR(int i)
{
    char c;
    cin>>c;

    int l = 0;

    while(c!=' ')
    {
        v[i].nume[l++] = c;
        cin>>c;
    }

    cin>>v[i].n;
    cin>>c;

    for(int j=0;j<v[i].n;j++)
        citesteNR2(i,j);
}

void citeste()
{
    cin>>n;

    for(int i=0;i<n;i++)
        citesteNR(i);
}

int main()
{
    citeste();

    printf("%d %s %s\n",v[0].n, v[0].nume, v[0].numar[0]);

    return 0;
}

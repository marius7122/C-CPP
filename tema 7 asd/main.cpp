#include <iostream>
using namespace std;

struct abc
{
    int info;
    abc *left = NULL, *right = NULL;
};

void insert(abc **r, int x)
{
    abc *nou = new abc;
    nou->info = x;

    if(!(*r))
    {
        *r = nou;
        return;
    }

    abc *aux = *r;
    while(true)
    {

    }
}


int main()
{

    return 0;
}

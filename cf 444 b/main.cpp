#include <iostream>

struct cub
{
    bool hasDigit[10];
}c[3];

int maxElement = 0;

bool checkCombination(int i1,int i2,int i3,int x)
{
    i1--;i2--;i3--;
    if(x < 10)
        return c[i1].hasDigit[x%10];
    if(x < 100)
        return c[i2].hasDigit[x%10] && c[i1].hasDigit[x/10%10];
    return c[i3].hasDigit[x%10] && c[i2].hasDigit[x/10%10] && c[i3].hasDigit[x/100%10];
}

bool checkPosible(int x)
{
    return checkCombination(1,2,3,x) || checkCombination(1,3,2,x) || checkCombination(2,1,3,x) || checkCombination(2,3,1,x) || checkCombination(3,1,2,x) || checkCombination(3,2,1,x);
}

void getElements()
{
    for(int i=1;i<1000;i++)
        if(!checkPosible(i))
        {
            maxElement = i-1;
            return;
        }
}

int main()
{
    int n;
    std::cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<6;j++)
        {
            int f;
            std::cin>>f;
            c[i].hasDigit[f] = true;
        }
    }

    getElements();

    std::cout<<maxElement;

    return 0;
}

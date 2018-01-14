#include <iostream>
using namespace std;

int n,i,x,maxCafeIndex,sol;
int lastVisit[200005];

int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        lastVisit[x] = i;
        if(x > maxCafeIndex)
            maxCafeIndex = x;
    }

    lastVisit[maxCafeIndex + 1] = 200005;
    sol = maxCafeIndex + 1;

    for(i=0;i<=maxCafeIndex;i++)
        if(lastVisit[i] < lastVisit[sol] && lastVisit[i])
            sol = i;

    cout<<sol;

    return 0;
}

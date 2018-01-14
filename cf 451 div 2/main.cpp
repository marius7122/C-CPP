#include <iostream>
using namespace std;

int n;

int main()
{
    cin>>n;

    int x = n%10;

    if(x <= 5)
        n -= x;
    else
        n += 10 - x;

    cout<<n;

    return 0;
}

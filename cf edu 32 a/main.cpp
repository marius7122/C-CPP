#include <iostream>
using namespace std;

int n,i,x1,x2,x3,cnt;

int main()
{
    cin>>n;

    if(n < 3)
    {
        cout<<"0";
        return 0;
    }

    cin>>x1>>x2>>x3;

    for(i=3;i<=n;i++)
    {
        //verif
        if(x2 > x1 && x2 > x3)
            cnt ++;
        if(x2 < x1 && x2 < x3)
            cnt ++;

        //permut
        x1 = x2;
        x2 = x3;
        if(i != n)
            cin>>x3;
    }

    cout<<cnt;

    return 0;
}

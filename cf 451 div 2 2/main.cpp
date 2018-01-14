#include <iostream>
using namespace std;

int n,x,y,i,j,aux;

int main()
{
    cin>>n>>x>>y;

    while(true)
    {
        aux = n - x * i;

        if(aux < 0)
        {
            cout<<"NO";
            return 0;
        }

        if(aux % y == 0)
        {
            cout<<"YES\n"<<i<<' '<<aux/y;
            return 0;
        }

        i++;
    }

    return 0;
}

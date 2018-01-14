#include <iostream>

using namespace std;

int ord;
unsigned n, sch, ant, act;

int main()
{
    cout << "n=" ; cin >> n;

    ant = n % 10;
    n = n / 10;

    while(n != 0)
    {
        act = n%10;

        if(ord == 0)
        {
            if(act > ant)
                ord = 1;
            else
                ord = -1;
        }
        else if(ord == 1 && act < ant)
        {
            ord = -1;
            sch++;
        }
        else if(ord == -1 && act > ant)
        {
            ord = 1;
            sch++;
        }

        ant = act;
        n /= 10;
    }

    if(sch == 1)
    {
        if(ord == 1)
            cout<<"vale";
        else
            cout<<"munte";
    }

    else
        cout<<"nu e nici munte nici vale";

    return 0;
}

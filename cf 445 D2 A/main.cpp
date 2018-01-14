#include <iostream>
#include <algorithm>
using namespace std;

int i, sum;
int a[7];
int perm[] = {1,2,3,4,5,6};

bool check()
{
    return a[perm[0]] + a[perm[1]] + a[perm[2]] == a[perm[3]] + a[perm[4]] + a[perm[5]];
}

int main()
{
    for(i=1;i<=6;i++)
        cin>>a[i];

    do
    {
        if(check())
        {
            cout<<"YES";
            return 0;
        }
    }while(next_permutation(perm, perm + 6));

    cout<<"NO";

    return 0;
}

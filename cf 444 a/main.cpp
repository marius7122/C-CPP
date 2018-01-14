#include <iostream>
#include <string.h>

char s[1005];
int bigestP,n;

int main()
{
    std::cin>>s;
    n = strlen(s);

    for(int i=0;i<n;i++)
        if(s[i] == '1')
        {
            bigestP = n - i - 1;
            break;
        }



    if(bigestP >= 6)
        std::cout<<"yes";
    else
        std::cout<<"no";

    //std::cout<<'\n'<<n - highestPos + 1<<' '<<n;

    return 0;
}

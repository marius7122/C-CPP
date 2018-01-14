#include <stdio.h>
#define ll long long
 
const ll mod = 1999999973;
 
ll p(ll x,ll n)
{
    ll rez = 1;
    ll pow = x;
     
    for(int i = 0;i<32;i++,pow=(pow*pow)%mod)
        if((1<<i) & n)
            rez = (rez * pow) % mod;
        
    return rez;
}
 
ll n,x;
int main()
{
    fscanf(fopen("lgput.in","r"),"%lld%lld",&x,&n);
    fprintf(fopen("lgput.out","w"),"%lld",p(x,n));
    return 0;
}
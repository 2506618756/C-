#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    long long t,n,m;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&m);
        int z = n&m;
        if( z==0 ) printf("1\n");
        else printf("%lld\n",n&m);
    }
    return 0;
}

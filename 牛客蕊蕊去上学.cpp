#include <iostream>
#include <cstdio> 
using namespace std;
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    double sum = 1.0*a*a/(a+b)+1.0*b*b/(a+b);
    printf("%.2f\n",sum);
    return 0;
}

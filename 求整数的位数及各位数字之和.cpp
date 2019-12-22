#include <stdio.h>
int main()
{
    int n,sum=0,cnt=0;
    scanf("%d",&n);
    do
    {
        sum += (n%10);
        cnt++;
        n /= 10;
    }while(n);
    printf("%d %d",cnt,sum);
    return 0;
}

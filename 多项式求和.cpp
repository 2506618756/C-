#include <stdio.h>
int main()
{
    int n;
    int a[4];
    scanf("%d",&n);
    for( int i=0; i<4; i++ )
    {
        a[i] = (n+9)%10;
        n /= 10;
    }
    printf("The encrypted number is %d%d%d%d",a[1],a[0],a[3],a[2]);
    return 0;
}

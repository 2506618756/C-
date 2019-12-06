#include <stdio.h>

double Fac(int x)
{
	if( x<0 )
		return 0;
	else if( x==0 )
		return 1;
	else
	{
		int sum = 1;
		for( int i=1; i<=x; i++ )
			sum *= i;
		return double(sum);	
	}
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%g\n", Fac(n));
    return 0;
}

#include <stdio.h>
#include <math.h>

int IsSquare( int n );

int main()
{
    int n;

    scanf("%d", &n);
    if ( IsSquare(n) ) printf("YES\n");
    else printf("NO\n");

    return 0;
}

int IsSquare(int n)
{
	int i,a=0;
	for(i=0;i*i<=n;i++)
	{
		if(i*i==n)
		{
			a=1;
			break;
		}
		
	}
	return a;
}

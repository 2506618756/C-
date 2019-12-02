#include <stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	while( T-- )
	{
		int a[4];
		int sum=0,cnt=0;
		for( int i=0; i<4; i++ )
		{
			scanf("%d",&a[i]);
			sum += a[i];
		}
		sum /= 3;
		for( int i=0; i<4; i++ )
		{
			if( a[i]==sum )
				cnt++;
		}
		if( cnt<2 )
			printf("-1\n");
		else
			printf("%d\n",sum);		
	}
	return 0;	
}

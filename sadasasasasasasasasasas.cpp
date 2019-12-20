#include <stdio.h>
#include <math.h>

void search( int n );

int main()
{
    int number;

    scanf("%d",&number);
    search(number);
    //printf("count=%d\n",search(number));
		
    return 0;
}
void search( int n )
{
	for( int i=101; i<=n; i++ )
	{
		if( i==(int)sqrt(i)*(int)sqrt(i) )
			printf("%d\n",i);
	}
}

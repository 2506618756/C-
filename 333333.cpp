#include <stdio.h>
#include <math.h>
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int num,flag=0;
		scanf("%d",&num);
		if( num<0 ) num = -num;
		int t = num,cnt = 0;
		do
		{
			t /= 10;
			cnt++;
		}while(t);
		for( int i=cnt; i>0; i-- )
		{
			int k = pow(10,i-1);
			k = (num/k)%10;
			if(flag) printf(" ");
			if(!flag) flag = 1;
			printf("%d",k);
		}
		printf("\n");
	}
	return 0;
}

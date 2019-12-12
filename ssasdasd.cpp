#include <stdio.h>
#include <string.h>
int main()
{
	int n;
	scanf("%d",&n);
	int ans = 0;
	while(n)
	{
		ans = ans * 10 + n % 10;
		n /= 10;
	}while(n);
	do
	{
		printf("%d ",ans%10);
		ans /= 10;
	}while(ans);
	return 0;
}


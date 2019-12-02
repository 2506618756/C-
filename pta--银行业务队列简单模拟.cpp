#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int main()
{
	int n,flag=0;
	scanf("%d",&n);
	int a[n];
	queue<int> odd,even;
	for( int i=0; i<n; i++ )
	{
		scanf("%d",&a[i]);
		if( a[i]%2 )
			odd.push(a[i]);
		else
			even.push(a[i]); 
	}
	while( !odd.empty() || !even.empty() )
	{
		if( !odd.empty() )
		{
			if( flag != 0 )
				printf(" ");
			printf("%d",odd.front());
			odd.pop();
			flag = 1;
		}
		if( !odd.empty() )
		{
			if( flag != 0 )
				printf(" ");
			printf("%d",odd.front());
			odd.pop();
			flag = 1;
		}
		if( !even.empty() )
		{
			if( flag != 0 )
				printf(" ");
			printf("%d",even.front());
			even.pop();
			flag = 1;
		}
	}
	return 0;
}

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int visted[1005];
int a[1005];
int n,m;
int cnt;
int flag;
void dfs( int num )
{
	if( flag==1 )
		return ;
	if( n==num )
	{
		cnt++;
		if( cnt==m && flag==0 )
		{
			for( int i=0; i<n; i++ )
			{
				cout<<a[i];
				if( i<n-1 )
					cout<<" ";	
			}
			cout<<endl;
			flag = 1;
			return ;	
		}
	}
	for( int i=1; i<=n; i++ )
	{
		if( visted[i]==0 )
		{
			a[num] = i;
			visted[i] = 1;
			dfs(num+1);
			visted[i] = 0;
		}
	}
}
int main()
{
	while( ~scanf("%d%d",&n,&m) )
	{
		flag = 0;
		cnt = 0;
		memset(visted,0,sizeof(visted));
		dfs(0);
	}
	return 0;	
}

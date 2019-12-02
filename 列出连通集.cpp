#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

int n,m;
int temp[11][11];
int visted[11];
void dfs( int k )
{
	for( int i=0; i<n; i++ )
	{
		if( !visted[i] && temp[k][i] )
		{
			visted[i] = 1;
			printf(" %d",i);
			dfs(i);
		}
	}
	return ;
}
void bfs( int k )
{
	queue<int> q;
	visted[k] = 1;
	q.push(k);
	while( !q.empty() )
	{
		int t = q.front();
		q.pop();
		for( int i=0; i<n; i++ )
		{
			if( !visted[i] && temp[t][i] )
			{
				visted[i] = 1;
				printf(" %d",i);
				q.push(i);
			}
		}
	}
	return ;
}
int main()
{
	scanf("%d%d",&n,&m);
	int x,y;
	memset(temp,0,sizeof(temp));
	for( int i=0; i<m; i++ )
	{
		scanf("%d%d",&x,&y);
		temp[x][y] = temp[y][x] = 1;
	}
	memset(visted,0,sizeof(visted));
	for( int i=0; i<n; i++ )
	{
		if( !visted[i] )
		{
			visted[i] = 1;
			printf("{ ");
			printf("%d",i);
			dfs(i);
			printf(" }\n");
		}
	}
	memset(visted,0,sizeof(visted));
	for( int i=0; i<n; i++ )
	{
		if( !visted[i] )
		{
			visted[i] = 1;
			printf("{ ");
			printf("%d",i);
			bfs(i);
			printf(" }\n");
		}
	}
	return 0;
}

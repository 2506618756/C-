#include <stdio.h>
#include <string.h>
#define maxx 3005
int edge[maxx][maxx];
int visted[maxx];
int temp[maxx];
int cnt=0;
void dfs( int x, int n )
{
	if( visted[x] ) return ;
	visted[x] = 1;
	temp[cnt] = x;
	cnt++;
	for( int i=1; i<=n; i++ )
	{
		if( visted[i]==0 && edge[x][i]==1 )
		{
			dfs(i,n);
			temp[cnt] = x;
			cnt++;
		}
	}		
	return ;
}
int main()
{
	int n,m,s;
	scanf("%d%d%d",&n,&m,&s);
	memset(edge,0,sizeof(edge));
	memset(visted,0,sizeof(visted));
	memset(temp,0,sizeof(temp));
	for( int i=1; i<=m; i++ )
	{
		int x,y;
		scanf("%d%d",&x,&y);
		edge[x][y] = edge[y][x] = 1;
	}
	dfs(s,n);
	for( int i=0; i<cnt-1; i++ )
		printf("%d ",temp[i]);
	printf("%d",temp[0]);
	if(cnt!=2*n-1) printf(" 0");
	return 0;
}

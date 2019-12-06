#include <stdio.h>
#include <string.h>
const int maxx = 105;
const int inf = 65535;
int prim( int edge[][maxx], int m, int n )
{
	int ans = 0;
	int book[maxx],dis[maxx];
	memset(book,0,sizeof(book));
	book[0] = 1;
	for( int i=1; i<n; i++ )
		dis[i] = edge[0][i];
	for( int i=1; i<n; i++ )
	{
		int minn = inf,u = -1;
		for( int j=0; j<n; j++ )
		{
			if( !book[j] && dis[j]<minn )
			{
				minn = dis[j];
				u = j;
			}
		}
		if( minn==inf )
			return -1;
		ans += minn;
		book[u] = 1;
		for( int v=0; v<n; v++ )
			if( !book[v] )
				dis[v] = dis[v]<edge[u][v]?dis[v]:edge[u][v];
	}
	return ans;
}
int main()
{
	int n,m;
	int edge[maxx][maxx];
	for( int i=0; i<=maxx; i++ )
		for( int j=0; j<=maxx; j++ )
			if( i==j ) edge[i][j] = 0;
			else edge[i][j] = inf;
	scanf("%d%d",&n,&m);
	for( int i=0; i<m; i++ )
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if( edge[a][b]>c )
			edge[a][b] = edge[b][a] = c;
	}
	int ans = prim(edge,m,n);
	if( ans == -1 )
		printf("Impossible\n");
	else
		printf("%d\n",ans);
	return 0;
}

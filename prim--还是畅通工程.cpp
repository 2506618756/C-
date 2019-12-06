#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;
const int inf = 65535;
const int maxx = 105;
int edge[maxx][maxx],dis[maxx],book[maxx];
int n,m;
void inti_set()
{
	for( int i=1; i<=n; i++ )
		for( int j=1; j<=n; j++ )
			if( i==j ) edge[i][j] = 0;
			else edge[i][j] = inf;
}
int prim( int edge[][maxx], int m )
{
	int ans = 0;
	memset(book,0,sizeof(book));
	book[1] = 1;
	for( int i=2; i<=n; i++ )
		dis[i] = edge[1][i];
	for( int i=1; i<n; i++ )
	{
		int minn = inf,u = -1;
		for( int j=1; j<=n; j++ )
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
		for( int v=1; v<=n; v++ )
			if( !book[v] )
				dis[v] = dis[v]<edge[u][v]?dis[v]:edge[u][v];
	}
	return ans;
}
int main()
{
	while( ~scanf("%d",&n) && n!=0 )
	{
		m = n*(n-1)/2;
		inti_set();
		for( int i=1; i<=m; i++ )
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			if( edge[a][b]>c )
				edge[a][b] = edge[b][a] = c;
		}
		printf("%d\n",prim(edge,m));
	}
	return 0;
}

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxx = 105;
int n,m;
struct Edge{
	int from,to,w;
} edge[maxx*3];
int s[maxx];
void inti_set()
{
	for( int i=1; i<=maxx; i++ )
		s[i] = i;
}
bool cmp( Edge a, Edge b ){ return a.w>b.w; }
int find_set( int x )
{
	int r = x;
	while( r!=s[r] ) r = s[r];
	int i = x,j;
	while( i!=j )
	{
		j = s[i];
		s[i] = r;
		i = j;
	}
	return r;
}
int kruskal()
{
	int ans = 0,cnt = 0;
	sort( edge+1, edge+1+m, cmp );
	for( int i=1; i<=m; i++ )
	{
		int x = find_set(edge[i].from);
		int y = find_set(edge[i].to);
		if( x==y ) continue;
		s[x] = y;
		cnt++;
		ans += edge[i].w;
	}
	if( cnt<n-1 )
		ans = 0;
	return ans;
}
int main()
{
	int t;
	scanf("%d",&t);
	while( t-- )
	{
		inti_set();
		scanf("%d%d",&n,&m);
		for( int i=1; i<=m; i++ )
			scanf("%d%d%d",&edge[i].from,&edge[i].to,&edge[i].w);
		int ans = kruskal();
			printf("%d\n",ans);
	}
	return 0;
}

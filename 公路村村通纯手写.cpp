#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct Edge{ int from,to,w; } edge[3005];
int s[1005];
int n,m,cnt=0;
bool cmp( Edge a,Edge b ){ return a.w<b.w; }
int find_set( int x ){ return x==s[x]? x:find_set(s[x]); }
int kruskal()
{
	int ans = 0;
	for( int i=1; i<=n; i++ )
		s[i] = i;
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
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for( int i=1; i<=m; i++ )
		scanf("%d%d%d",&edge[i].from,&edge[i].to,&edge[i].w);
	int ans = kruskal();
	if( ans<n-1 )
		ans = -1;
	printf("%d\n",ans);
}

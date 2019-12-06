#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct Edge{ int from,to,w,yes; } edge[5000];
int n,cnt=0;
int s[101];
bool cmp( Edge a, Edge b ){
	if( a.yes==b.yes )
		return a.w<b.w;
	else
		return a.yes>b.yes;
}
int find_set( int x ){ return x==s[x]?x:find_set(s[x]); }
int kruskal()
{
	int ans = 0;
	for( int i=1; i<=n; i++ )
		s[i] = i;
	sort( edge+1, edge+1+n*(n-1)/2, cmp );
	for( int i=1; i<=n*(n-1)/2; i++ )
	{
		int x = find_set( edge[i].from );
		int y = find_set( edge[i].to );
		if( x==y ) continue;
		s[x] = y;
		if( edge[i].yes==0 )
			ans += edge[i].w;
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	for( int i=1; i<=n*(n-1)/2; i++ )
		scanf("%d%d%d%d",&edge[i].from,&edge[i].to,&edge[i].w,&edge[i].yes);
	int ans = kruskal();
	printf("%d\n",ans);
	return 0;
}
/*
4
1 2 1 1
1 3 4 0
1 4 1 1
2 3 3 0
2 4 2 1
3 4 5 0
*/

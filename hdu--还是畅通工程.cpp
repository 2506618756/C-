#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct Edge{
	int from,to,w;
} edge[5000];
int s[1005];
int n;
void inti_set()
{
	for( int i=1; i<=n; i++ )
		s[i] = i;
}
bool cmp( Edge a, Edge b ){ return a.w<b.w; }
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
	sort( edge+1, edge+1+n*(n-1)/2, cmp );
	int ans = 0;
	for( int i=1; i<=n*(n-1)/2; i++ )
	{
		int x = find_set(edge[i].from);
		int y = find_set(edge[i].to);
		if( x==y ) continue;
		s[x] = y;
		ans += edge[i].w;
	}
	return ans;
}
int main()
{
	while( ~scanf("%d",&n) && n!=0 )
	{
		inti_set();
		for( int i=1; i<=n*(n-1)/2; i++ )
			scanf("%d%d%d",&edge[i].from,&edge[i].to,&edge[i].w);	
		printf("%d\n",kruskal());	
	}
	return 0;
}
/*
3
1 2 1
1 3 2
2 3 4
4
1 2 1
1 3 4
1 4 1
2 3 3
2 4 2
3 4 5
0
*/

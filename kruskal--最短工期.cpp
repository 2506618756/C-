//#include <iostream>
//#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
const int maxx = 105;
int s[maxx];
int n,m;
struct Edge{
	int from,to,w;
} edge[maxx*3];
void inti_set()
{
	for( int i=0; i<=maxx; i++ )
		s[i] = i;
}
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
int cmp( const void *a, const void *b ){ return (*(Edge *)a).w > (*(Edge *)b).w ? 1 : -1;  }
int kruskal()
{
	int ans = 0,cnt = 0;
	qsort( edge, m, sizeof(edge[0]), cmp );
	for( int i=0; i<m; i++ )
	{
		int x = find_set( edge[i].from );
		int y = find_set( edge[i].to );
		if( x==y ) continue;
		cnt++; s[x] = y;
		ans += edge[i].w;
	}
	if( cnt<n-1 )
		ans = -1;
	return ans;
}
int main()
{
	inti_set();
	scanf("%d%d",&n,&m);
	for( int i=0; i<m; i++ )
		scanf("%d%d%d",&edge[i].from,&edge[i].to,&edge[i].w);
	int ans = kruskal();
	if( ans == -1 )
		printf("Impossible\n");
	else
		printf("%d\n",ans);
	return 0;
}

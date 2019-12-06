#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct edge{
	int from,to,w;
} edge[3005];
int s[1005];
int t[1005];
int n,m;
int find_set( int x )
{
	int r = x;
	while( r!=s[r] ) r = s[r];
	int i = x,j;
	while( i != j )
	{
		j = s[i];
		s[i] = r;
		i = j;
	}
	return r;
}
void union_set( int x,int y )
{
	x = find_set(x);
	y = find_set(y);
	if( x!=y ) s[x] = y;
}
void inti_set()
{
	for( int i=1; i<=n; i++ )
		s[i] = i;
}
int main()
{
	while( ~scanf("%d",&n) && n!=0 )
	{
		inti_set();
		scanf("%d",&m);
		for( int i=1; i<=m; i++ )
		{
			scanf("%d%d",&edge[i].from,&edge[i].to);
			union_set( edge[i].from, edge[i].to );
		}
		memset(t,0,sizeof(t));
		for( int i=1; i<=n; i++ )
			t[find_set(i)] = 1;
		int ans = 0;
		for( int i=1; i<=n; i++ )
			if( t[i] )
				ans++;
		printf("%d\n",ans-1);
	}
	return 0;
}
/*
4 2
1 3
4 3
3 3
1 2
1 3
2 3
5 2
1 2
3 5
999 0
0
*/

#include <iostream>
#include <algorithm>
using namespace std;
struct Edge{
	int from,to,w,price;
}edge[505];
int x[505];
bool cmp( Edge a, Edge b )
{
	if( a.w!=b.w )
		return a.w<b.w;
	else
		return a.price>b.price;
}
void inti_set()
{
	for( int i=0; i<505; i++ )
		x[i] = i;
}
int find_set( int k )
{
	int r = k;
	while(r!=k) r = x[r];
	int i = k,j;
	while(i!=j)
	{
		j = x[i];
		x[i] = r;
		i = j;
	}
	return r;
}
void kruskal( int &len, int &price, int m )
{
	sort( edge, edge+m, cmp );
	for( int i=0; i<m; i++ )
		cout<<edge[i].from<<edge[i].to<<edge[i].w<<edge[i].price<<endl;
	for( int i=0; i<m; i++ )
	{
		int k = find_set( edge[i].from );
		int y = find_set( edge[i].to );
		if(k==y) continue;
		x[k] = y;
		len += edge[i].w; price += edge[i].price;
	}
}
int main()
{
	ios::sync_with_stdio(false); 
	int n,m,s,d;
	int len=0,price=0;
	cin>>n>>m>>s>>d;
	inti_set();
	for( int i=0; i<m; i++ )
	{
		cin>>edge[i].from>>edge[i].to>>edge[i].w>>edge[i].price;
	}
	kruskal(len,price,m);
	cout<<len<<" "<<price<<endl;
	return 0;
}

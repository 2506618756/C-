#include <iostream>
using namespace std;

int s[30001];
int root[30001]={0};
int find_set( int x ){
	return x==s[x]?x:find_set(s[x]);
}
void union_set( int x,int y ){
	x = find_set(x);
	y = find_set(y);
	if(x!=y) s[x] = y;
}
int main(){
	int n,m,k,x,y;
	cin>>n>>m;
	for( int i=1; i<=n; i++ )
		s[i] = i;		
	for( int i=0; i<m; i++ ){
		cin>>k>>x;
		for( int j=1; j<k; j++ ){
			cin>>y;
			union_set(x,y);
		}
	}
	int max = 0;
	for( int i=1; i<=n; i++ ){
		int t = find_set(i);
		root[t]++;
		if( root[t]>max ) max = root[t];
	}
	cout<<max<<endl;
	return 0;
}

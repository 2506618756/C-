#include <iostream>
using namespace std;
int temp[1005];
void inti_set(){
	for( int i=1; i<=1005; i++ ){
		temp[i] = i;
	}
}
int find_set(int x){
	return x==temp[x]? x:find_set(temp[x]);
}
void union_set(int x,int y){
	x = find_set(x);
	y = find_set(y);
	if(x!=y) temp[x] = y;
}
int main(){
	ios::sync_with_stdio(false);
	int T,n,m,x,y;
	cin>>T;
	while( T-- ){
		cin>>n>>m;
		inti_set();
		for( int i=0; i<m; i++ )
		{
			cin>>x>>y;
			union_set(x,y);
		}
		int ans = 0;
		for( int i=1; i<=n; i++ )
			if( temp[i]==i )
				ans++;
		cout<<ans<<endl;
	}
	return 0;
}

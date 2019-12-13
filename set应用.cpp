#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n,x,flag=0;
	cin>>n;
	set<int> s;
	s.clear();
	pair<set<int>::iterator,bool> ans;
	for( int i=0; i<n; i++ )
	{
		cin>>x;
		ans = s.insert(x);
		if( ans.second==false )
			flag = 1;
	}
	if(flag) printf("YES\n");
	else printf("NO\n");
	return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	
	int n,k;
	cin>>n>>k;
	int zc[n];
	for( int i=0; i<n; i++ )
		scanf("%d",&zc[i]);
	sort(zc,zc+n);
	if( n<k )
		for( int i=n-1; i>=0; i-- )
		{
			printf("%d",zc[i]);
			if(i>0)
			printf(" ");
		}
	else
	{
		for( int i=k-1; i>=0; i-- )
		{
			printf("%d",zc[n-1]);
			n--;
			if(i>0)
			printf(" ");
		}
	}
	return 0;
}

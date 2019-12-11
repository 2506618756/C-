#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	char x[4][100];
	for( int i=0; i<4; i++ )
	{
		cin>>x[i];
	}
	for( int i=0; i<4; i++ )
	{
		int len = strlen(x[i]);
		cout<<x[i][len-2]<<x[i][len-1];
	}
	cout<<endl;
	return 0; 
}

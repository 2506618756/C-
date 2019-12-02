#include <iostream>
#include <string.h>
#define MAX 10000
using namespace std;
int prime[MAX];
int k,num[21];
int temp[21];
int visted[21];
int cnt=0;
void getprime()
{
	for( int i=2; i<MAX; i++ )
	{
		if( prime[i]==0 )
		{
			for( int k=i*2; k<MAX; k+=i )
			{
				prime[k] = 1;
			}
		}
	}
}
int main()
{
	memset(prime,0,sizeof(prime));
	getprime();
	int first=1;
	int cnt=0;
	int n;
	cin>>n;
	for( int i=2; i<MAX; i++ )
	{
		if(n==0)
			break;
		if( prime[i]==0 )
		{
			if( i-first==2 )
				cnt++;
			first = i;
			n--;
		}
	}
	cout<<cnt<<endl;
	return 0;
}

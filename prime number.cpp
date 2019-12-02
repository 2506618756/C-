#include <iostream>
#include <string.h>
#define MAX 1000
using namespace std;
int prime[MAX];
int k,num[MAX];
int temp[MAX];
int visted[MAX];
int cnt=0;
void getprime()
{
	prime[0] = prime[1] = 1;
	for( int i=2; i<=MAX; i++ )
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
//	cin>>n;
//	for( int i=2; i<MAX; i++ )
//	{
//		if(n==0)
//			break;
//		if( prime[i]==0 )
//		{
//			if( i-first==2 )
//				cnt++;
//			first = i;
//			n--;
//		}
//	}
	for( int i=1; i<=MAX; i++ )
	{
		if( prime[i]==0 )
			cout<<i<<endl;
	}
	return 0;
}

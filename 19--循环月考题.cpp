#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	int n,m;
	double sum=0;
	scanf("%d%d",&m,&n);
	for( int i=m; i<=n; i++ )
		sum += 1.0*pow(i,2) + 1.0/i;
	printf("%.6f\n",sum);
	return 0;
}

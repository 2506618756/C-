#include <stdio.h>
int main()
{
	double n,m;
	scanf("%lf%lf",&n,&m);
	double sum,sum2;
	if(n==1)
		sum = m*0.9;
	else if(n==2)
		sum = m*0.8;
	else if(n>=3)
		sum = m*0.7;
	if(m>=500)
	{
		sum2 = 1.0 * m - 100;
	}
	else if(m>=1000) sum2 = 1.0 * m - 300;
	if( sum>sum2 ) sum = sum2;
	printf("%.2f\n",sum); 
	return 0;
}

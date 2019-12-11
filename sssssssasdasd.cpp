#include <stdio.h>
long long mf (long long n){
	long long i, j, a, b, sum;
	sum=0;
	a=1;
	b=2;
	if(n<3){
		return n;
	}else{
		for(i=0;i<=n-3;i++){
			sum=a+b;
			a=b;
			b=sum;
		}
		return sum;
	}
}
int main()
{
	long long i, n, m, t;
	scanf("%lld", &t);
		for(i=0;i<t;i++){
			scanf("%lld%lld", &n, &m);
			long long s;
			long long x;
			long long ans=0;
			x=m-n;
			ans=mf(x);
			printf("%lld\n", ans);
		}
	return 0;
}


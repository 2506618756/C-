#include<stdio.h>
#include<math.h>
int main()
{
	int n,i,j,k,z,max,t,a[110];
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
		break;
		else
		{
		for(i=0;i<n;i++)
			a[i] = i;
		
		for(j=0;j<n-1;j++)
		{
			max=j;
			for(k=j+1;k<n;k++)
			{
				if(fabs(a[k])>fabs(a[max]))
				max=k;
			}
			if(j!=max)
			{
				t=a[j];
				a[j]=a[max];
				a[max]=t;
			}
		}
		for(z=0;z<n;z++)
		printf("%d ",a[z]);
		printf("\n");
		}
		
	}
	
	return 0;
 }

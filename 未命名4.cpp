#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
	char s[50];
	int n,flag;
	scanf("%d",&n);
	while(n--)
	{
		flag = 0;
		scanf("%s",s);
		int len = strlen(s);
		for( int i=0; i<len; i++ )
		{
			if( s[i]=='-' )
				continue;
			if(flag) printf(" ");
			if(!flag) flag = 1;
			printf("%c",s[i]);
		}
		printf("\n");
	}
	return 0;	
}

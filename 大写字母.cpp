#include <stdio.h>
#include<string.h>
int main()
{
	char s[1005];
	int num[26];
	int max = 0;	
	memset(num,0,sizeof(num));
	gets(s);
	for( int i=0; s[i]!='\0'; i++ )
	{
		if(s[i]<='z'&&s[i]>='a')
			s[i] -= 32;
		if(s[i]<='Z'&&s[i]>='A')
			num[ (int)(s[i]-65) ]++;
		if( max<num[ (int)(s[i]-65) ] )
			max = num[(int)(s[i]-65)];
	}
	if(max!=0) printf("%d:",max);
	for( int i=0; i<26; i++ )
	{
		if(num[i]==max)
			printf(" %c",char(i+65));
	}
	return 0;
}

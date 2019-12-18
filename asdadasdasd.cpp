#include <stdio.h>
#include <string.h>
int main()
{
    char num[81];
    int sum = 0;
    gets(num);
    for( int i=0; num[i]!='\0'; i++ )
    {
        int t = num[i]-'0';
        if( t>=0 && t<=9 )
        	sum = sum*10+t;
    }
    printf("%d\n",sum);
    return 0;
}

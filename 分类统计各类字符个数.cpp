#include <stdio.h>
#define MAXS 15

void StringCount( char *s );
void ReadString( char *s ); /* 由裁判实现，略去不表 */

int main()
{
    char s[MAXS];

    ReadString(s);
    StringCount(s);

    return 0;
}
void StringCount( char *s )
{
    int a=0,b=0,c=0,d=0,e=0;
    for( int i=0; s[i]!='\0'; i++ )
    {
        if( s[i]>='A' && s[i]<='Z' )
            a++;
        else if( s[i]>='a' && s[i]<='z' )
            b++;
        else if( s[i]==' ' )
            c++;
        else if( s[i]>='0' && s[i]<='9' )
            d++;
        else
            e++;
    }
    printf("%d %d %d %d %d\n",a,b,c,d,e);
}

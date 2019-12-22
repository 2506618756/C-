#include <stdio.h>
int main()
{
    char s[85];
    gets(s);
    for( int i=0; s[i]!='\0'; i++ )
    {
        if( s[i]>='A' && s[i]<='Z' )
            s[i] = 'A' + 'Z' - s[i];
    }
    puts(s);
    return 0;
}

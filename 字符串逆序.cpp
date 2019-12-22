#include <stdio.h>
#include <string.h>
int main()
{
    char s[80];
    gets(s);
    int num = strlen(s);
    for( int i=num-1; i>=0; i-- )
    {
        printf("%c",s[i]);
    }
    return 0;
}

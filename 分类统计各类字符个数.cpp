#include <stdio.h>
#define MAXS 15

void StringCount( char *s );
void ReadString( char *s ); /* �ɲ���ʵ�֣���ȥ���� */

int main()
{
    char s[MAXS];

    ReadString(s);
    StringCount(s);

    return 0;
}

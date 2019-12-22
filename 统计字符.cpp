#include <stdio.h>
int main()
{
    char s;
    int letter = 0, blank = 0, digit = 0, other = 0;
    for( int i=0; i<10; i++ )
    {
        s = getchar();
        if(s == ' ' || s == '\n')
		{
			blank++;
		}
		else if('0' <= s && s <= '9')
		{
			digit++;
		}
		else if('a' <= s && s <= 'z' || 'A' <= s && s <= 'Z')
		{
			letter++;
		}
		else
		{
			other++;
		}
    }
    printf("letter = %d, blank = %d, digit = %d, other = %d\n",letter,blank,digit,other);
    return 0;
}

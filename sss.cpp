#include <stdio.h>
int f(int x)
{  
	static int y=1;
    x+=y;  
    y++;
    return x;
}
int main(void)
{  
	int k;
    k=f(3);
    printf("%d %d\n",k,f(k));               //%d��%d֮��ֻ��1���ո�
    return 0;
}

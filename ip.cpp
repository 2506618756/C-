#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
struct node{
	char s[15];
	int x;
};
bool cmp( node a, node b ){ return a.x<b.x; }
int main()
{
	ios::sync_with_stdio(false);
	node x[25];
	int i=0;
	while( scanf("%s",x[i].s ) && strcmp(x[i].s,"#")!=0 )
	{
		x[i].x = strlen(x[i].s);
		i++;
	}
	sort(x,x+i,cmp);
	int flag=0;
	for( int k=0; k<i; k++ )
	{
//		if(flag) printf(" ");
//		else flag = 1;
		printf("%s ",x[k].s);
	}
	return 0;
}

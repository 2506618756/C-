#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<int> q;
	int x;
	int num;
	scanf("%d",&num);
	for( int i=0; i<num; i++ )
	{
		scanf("%d",&x);
		q.push_back(x);
	}
	list<int>::iterator p;
	int flag = 0;
	for( p=q.begin(); p!=q.end(); p++ )
	{
		if(flag) printf(" ");
		else flag++;
		printf("%d",*p);
	}
	return 0;
}

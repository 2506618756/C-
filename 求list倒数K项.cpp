#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<int> q;
	int x;
	int num;
	scanf("%d",&num);
	while( ~scanf("%d",&x) && x>=0 )
	{
		q.push_front(x);
	}
	list<int>::iterator p;
	int cnt=0;
	for( p=q.begin(); p!=q.end(); p++ )
	{
		printf("%d ",*p);
	}
	printf("\n");
	q.reverse();
	for( p=q.begin(); p!=q.end(); p++ )
	{
		printf("%d ",*p);
	}
	printf("\n");
	printf("NULL\n");
	return 0;
}

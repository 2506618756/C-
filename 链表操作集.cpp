#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef struct node *List; 
typedef struct node{
	int Data;
	List Next;
}sqlist;
List create()
{
	List now,L;
	L = NULL;
	int temp;
	while( scanf("%d",&temp) && temp!=-1 )
	{
		now = (List)malloc(sizeof(struct node));
		now->Data = temp;
		now->Next = L;
		L = now;
	}
	return L;
}
int main()
{
	List q;
	q = create();
	while( q!=NULL )
	{
		printf("%d ",q->Data);
		q = q->Next;
	}
	return 0;
}

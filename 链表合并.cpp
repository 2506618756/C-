#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    //Print(L1);
    //Print(L2);
    return 0;
}
List Read()
{
	int n,x;
	scanf("%d",&n); 
	List head,node,end;
	head = (List)malloc(sizeof(List));
	node = NULL;end = NULL;head->Next = NULL;
	end = head;
	for( int i=0; i<n; i++ )
	{
		node = (List)malloc(sizeof(List));
		scanf("%d",&node->Data);
		end->Next = node;
		end = node;
	}
	end->Next = NULL;
	return head;
}
void Print( List L )
{
	while( L->Next )
	{
		printf("%d ",L->Next->Data);
		L = L->Next;
	}
}
List Merge( List L1, List L2 )
{
	List L,head,p1,p2;
	p1 = L1->Next;
	p2 = L2->Next;
	head = (struct Node *)malloc(sizeof(struct Node));
	L = head;
	while( p1 && p2 )
	{
		if( p1->Data<p2->Data )
		{
			L->Next = p1;
			p1 = p1->Next;
		}
		else
		{
			L->Next = p2;
			p2 = p2->Next;
		}
		L = L->Next;
	}
		while(p1!=NULL)
		{
			L->Next = p1;
			p1 = p1->Next;
			L = L->Next;
			printf("ssssssss");
		}
		while(p2!=NULL)
		{
			L->Next = p2;
			p2 = p2->Next;
			L = L->Next;
			printf("ssssssss");		
		}
	L->Next = NULL;
	return head;
}

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *readlist();
struct ListNode *deletem( struct ListNode *L, int m );
void printlist( struct ListNode *L )
{
     struct ListNode *p = L;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    int m;
    struct ListNode *L = readlist();
    scanf("%d", &m);
    L = deletem(L, m);
    printlist(L);
    return 0;
}
struct ListNode *readlist()
{
	ListNode *p,*head,*tail;
	head = (struct ListNode *)malloc(sizeof(struct ListNode));
	tail = head = NULL;
	int x;
	while( ~scanf("%d",&x) && x!=-1 )
	{
		p = (struct ListNode *)malloc(sizeof(struct ListNode));
		p->data = x;
		if( tail==NULL )
			tail = head = p;
		else
		{
			tail->next = p;
			tail = p;
		}
	}
	tail->next = NULL;
	return head;
}
struct ListNode *deletem( struct ListNode *L, int m )
{
	struct ListNode *p = L,*t;
	while( p->data==m && p->next!=NULL )
	{
		L = L->next;
		free(p);
		p = L;
	}
	if( p->data==m )
		return NULL;
	t = L->next;
	while(t)
	{
		if(t->data==m)
		{
			p->next = t->next;
			free(t);
			t = p->next;
			continue; 
		}
		else
		{
			p = t;
			t = p->next;
		}
	}
	return L;
}

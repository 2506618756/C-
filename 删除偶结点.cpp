#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist();
struct ListNode *deleteeven( struct ListNode *head );
void printlist( struct ListNode *head )
{
     struct ListNode *p = head;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    struct ListNode *head;

    head = createlist();
    head = deleteeven(head);
    printlist(head);

    return 0;
}
struct ListNode *createlist()
{
	struct ListNode *head,*p,*node;
	head = (struct ListNode *)malloc(sizeof(struct ListNode));
	p = head;
	int x;
	while( ~scanf("%d",&x) && x!=-1 )
	{
		node = (struct ListNode *)malloc(sizeof(struct ListNode));
		node->data = x;
		node->next = NULL;
		p->next = node;
		p = node;
	}
	return head->next;
}
struct ListNode *deleteeven( struct ListNode *head )
{
	struct ListNode *t=NULL;
	struct ListNode *L=NULL;
	t = head;
	for( L=head; L!=NULL; L=L->next )
	{
		if( (L->data%2)==0 )
		{
			if(L==head)
			{
				head = head->next;
				free(L);
			}
			else
			{
				t->next = L->next;
				free(L);
			}
		}
		else
			t = L;
	}
	return head;
}

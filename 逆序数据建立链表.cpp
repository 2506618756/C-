#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist();

int main()
{
    struct ListNode *p, *head = NULL;

    head = createlist();
    for ( p = head; p != NULL; p = p->next )
        printf("%d ", p->data);
    printf("\n");

    return 0;
}
struct ListNode *createlist()
{
	struct ListNode *head,*p;
	head = NULL;
	int x;
	while( ~scanf("%d",&x) && x!=-1 )
	{
		p = (struct ListNode *)malloc(sizeof(struct ListNode));
		p->data = x;
		p->next = head;
		head = p;
	}
	return head;
}

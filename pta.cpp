#include <stdio.h>
#include <stdlib.h>
struct stud_node
{ 
	int num;
	char name[20];
	int score;
	struct stud_node *next; 
};
struct stud_node *createlist();
struct stud_node *deletelist( struct stud_node *head, int min_score );
int main()
{
	int min_score;
	struct stud_node *p, *head = NULL;
	head = createlist();
	scanf("%d", &min_score);
	head = deletelist(head, min_score);
	for ( p = head; p != NULL; p = p->next )
		printf("%d %s %d\n", p->num, p->name, p->score);
	return 0;
}
struct stud_node *createlist()
{
	int x;
	struct stud_node *p,*head,*tail;
	head = tail = NULL;
	p = head;
	while( ~scanf("%d",&x) && x!=0 )
	{
		p = (struct stud_node *)malloc(sizeof(struct stud_node));
		p->num = x;
		scanf("%s",p->name);
		scanf("%d",&p->score);
		if( head==NULL )
		{
			head = p;
		}
		else
		{
			tail = head;
			while(tail->next!=NULL)
			{
				tail = tail->next;
			}
			tail->next = p;
		}
		p->next = NULL;
	}
	return head;
}
struct stud_node *deletelist( struct stud_node *head, int min_score )
{
	if( head==NULL ) return NULL;
	struct stud_node *p=NULL,*t=NULL;
	for ( p = head; p->next != NULL; p = p->next )
	{
		if( p->score<min_score )
		{
			if( p==head )
			{
				head = head->next;
				free(p);
			}
			else
			{
				t->next = p->next;
				free(p);
			}
		}
		else
			t = p;	
	}
	return head;
}
//struct stud_node *deletelist( struct stud_node *head, int min_score )
//{
//struct stud_node *ptr=NULL,*ptr1=NULL;
//if(head==NULL) return NULL;
//for(ptr=head;ptr!=NULL;ptr=ptr->next)
//{
//	if(ptr->score<min_score)
//	{
//		if(ptr==head)
//		{
//			head=head->next;
//			free(ptr);
//		}
//		else
//		{
//			ptr1->next=ptr->next;
//			free(ptr);
//		}
//	}
//	else
//		ptr1=ptr;
//}
//return head;
//}

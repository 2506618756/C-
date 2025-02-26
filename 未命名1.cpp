#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stud_node {
     int    num;
     char   name[20];
     int    score;
     struct stud_node *next;
};
struct stud_node *head, *tail;

void input();

int main()
{
    struct stud_node *p;
	
    head = tail = NULL;
    input();
    for ( p = head; p != NULL; p = p->next )
        printf("%d %s %d\n", p->num, p->name, p->score);

    return 0;
}
void input()
{
	int x;
	struct stud_node *p;
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
}

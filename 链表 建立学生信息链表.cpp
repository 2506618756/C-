#include <stdio.h>
#include <stdlib.h>
struct stud_node {
     int    num;
     char   name[20];
     int    score;
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
#include <string.h>
struct stud_node *createlist()
{
int number,score;
char name[100];
struct stud_node *p=NULL,*head=NULL,*tail=NULL;
scanf("%d",&number);
while(number!=0)
{
scanf("%s %d",name,&score);
p=(struct stud_node *)malloc(sizeof(struct stud_node));
p->num=number;
p->score=score;
strcpy(p->name,name);
p->next=NULL;
if(head==NULL) head=p;
else tail->next=p;
tail=p;
scanf("%d",&number);
}
return head;
}
struct stud_node *deletelist( struct stud_node *head, int min_score )
{
struct stud_node *ptr=NULL,*ptr1=NULL,*ptr2=NULL;
if(head==NULL) return NULL;
for(ptr=head;ptr!=NULL;ptr=ptr->next)
{
if(ptr->score<min_score)
{
if(ptr==head)
{
head=head->next;
free(ptr);
}
else
{
ptr1->next=ptr->next;
free(ptr);
}
}
else
{
ptr1=ptr;
}
}
return head;
}

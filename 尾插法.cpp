#include <stdio.h>
#include <stdlib.h>//malloc函数

struct Node {    //链表结点
    int data;    //数据
    struct Node* link;    //指向下一个结点的指针
};

/* 尾插法建立单链表：返回单链表的头指针 */
struct Node* buildLinkedList(); /* 尾插法建立单链表 */
void printLinkedList(struct Node* head);       /* 打印链表 */

int main(int argc, char const *argv[]) {

    struct Node* head = NULL;	//声明一个指针变量head

    //创建链表，把返回的头指针赋值给head指针变量
    head = buildLinkedList();

    //打印链表：整个链表用head来代表。
    printLinkedList(head);

    return 0;
}
struct Node* buildLinkedList()
{
	struct Node *head,*tail,*p;
	head = NULL;
	int x;
	scanf("%d",&x);
	
	if( x!=-1 )
	{
		head = (struct Node *)malloc(sizeof(struct Node));
		head->data = x;
		tail = head;
	}
	while( ~scanf("%d",&x) && x!=-1 )
	{
		p = (struct Node *)malloc(sizeof(struct Node));
		p->data = x;
		tail->link = p;
		tail = p;
	}
	tail->link = NULL;
	return head;
}
void printLinkedList(struct Node* head)
{
	if(head==NULL)
		return ;
	int flag = 0;
	while(head)
	{
		if( (head->data)%2 && flag )
		{
			printf(" %d",head->data);
		}
		else if( (head->data)%2 && !flag )
		{
			printf("%d",head->data);
			flag++;
		}
		head = head->link;
	}
}

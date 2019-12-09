#include <stdio.h>
#include <stdlib.h>//malloc����

struct Node {    //������
    int data;    //����
    struct Node* link;    //ָ����һ������ָ��
};

/* β�巨�������������ص������ͷָ�� */
struct Node* buildLinkedList(); /* β�巨���������� */
void printLinkedList(struct Node* head);       /* ��ӡ���� */

int main(int argc, char const *argv[]) {

    struct Node* head = NULL;	//����һ��ָ�����head

    //���������ѷ��ص�ͷָ�븳ֵ��headָ�����
    head = buildLinkedList();

    //��ӡ��������������head������
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

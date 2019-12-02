#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#include <queue>
using namespace std;
typedef struct TNode *Bintree;
struct TNode
{
	int data;
	Bintree Left,Right;
};
Bintree CreateBintree()				//�������Ľ��� 
{
	int n;
	cout<<"�������������"<<endl;
	cin>>n;
	int array[n];
	cout<<"������������ֵ��"<<endl; 
	for( int i=0; i<n; i++ )
		cin>>array[i];
	Bintree tree,BT,p,t;
	if(n>0)
	{
		tree = (struct TNode *)malloc(sizeof(struct TNode));
		tree->data = array[0];
		tree->Left = tree->Right = NULL;
	}
	BT = tree;
	for( int i=1; i<n; i++ )
	{
		p = (struct TNode *)malloc(sizeof(struct TNode));
		p->data = array[i];
		p->Left = p->Right = NULL;
		tree = BT;
		while( tree )
		{
			t = tree;
			if( tree->data>array[i] )
				tree = tree->Left;
			else
				tree = tree->Right;
		}
		if( t->data>p->data )
			t->Left = p;
		else
			t->Right = p;
	}
	return BT;
}
void InorderTraversal(Bintree s)				//��������������� 
{
	if(s!=NULL)
	{
		InorderTraversal(s->Left);
		cout<<s->data<<" ";
		InorderTraversal(s->Right);
	}
}
void PreorderTraversal(Bintree s)				//��������������� 
{
	if(s!=NULL)
	{
		cout<<s->data<<" ";
		PreorderTraversal(s->Left);
		PreorderTraversal(s->Right);
	}
}
void PostorderTraversal(Bintree s)				//�������ĺ������ 
{
	if(s!=NULL)
	{
		PostorderTraversal(s->Left);
		PostorderTraversal(s->Right);
		cout<<s->data<<" ";
	}
}
void CengxuTraversal(Bintree s)					//�������Ĳ������ 
{
	if(s!=NULL)
	{
		queue<Bintree> q;
		Bintree t;
		t = s;
		q.push(t);
		while( !q.empty() )
		{
			t = q.front();
			q.pop();
			printf("%d ",t->data);
			if( t->Left )
				q.push(t->Left);
			if( t->Right )
				q.push(t->Right);
		}
	}
}
void PostorderPrintLeaves(Bintree s)				//��������Ҷ������ 
{
	if(s!=NULL)
	{
		if( !s->Left && !s->Right )
			cout<<s->data<<" ";
		PostorderTraversal(s->Left);
		PostorderTraversal(s->Right);
	}
}
void insert(Bintree s,int X)							//��������ֵ���� 
{
	Bintree t,p;
	p = (struct TNode *)malloc(sizeof(struct TNode));
	p->data = X;
	p->Left = p->Right = NULL;
	if(!s)
	{
		s = p;
		s->Left = s->Right = NULL;
	}
	else
	{
		while(s)
		{
			t = s;
			if( s->data>X)
				s = s->Left;
			else if(s->data<X)
				s = s->Right;
			else
			{
				cout<<"����ʧ�ܣ����ֵ "<<X<<" �Ѵ��ڣ�"<<endl<<endl;
				return ;
			}
		}
		if( t->data<X )
			t->Right = p;
		else if( t->data>X )
			t->Left = p;
		cout<<"��� "<<p->data<<" ����ɹ���"<<endl;
	}
	return ;
}
Bintree FindMin(Bintree s)				//���Ҷ���������Сֵ 
{
	if(!s)
	{
		cout<<"������Ϊ�գ�������Сֵʧ�ܣ�"<<endl;
		return 0;
	}
	while(s->Left)
		s = s->Left;
	return s;
}
Bintree FindMax(Bintree s)				//���Ҷ����������ֵ 
{
	if(!s)
	{
		cout<<"������Ϊ�գ��������ֵʧ�ܣ�"<<endl;
		return 0;
	}
	while(s->Right)
		s = s->Right;
	return s;
}
Bintree Delete(Bintree s,int x)				//ɾ����������� 
{
	Bintree temp;
	if(!s)
		cout<<"δ�ҵ�ɾ��Ԫ�أ�"<<endl;
	else
	{
		if( x<s->data )
			s->Left = Delete(s->Left,x);
		else if( x>s->data )
			s->Right = Delete(s->Right,x);
		else
		{
			if( s->Left && s->Right )
			{
				temp = FindMin(s->Right);
				s->data = temp->data;
				s->Right = Delete(s->Right,temp->data);
			}
			else
			{
				temp = s;
				printf("%d\n\n",temp->data);
				if( !s->Left )
					s = s->Right;
				else
					s = s->Left;
				free(temp);
			}
		}
	}
	return s;
}
Bintree Find(Bintree s,int X)				//���Ҷ������Ľ�� 
{
	while(s)
	{
		if(X>s->data)
			return Find(s->Left,X);
		else if(X<s->data)
			return Find(s->Right,X);
		else
			break;
	}
	return s;
}
int GetHeight(Bintree s)			//��������ĸ߶� 
{
	int HR,HL,MaxH;
	if(s)
	{
		HL = GetHeight(s->Left);
		HR = GetHeight(s->Right);
		MaxH = HR > HL ? HR : HL;
		return (MaxH+1);
	}
	else
		return 0;
}
void PrintTree(Bintree s, int nLayer)				//��ӡ���������� 
{
	if( s==NULL )
		return ;
	PrintTree( s->Right,  nLayer+1);
	for(int i=0;i<nLayer;i++)
	{
		printf("   ");
	}
	printf("%d\n",s->data);
	PrintTree( s->Left , nLayer+1 );
}
int main()
{
	int TreeHeight;
	Bintree tree,t;
	cout<<"                                        ������ɶ������Ľ���"<<endl;
	tree = CreateBintree();										//����������
	if( tree )
	{
		cout<<"�����������ɹ���"<<endl;
		cout<<"���Ե�Ƭ�̣����Ͻ���������棡"<<endl;
		Sleep(2*1000);
		system("cls");
		cout<<"                            ��������Ҫִ�еĲ���(1--8)��"<<endl;
	}
	else
	{
		cout<<"������Ϊ�գ�����ʧ�ܣ�"<<endl;
		return 0;	
	}
	while(1)
	{
		cout<<"0.�˳�����"<<endl<<endl;
		cout<<"1.����������������"<<endl<<endl;
		cout<<"2.����������������"<<endl<<endl;
		cout<<"3.����������������"<<endl<<endl;
		cout<<"4.����������������"<<endl<<endl;
		cout<<"5.��ӡ����������"<<endl<<endl;
		cout<<"6.����������߶�"<<endl<<endl;
		cout<<"7.������������ֵ"<<endl<<endl;
		cout<<"8.�����������Сֵ"<<endl<<endl;
		cout<<"9.������������"<<endl<<endl;
		cout<<"10.ɾ�����������"<<endl<<endl;
		int temp;
		cin>>temp;
		switch(temp)
		{
			case 0:return 0;
			case 1:
				cout<<"���������������㣺";
				InorderTraversal(tree);
				cout<<endl<<endl;
				break;
			case 2:
				cout<<"���������������㣺";
				PreorderTraversal(tree);
				cout<<endl<<endl;
				break;
			case 3: 
				cout<<"���������������㣺";
				PostorderTraversal(tree);
				cout<<endl<<endl;
				break;
			case 4: 
				cout<<"�����������������㣺";
				CengxuTraversal(tree);
				cout<<endl<<endl;
				break;
			case 5:
				cout<<"�����������δ�ӡ����: "<<endl;
				PrintTree(tree,1);
				cout<<endl<<endl;
				break;
			case 6:
				cout<<"�ö������ĸ߶�Ϊ��";
				cout<<GetHeight(tree);
				cout<<endl<<endl;
				break;
			case 7:
				cout<<"�ö����������ֵΪ��";
				t = FindMax(tree);
				cout<<t->data;
				cout<<endl<<endl;
				break;
			case 8:
				cout<<"�ö���������СֵΪ��";
				t = FindMin(tree);
				cout<<t->data;
				cout<<endl<<endl;
				break;
			case 9:
				cout<<"��������Ҫ�������ֵ��"<<endl;
				int x;cin>>x;
				insert(tree,x);
				break;
			case 10:
				cout<<"��������Ҫɾ������ֵ��"<<endl;
				int valuse;cin>>valuse;
				Delete(tree,valuse);
				break;
			default:
				cout<<"����ָ����󣬼�����������ָ�"<<endl;
				break;
		}
		Sleep(2*1000);
		cout<<"��������Ҫִ�еĲ���(1--8)��"<<endl;
	}
	return 0;
}
/*
8
5 6 8 7 4 2 3 1

		30
			41
		33		55
*/

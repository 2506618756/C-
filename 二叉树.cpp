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
Bintree CreateBintree()				//二叉树的建立 
{
	int n;
	cout<<"请输入结点个数："<<endl;
	cin>>n;
	int array[n];
	cout<<"请依次输入结点值："<<endl; 
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
void InorderTraversal(Bintree s)				//二叉树的中序遍历 
{
	if(s!=NULL)
	{
		InorderTraversal(s->Left);
		cout<<s->data<<" ";
		InorderTraversal(s->Right);
	}
}
void PreorderTraversal(Bintree s)				//二叉树的先序遍历 
{
	if(s!=NULL)
	{
		cout<<s->data<<" ";
		PreorderTraversal(s->Left);
		PreorderTraversal(s->Right);
	}
}
void PostorderTraversal(Bintree s)				//二叉树的后序遍历 
{
	if(s!=NULL)
	{
		PostorderTraversal(s->Left);
		PostorderTraversal(s->Right);
		cout<<s->data<<" ";
	}
}
void CengxuTraversal(Bintree s)					//二叉树的层序遍历 
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
void PostorderPrintLeaves(Bintree s)				//二叉树的叶结点输出 
{
	if(s!=NULL)
	{
		if( !s->Left && !s->Right )
			cout<<s->data<<" ";
		PostorderTraversal(s->Left);
		PostorderTraversal(s->Right);
	}
}
void insert(Bintree s,int X)							//二叉树的值插入 
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
				cout<<"插入失败，结点值 "<<X<<" 已存在！"<<endl<<endl;
				return ;
			}
		}
		if( t->data<X )
			t->Right = p;
		else if( t->data>X )
			t->Left = p;
		cout<<"结点 "<<p->data<<" 插入成功！"<<endl;
	}
	return ;
}
Bintree FindMin(Bintree s)				//查找二叉树的最小值 
{
	if(!s)
	{
		cout<<"二叉树为空，查找最小值失败！"<<endl;
		return 0;
	}
	while(s->Left)
		s = s->Left;
	return s;
}
Bintree FindMax(Bintree s)				//查找二叉树的最大值 
{
	if(!s)
	{
		cout<<"二叉树为空，查找最大值失败！"<<endl;
		return 0;
	}
	while(s->Right)
		s = s->Right;
	return s;
}
Bintree Delete(Bintree s,int x)				//删除二叉树结点 
{
	Bintree temp;
	if(!s)
		cout<<"未找到删除元素！"<<endl;
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
Bintree Find(Bintree s,int X)				//查找二叉树的结点 
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
int GetHeight(Bintree s)			//求二叉树的高度 
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
void PrintTree(Bintree s, int nLayer)				//打印二叉树树形 
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
	cout<<"                                        请先完成二叉树的建立"<<endl;
	tree = CreateBintree();										//创建二叉树
	if( tree )
	{
		cout<<"二叉树创建成功！"<<endl;
		cout<<"请稍等片刻，马上进入操作界面！"<<endl;
		Sleep(2*1000);
		system("cls");
		cout<<"                            请输入需要执行的操作(1--8)："<<endl;
	}
	else
	{
		cout<<"二叉树为空，创建失败！"<<endl;
		return 0;	
	}
	while(1)
	{
		cout<<"0.退出程序"<<endl<<endl;
		cout<<"1.中序输出二叉树结点"<<endl<<endl;
		cout<<"2.先序输出二叉树结点"<<endl<<endl;
		cout<<"3.后序输出二叉树结点"<<endl<<endl;
		cout<<"4.层序遍历二叉树结点"<<endl<<endl;
		cout<<"5.打印二叉树树形"<<endl<<endl;
		cout<<"6.输出二叉树高度"<<endl<<endl;
		cout<<"7.输出二叉树最大值"<<endl<<endl;
		cout<<"8.输出二叉树最小值"<<endl<<endl;
		cout<<"9.插入二叉树结点"<<endl<<endl;
		cout<<"10.删除二叉树结点"<<endl<<endl;
		int temp;
		cin>>temp;
		switch(temp)
		{
			case 0:return 0;
			case 1:
				cout<<"中序输出二叉树结点：";
				InorderTraversal(tree);
				cout<<endl<<endl;
				break;
			case 2:
				cout<<"先序输出二叉树结点：";
				PreorderTraversal(tree);
				cout<<endl<<endl;
				break;
			case 3: 
				cout<<"后序输出二叉树结点：";
				PostorderTraversal(tree);
				cout<<endl<<endl;
				break;
			case 4: 
				cout<<"层序序输出二叉树结点：";
				CengxuTraversal(tree);
				cout<<endl<<endl;
				break;
			case 5:
				cout<<"二叉树的树形打印如下: "<<endl;
				PrintTree(tree,1);
				cout<<endl<<endl;
				break;
			case 6:
				cout<<"该二叉树的高度为：";
				cout<<GetHeight(tree);
				cout<<endl<<endl;
				break;
			case 7:
				cout<<"该二叉树的最大值为：";
				t = FindMax(tree);
				cout<<t->data;
				cout<<endl<<endl;
				break;
			case 8:
				cout<<"该二叉树的最小值为：";
				t = FindMin(tree);
				cout<<t->data;
				cout<<endl<<endl;
				break;
			case 9:
				cout<<"请输入需要插入的数值："<<endl;
				int x;cin>>x;
				insert(tree,x);
				break;
			case 10:
				cout<<"请输入需要删除的数值："<<endl;
				int valuse;cin>>valuse;
				Delete(tree,valuse);
				break;
			default:
				cout<<"输入指令错误，即将重新输入指令！"<<endl;
				break;
		}
		Sleep(2*1000);
		cout<<"请输入需要执行的操作(1--8)："<<endl;
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

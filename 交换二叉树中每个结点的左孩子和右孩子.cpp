#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};
string str;
int len,idx;

void CreatBinTree(BinTree &BST)
{
	if(str[idx]=='#'||idx==len) return;
	BST  = (BinTree)malloc(sizeof(struct TNode));
	BST->Data = str[idx];
	BST->Left = BST->Right = NULL;
	idx++;
	CreatBinTree(BST->Left);
	idx++;
	CreatBinTree(BST->Right);
	return ;
}
void exchange(BinTree &BST)
{
	if( !BST->Left && !BST->Right ) return ;
	BinTree temp;
	temp = BST->Left;
	BST->Left = BST->Right;
	BST->Right = temp;
	if( BST->Left )
		exchange(BST->Left);
	if( BST->Right )
		exchange(BST->Right);
}
void zxprint(BinTree BST)
{
	if(BST!=NULL)
	{
		zxprint(BST->Left);
		cout<<BST->Data;
		zxprint(BST->Right);
	}
}

int main()
{
    BinTree BT=NULL;
    cin>>str;
    len = str.length();
    idx = 0;
	CreatBinTree(BT);
    zxprint(BT);
    cout<<endl;
    exchange(BT);
    zxprint(BT);
    return 0;
}

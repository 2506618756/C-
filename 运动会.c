#include <stdio.h>
#include <math.h>
#define SCHOOLMAX 20
#define BOYMAX 20
#define GIRLMAX 20
typedef struct 
{
	int itemnumber;
	int top;
	int rank[5];
	int sorce[5];
}itemnews;
typedef struct
{
	int schoolnum;
	int sum;
	int boymark;
	int girlmark;
	itemnews project[BOYMAX+GIRLMAX];
}schoolnode;
schoolnode snum[SCHOOLMAX];
void function(int n,int x,int y)
{
	void function(int n,int x,int y);
	void input(int n,int x,int y);
	void output(int n,int x,int y);
	void sortput(int n,int x,int y);
	void search(int n,int x,int y);	 
	int k;
	printf("************************************************\n\n\n");
	printf("\t**********内蒙古大运会分数统计系统**********\n\n");
	printf("\t\t******1.信息录入******\n");
	printf("\t\t******2.计算输出******\n");
	printf("\t\t******3.排序输出******\n");
	printf("\t\t******4.信息查询******\n");
	printf("\t\t******5.退出系统******\n\n\n");
	printf("************************************************\n\n\n");
	printf("请输出需要执行的操作编号(0--4)：");
	scanf("%d",&k);
	switch(k)
	{
		case 1:input(n,x,y);break;
		case 2:output(n,x,y);break;
		case 3:sortput(n,x,y);break;
		case 4:search(n,x,y);break;
		case 5:printf("操作结束，感谢使用！\n");break;
		default:printf("编号输入错误，请重试！\n");function(n,x,y);
	}
}
void input(int n,int x,int y)
{
	int i,j,k,q,s;
	for( i=0; i<n; i++ )
	{
		printf("学校编号：");
		scanf("%d",&snum[i].schoolnum);
		for( j=0; j<x+y; j++)
		{
			printf("项目编号：");
			scanf("%d",&snum[i].project[j].itemnumber);
			printf("项目取前3名或前5：");
			scanf("%d",&snum[i].project[j].top);
			if( snum[i].project[j].top==3 )
				printf("项目获得名次个数为(1---3)：");
			else
				printf("项目获得名次个数为(1---5)："); 		
			scanf("%d",&k);
			for( s=0; s<k; s++ )
			{
				if( snum[i].project[j].top==3 )
					printf("所获名次(1--3):");
				else
					printf("所获名次(1--5):");
				scanf("%d",&snum[i].project[j].rank[s]);
			}
			printf("\n");
		}
	}
	for( i=0; i<n; i++ )
	{
		snum[i].sum = 0;
		snum[i].boymark = 0;
		snum[i].girlmark = 0;
	}
	for( i=0; i<n; i++ )
		for( j=0; j<x+y; j++ )
			for( s=0; s<5; s++ )
			{
				if( snum[i].project[j].top==3 )
					switch( snum[i].project[j].rank[s] )
					{
						case 0:snum[i].project[j].sorce[s] = 0;break;
						case 1:snum[i].project[j].sorce[s] = 5;break;
						case 2:snum[i].project[j].sorce[s] = 3;break;
						case 3:snum[i].project[j].sorce[s] = 2;break;
					}
				else if( snum[i].project[j].top==5 )
					switch( snum[i].project[j].rank[s] )
					{
						case 0:snum[i].project[j].sorce[s] = 0;break;
						case 1:snum[i].project[j].sorce[s] = 7;break;
						case 2:snum[i].project[j].sorce[s] = 5;break;
						case 3:snum[i].project[j].sorce[s] = 3;break;
						case 4:snum[i].project[j].sorce[s] = 2;break;
						case 5:snum[i].project[j].sorce[s] = 1;break;
					}
				else
				{
					printf("输入的信息发生错误！\n");
					break;
				}
				snum[i].sum += snum[i].project[j].sorce[s];
				if( j<=x-1 )
					snum[i].boymark  += snum[i].project[j].sorce[s];
				else
					snum[i].girlmark += snum[i].project[j].sorce[s];
			}
			printf("输入成功！返回？ 1 是 2 否\n");
			scanf("%d",&q);
			printf("\n");
			if(q!=1)
				printf("信息已满！");
			printf("\n");
			function(n,x,y);
}
void output( int n, int x,int y)
{
	int i,j,s,q;
	for( i=0; i<n; i++ )
	{
		printf("学 校 编 号：%d    学 校 总 分：%d    男 团 总 分：%d    女 团 总 分：%d\n",snum[i].schoolnum,snum[i].sum,snum[i].boymark,snum[i].girlmark);
		for( j=0; j<x+y; j++ )
		{
			printf("项目编号：%d  所获取名次数量：%d\n",snum[i].project[j].itemnumber,snum[i].project[j].top);
			for( s=0; s<5; s++ )
			{
				if( snum[i].project[j].rank[s]!=0 )
				printf("名次：%d   分数：%d\n",snum[i].project[j].rank[s],snum[i].project[j].sorce[s]);
			}
		}
		printf("\n");
	}
	printf("\n");
	printf("统计完毕！返回？ 1 是 2 否");
	printf("\n");
	scanf("%d",&q);
	printf("\n");
	if(q!=1)
		printf("统计已经结束");
	printf("\n");
	function(n,x,y);
}
void sortput(int n,int x,int y)
{
	int q=0,t,i,j;
	int temp[SCHOOLMAX];
	printf("************************************************\n\n\n");
	printf("\t\t******1.按学校编号输出******\n");
	printf("\t\t******2.按学校总分输出******\n");
	printf("\t\t******3.按男生总分输出******\n");
	printf("\t\t******4.按女生总分输出******\n");
	printf("************************************************\n\n\n");
	do
	{
		printf("请选择实现功能的编号(1--4)：");
		scanf("%d",&t);
		switch(t)
		{
			case 1:
				for( i=0; i<n; i++ )
					temp[i] = i;
				for( i=0; i<n; i++ )
				{
					for( j=i+1; j<n; j++ )
						if( snum[temp[i]].schoolnum<snum[j].schoolnum )
						{
							int k = temp[i];
							temp[i] = temp[j];
							temp[j] = k;
						}
				}
				for( i=0; i<n; i++ )
				{
					printf("学校编号：%d   学校总分：%d   男团总分：%d   女团总分：%d\n",snum[temp[i]].schoolnum,snum[temp[i]].sum,snum[temp[i]].boymark,snum[temp[i]].girlmark);
				}
				break;	
			case 2:
				for( i=0; i<n; i++ )
				temp[i] = i;
				for( i=0; i<n; i++ )
				{
					for( j=i+1; j<n; j++ )
						if( snum[temp[i]].sum<snum[j].sum )
						{
							int k = temp[i];
							temp[i] = temp[j];
							temp[j] = k;
						}
				}
				for( i=0; i<n; i++ )
				{
					printf("学校编号：%d   学校总分：%d   男团总分：%d   女团总分：%d\n",snum[temp[i]].schoolnum,snum[temp[i]].sum,snum[temp[i]].boymark,snum[temp[i]].girlmark);
				}
				break;
			case 3:
				for( i=0; i<n; i++ )
				temp[i] = i;
				for( i=0; i<n; i++ )
				{
					for( j=i+1; j<n; j++ )
						if( snum[temp[i]].boymark<snum[j].boymark )
						{
							int k = temp[i];
							temp[i] = temp[j];
							temp[j] = k;
						}
				}
				for( i=0; i<n; i++ )
				{
					printf("学校编号：%d   学校总分：%d   男团总分：%d   女团总分：%d\n",snum[temp[i]].schoolnum,snum[temp[i]].sum,snum[temp[i]].boymark,snum[temp[i]].girlmark);
				}
				break;
			case 4:
				for( i=0; i<n; i++ )
				temp[i] = i;
				for( i=0; i<n; i++ )
				{
					for( j=i+1; j<n; j++ )
						if( snum[temp[i]].girlmark<snum[j].girlmark )
						{
							int k = temp[i];
							temp[i] = temp[j];
							temp[j] = k;
						}
				}
				for( i=0; i<n; i++ )
				{
					printf("学校编号：%d   学校总分：%d   男团总分：%d   女团总分：%d\n",snum[temp[i]].schoolnum,snum[temp[i]].sum,snum[temp[i]].boymark,snum[temp[i]].girlmark);
				}
				break;
			default:
				printf("输入的信息有误，请重试！\n");
		}
		printf("请选择   1 返回主菜单 0 继续");
		scanf("%d",&q);
		printf("\n");
	}
	while(q==0);
	printf("\n");
	if(q!=0)
		function(n,x,y);
}
void search(int n,int x, int y)
{
	int i,j,k,d,p,t,q;
	printf("************************************************\n\n\n");
	printf("\t\t********查询系统********\n");
	printf("\t\t******1.按学校编号查询******\n");
	printf("\t\t******2.按项目编号查询******\n");
	printf("************************************************\n\n\n");
	do
	{
		k=-1;d=-1;p=-1;
		printf("请选择要实现功能的编号(1--2)：");
		scanf("%d",&t);
		switch(t)
		{
			case 1:
				printf("要查询的学校编号：");
				scanf("%d",&t);
				for( i=0; i<n; i++ )
				{
					if( snum[i].schoolnum==t )
						k = i;
				}
				if( k==-1 )
					printf("错误信息：此学校并未参加此次的运动会！\n");
				else
				{
					printf("要查询的项目编号：");
					scanf("%d",&t);
					for( j=0; j<x+y; j++ )
					{
						if( snum[k].project[j].itemnumber==t )
							d = j;
					}
					if( d==-1 )
						printf("此次运动会没有这个项目\n");
					else
					{
						printf("这个项目取前%d名，该学校的成绩如下：\n",snum[k].project[d].top);
						for( i=0; i<5; i++ )
							printf("名次：%d\n",snum[k].project[d].rank[i]);
					}
				}
				break;
			case 2:
				printf("要查询的项目编号：");
				scanf("%d",&t);
				for( i=0; i<n; i++ )
					for( j=0; j<x+y; j++ )
						if( snum[i].project[j].itemnumber==t )
							p = j;
				if( p==-1 )
					printf("错误信息：此次运动会没有这个项目！\n");
				else
				{
					printf("要查询的项目编号：");
						printf("这个项目取前%d名，取得名次的学校：\n",snum[0].project[p].top);
						for( i=0; i<n; i++ )
							for( j=0; j<5; j++ )
								if( snum[i].project[p].rank[j]!=0 )
					printf("学校编号：%d，名次：%d\n",snum[i].schoolnum,snum[i].project[p].rank[j]);
				}
				break;
			default:
				printf("信息输入错误，请重试！\n");
		}
		printf("请选择：1 返回主菜单 0 继续");
		scanf("%d",&q);
		printf("\n");
	}while(q==0);
	printf("\n");
	if(q!=0)
		function(n,x,y);	
}
int main()
{
	int n,w,m;
	printf("\t\t\t  欢迎使用\t\t\t\t\n\n");
	printf("\t***********内蒙古大运会分数统计系统***********\n\n");
	printf("请输入运动会的相关信息：\n");
	printf("请输入学校个数：");
	scanf("%d",&n);
	printf("请输入男子项目个数：");
	scanf("%d",&m);
	printf("请输入女子项目个数：");
	scanf("%d",&w);
	function(n,m,w);
	return 0;
}

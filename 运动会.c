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
	printf("\t**********���ɹŴ��˻����ͳ��ϵͳ**********\n\n");
	printf("\t\t******1.��Ϣ¼��******\n");
	printf("\t\t******2.�������******\n");
	printf("\t\t******3.�������******\n");
	printf("\t\t******4.��Ϣ��ѯ******\n");
	printf("\t\t******5.�˳�ϵͳ******\n\n\n");
	printf("************************************************\n\n\n");
	printf("�������Ҫִ�еĲ������(0--4)��");
	scanf("%d",&k);
	switch(k)
	{
		case 1:input(n,x,y);break;
		case 2:output(n,x,y);break;
		case 3:sortput(n,x,y);break;
		case 4:search(n,x,y);break;
		case 5:printf("������������лʹ�ã�\n");break;
		default:printf("���������������ԣ�\n");function(n,x,y);
	}
}
void input(int n,int x,int y)
{
	int i,j,k,q,s;
	for( i=0; i<n; i++ )
	{
		printf("ѧУ��ţ�");
		scanf("%d",&snum[i].schoolnum);
		for( j=0; j<x+y; j++)
		{
			printf("��Ŀ��ţ�");
			scanf("%d",&snum[i].project[j].itemnumber);
			printf("��Ŀȡǰ3����ǰ5��");
			scanf("%d",&snum[i].project[j].top);
			if( snum[i].project[j].top==3 )
				printf("��Ŀ������θ���Ϊ(1---3)��");
			else
				printf("��Ŀ������θ���Ϊ(1---5)��"); 		
			scanf("%d",&k);
			for( s=0; s<k; s++ )
			{
				if( snum[i].project[j].top==3 )
					printf("��������(1--3):");
				else
					printf("��������(1--5):");
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
					printf("�������Ϣ��������\n");
					break;
				}
				snum[i].sum += snum[i].project[j].sorce[s];
				if( j<=x-1 )
					snum[i].boymark  += snum[i].project[j].sorce[s];
				else
					snum[i].girlmark += snum[i].project[j].sorce[s];
			}
			printf("����ɹ������أ� 1 �� 2 ��\n");
			scanf("%d",&q);
			printf("\n");
			if(q!=1)
				printf("��Ϣ������");
			printf("\n");
			function(n,x,y);
}
void output( int n, int x,int y)
{
	int i,j,s,q;
	for( i=0; i<n; i++ )
	{
		printf("ѧ У �� �ţ�%d    ѧ У �� �֣�%d    �� �� �� �֣�%d    Ů �� �� �֣�%d\n",snum[i].schoolnum,snum[i].sum,snum[i].boymark,snum[i].girlmark);
		for( j=0; j<x+y; j++ )
		{
			printf("��Ŀ��ţ�%d  ����ȡ����������%d\n",snum[i].project[j].itemnumber,snum[i].project[j].top);
			for( s=0; s<5; s++ )
			{
				if( snum[i].project[j].rank[s]!=0 )
				printf("���Σ�%d   ������%d\n",snum[i].project[j].rank[s],snum[i].project[j].sorce[s]);
			}
		}
		printf("\n");
	}
	printf("\n");
	printf("ͳ����ϣ����أ� 1 �� 2 ��");
	printf("\n");
	scanf("%d",&q);
	printf("\n");
	if(q!=1)
		printf("ͳ���Ѿ�����");
	printf("\n");
	function(n,x,y);
}
void sortput(int n,int x,int y)
{
	int q=0,t,i,j;
	int temp[SCHOOLMAX];
	printf("************************************************\n\n\n");
	printf("\t\t******1.��ѧУ������******\n");
	printf("\t\t******2.��ѧУ�ܷ����******\n");
	printf("\t\t******3.�������ܷ����******\n");
	printf("\t\t******4.��Ů���ܷ����******\n");
	printf("************************************************\n\n\n");
	do
	{
		printf("��ѡ��ʵ�ֹ��ܵı��(1--4)��");
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
					printf("ѧУ��ţ�%d   ѧУ�ܷ֣�%d   �����ܷ֣�%d   Ů���ܷ֣�%d\n",snum[temp[i]].schoolnum,snum[temp[i]].sum,snum[temp[i]].boymark,snum[temp[i]].girlmark);
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
					printf("ѧУ��ţ�%d   ѧУ�ܷ֣�%d   �����ܷ֣�%d   Ů���ܷ֣�%d\n",snum[temp[i]].schoolnum,snum[temp[i]].sum,snum[temp[i]].boymark,snum[temp[i]].girlmark);
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
					printf("ѧУ��ţ�%d   ѧУ�ܷ֣�%d   �����ܷ֣�%d   Ů���ܷ֣�%d\n",snum[temp[i]].schoolnum,snum[temp[i]].sum,snum[temp[i]].boymark,snum[temp[i]].girlmark);
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
					printf("ѧУ��ţ�%d   ѧУ�ܷ֣�%d   �����ܷ֣�%d   Ů���ܷ֣�%d\n",snum[temp[i]].schoolnum,snum[temp[i]].sum,snum[temp[i]].boymark,snum[temp[i]].girlmark);
				}
				break;
			default:
				printf("�������Ϣ���������ԣ�\n");
		}
		printf("��ѡ��   1 �������˵� 0 ����");
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
	printf("\t\t********��ѯϵͳ********\n");
	printf("\t\t******1.��ѧУ��Ų�ѯ******\n");
	printf("\t\t******2.����Ŀ��Ų�ѯ******\n");
	printf("************************************************\n\n\n");
	do
	{
		k=-1;d=-1;p=-1;
		printf("��ѡ��Ҫʵ�ֹ��ܵı��(1--2)��");
		scanf("%d",&t);
		switch(t)
		{
			case 1:
				printf("Ҫ��ѯ��ѧУ��ţ�");
				scanf("%d",&t);
				for( i=0; i<n; i++ )
				{
					if( snum[i].schoolnum==t )
						k = i;
				}
				if( k==-1 )
					printf("������Ϣ����ѧУ��δ�μӴ˴ε��˶��ᣡ\n");
				else
				{
					printf("Ҫ��ѯ����Ŀ��ţ�");
					scanf("%d",&t);
					for( j=0; j<x+y; j++ )
					{
						if( snum[k].project[j].itemnumber==t )
							d = j;
					}
					if( d==-1 )
						printf("�˴��˶���û�������Ŀ\n");
					else
					{
						printf("�����Ŀȡǰ%d������ѧУ�ĳɼ����£�\n",snum[k].project[d].top);
						for( i=0; i<5; i++ )
							printf("���Σ�%d\n",snum[k].project[d].rank[i]);
					}
				}
				break;
			case 2:
				printf("Ҫ��ѯ����Ŀ��ţ�");
				scanf("%d",&t);
				for( i=0; i<n; i++ )
					for( j=0; j<x+y; j++ )
						if( snum[i].project[j].itemnumber==t )
							p = j;
				if( p==-1 )
					printf("������Ϣ���˴��˶���û�������Ŀ��\n");
				else
				{
					printf("Ҫ��ѯ����Ŀ��ţ�");
						printf("�����Ŀȡǰ%d����ȡ�����ε�ѧУ��\n",snum[0].project[p].top);
						for( i=0; i<n; i++ )
							for( j=0; j<5; j++ )
								if( snum[i].project[p].rank[j]!=0 )
					printf("ѧУ��ţ�%d�����Σ�%d\n",snum[i].schoolnum,snum[i].project[p].rank[j]);
				}
				break;
			default:
				printf("��Ϣ������������ԣ�\n");
		}
		printf("��ѡ��1 �������˵� 0 ����");
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
	printf("\t\t\t  ��ӭʹ��\t\t\t\t\n\n");
	printf("\t***********���ɹŴ��˻����ͳ��ϵͳ***********\n\n");
	printf("�������˶���������Ϣ��\n");
	printf("������ѧУ������");
	scanf("%d",&n);
	printf("������������Ŀ������");
	scanf("%d",&m);
	printf("������Ů����Ŀ������");
	scanf("%d",&w);
	function(n,m,w);
	return 0;
}

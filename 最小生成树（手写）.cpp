#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define MAX 65535
int map[1005][1005];
int n,m,ct1,ct2,price;
int prim()
{
    int min;
    int i,j,k;
    int lowcost[1005];
    int cost =0;
    lowcost[1] = 0;   //初始化第一个权值为0,即v0加入生成树
    for( i=2; i<=n; i++)
    {
        lowcost[i] = map[1][i];
    }
    for( i=2; i<=n; i++)
    {
        min = MAX;
        j = 1;
        k = 0;
        while( j<=n )
        {
            if( lowcost[j]!=0 && lowcost[j]<min)
            {
                min = lowcost[j];
                k = j;   //将当前最小值的下标存入k
            }
            j++;
        }
        if(k==0)
        {
            return -1;  //不连通
        }
        cost += min;
        lowcost[k] = 0;   //将当前顶点设置为0，表示此结点已经完成任务
        for( j=2; j<=n; j++)
        {
            if( lowcost[j]!=0 && map[k][j]<lowcost[j])
            {
                //若下标为k顶点各边权值小于此前这些顶点未被加入生成树的权值
                lowcost[j] = map[k][j];
            }
        }
    }
    return cost;	
}
int main()
{
	scanf("%d %d",&n,&m);
	for( int i=1; i<=n; i++ )
		for( int j=1; j<=n; j++ )
			map[i][j] = MAX;
	for( int i=0; i<m; i++ )
	{
		scanf("%d %d %d",&ct1,&ct2,&price);
		map[ct1][ct2] = map[ct2][ct1] = price;
	}
	int f = prim();
	printf("%d\n",f);
	return 0;	
}
/*
测试数据：
6 15
1 2 5
1 3 3
1 4 7
1 5 4
1 6 2
2 3 4
2 4 6
2 5 2
2 6 6
3 4 6
3 5 1
3 6 1
4 5 10
4 6 8
5 6 3
*/

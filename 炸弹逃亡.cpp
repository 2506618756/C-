#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n,m,startx,starty;
int temp[10][10];
int visted[10][10]; 
int dir[4][2] = {1,0,-1,0,0,1,0,-1};
struct node{
	int x,y,time,step;
};
int bfs()
{
	node now;	now.x = startx;now.y = starty;now.time = 6;now.step = 0;
	queue<node> q;	q.push(now);
	while( !q.empty() )
	{
		now = q.front();	q.pop();
		for( int i=0; i<4; i++ )
		{
			node next;	next.x = now.x + dir[i][0];	 next.y = now.y + dir[i][1];
			if( next.x>=0 && next.x<n && next.y>=0 && next.y<m && temp[next.x][next.y]!=0 &&visted[next.x][next.y]==0 )
			{
				next.time = now.time - 1;
				next.step = now.step + 1;
				if( next.time == 0 )
				{
					visted[next.x][next.y]=1;
					continue;
				}
				if( temp[next.x][next.y]==3 )
					return next.step;
				if( temp[next.x][next.y]==4 )
					next.time = 6;
				q.push(next);
			}
		}
	}
	return -1;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(visted,0,sizeof(visted));
		scanf("%d%d",&n,&m);
		for( int i=0; i<n; i++ )
			for( int j=0; j<m; j++ )
			{
				scanf("%d",&temp[i][j]);
				if( temp[i][j]==2 )
				{
					startx = i;starty = j;
					//temp[i][j] = 0;
				}
			}
		int time = bfs();
		printf("%d\n",time);
	}
	return 0;
}

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
using namespace std;
int dir[6][3]={0,1,0,1,0,0,0,-1,0,-1,0,0,0,0,1,0,0,-1};
int temp[50][50][50];
struct node{
 int x,y,z,step;
}; 
int bfs(int A,int B,int C,int time)
{
 queue<node> q;node now,next;
 now.x = now.y = now.z = now.step = 0;
 q.push(now);
 temp[0][0][0] = 1;
 while( !q.empty() )
 {
  now = q.front();
  q.pop();
	if(now.x==A-1 && now.y==B-1 && now.z==C-1) return now.step;
	if( now.step>time )
		return -1;
  for( int i=0; i<6; i++ )
  {
   next.x = now.x + dir[i][0];
   next.y = now.y + dir[i][1];
   next.z = now.z + dir[i][2];
   if( next.x>=0 && next.x<A && next.y>=0 && next.y<B && next.z>=0 && next.z<C && temp[next.x][next.y][next.z]!=1 )
   {
   		next.step = now.step + 1;
   		q.push(next);
   		temp[next.x][next.y][next.z]==1;
   }
  }
 }
 return -1;
}
int main()
{
 int T;
 int A,B,C;
 scanf("%d",&T);
 int time;
 while(T--)
 {
  scanf("%d%d%d%d",&A,&B,&C,&time);
  for( int i=0; i<A; i++ )
   for( int j=0; j<B; j++ )
    for( int k=0; k<C; k++ )
     scanf("%d",&temp[i][j][k]);
     if( temp[A-1][B-1][C-1]==1 )
     {
     	printf("-1\n");
	 }
	 else
	 {
	 	 int step = bfs(A,B,C,time);
 	 	if(step == -1)
  		 	printf("-1\n");
 		 else
   			printf("%d\n",step); 	
	 }
 }
 return 0;
}

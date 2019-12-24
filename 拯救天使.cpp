#include <iostream>
#include <queue>
#include <string.h>
#include <stdio.h>
using namespace std;
int n,m,x,y; 
char temp[210][210];
int dir[4][2] = {1,0,-1,0,0,1,0,-1}; 
struct node{
 int x,y;
 int cnt;
};
int bfs()
{
    queue <node> q;
    node now;
     now.cnt=0;
     now.x = x;
     now.y = y;
     q.push(now);
     temp[x][y] = '#';
     while( !q.empty() ){
  now = q.front();
  q.pop();
  for( int i=0; i<4; i++ )
  {
    node next;
   next.x = now.x + dir[i][0];
   next.y = now.y + dir[i][1];
   next.cnt = now.cnt + 1;
   if( next.x<0 || next.x>=n || next.y<0 || next.y>=m || temp[next.x][next.y]=='#')
        continue;
    if( temp[next.x][next.y]=='r')
        return next.cnt;        
    if( temp[next.x][next.y]=='x'){
        next.cnt++;
    }
    temp[next.x][next.y] = '#';
    q.push(next);
    }
 }
 return -1;
}
int main()
{
    int k;
    while( scanf("%d %d",&n,&m)!=EOF )
    {
        for( int i=0; i<n; i++ )
        {
            for( int j=0; j<m; j++ )
            {
                cin>>temp[i][j];
                if(temp[i][j]=='a')
                {
                    x = i;y = j;
                }
            }
        }
        int time = bfs();
          if(time==-1)
              printf("Poor ANGEL has to stay in the prison all his life.\n");
        else
            printf("%d\n",time);            
    }    
 return 0;
}

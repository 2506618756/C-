#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
int A,B,C,T;
int str[55][55][55];
int dir[6][3]={0,1,0,1,0,0,0,-1,0,-1,0,0,0,0,1,0,0,-1};
struct node
{
    int x,y,z;int time;
};
int bfs()
{
        queue<node>q;node now,next;
        now.x=0,now.y=0,now.z=0,now.time=0;q.push(now);
        while(!q.empty())
        {
            now=q.front();q.pop();
            if(now.x==B-1&&now.y==C-1&&now.z==A-1)return now.time;
            for(int i=0;i<6;i++)
            {
                next.x=now.x+dir[i][0];
                next.y=now.y+dir[i][1];
                next.z=now.z+dir[i][2];
                if(!str[next.z][next.x][next.y]&&next.z>=0&&next.z<A&&next.x<B&&next.x>=0&&next.y>=0&&next.y<C)
                {
                    next.time=now.time+1;
                    str[next.z][next.x][next.y]=1;
                    q.push(next);
                }
            }
        }
    return -1;
}
int main()
{
    int t;cin>>t;while(t--)
    {
        scanf("%d%d%d%d",&A,&B,&C,&T);
        for(int i=0;i<A;i++)
        {
            for(int j=0;j<B;j++)
            {
                for(int k=0;k<C;k++)
                {
                    scanf("%d",&str[i][j][k]);
                }
            }
        }int ans=bfs();
        if(ans>T)printf("-1\n");else printf("%d\n",ans);
    }
}

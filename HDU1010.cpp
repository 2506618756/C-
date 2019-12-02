#include <iostream>
#include <cstring>
#include <cmath>
#include <stdio.h>
using namespace std;
char temp[15][15];
int n,m,t,startx,starty,endx,endy,flag;
void dfs( int x, int y ,int time)
{
    if (temp[x][y] == 'D')
    {
        if (time == 0)
            flag = 1;
        return;
    }
    if (x < 0 || y < 0 || x >= m || y >= n || temp[x][y] == 'X' || flag )
        return;
    temp[x][y] = 'X';
    dfs (x + 1, y, time - 1);
    dfs (x, y + 1, time - 1);
    dfs (x - 1, y, time - 1);
    dfs (x, y - 1, time - 1);
    temp[x][y] = '.';
}
int main()
{
    while( ~scanf("%d%d%d",&n,&m,&t) )
    {
        int cnt=0;flag = 0;
        if( n==0 && m==0 && t==0 )
            break;
        for( int i=0; i<n; i++ )
            for( int j=0; j<m; j++ )
            {
                cin>>temp[j][i];
                if( temp[j][i]=='S' )
                {
                    startx = j;starty = i;
                }
                if( temp[j][i]=='.' )
                    cnt++;
                if( temp[j][i]=='D' )
                {
                    endx = j;endy = i;
                }
            }
        int num = endx + endy - startx - starty - t    ;    
        if( cnt+1>= t && num%2==0 )
            dfs(startx,starty,t);
        if( flag )
            printf("YES\n");
        else
            printf("NO\n");
            
    }
    return 0;
}

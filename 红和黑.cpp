#include <iostream>
using namespace std;
int visted[25][25];
int s[25][25];
int n,m,sx,sy,ans;
int main()
{
	int n;
	while(scanf("%d%d",&m,&n) != EOF && (m||n))
	{
		memset(visted,0,sizeof(visted));
		int i,j;
		char ch;
		for(i=0 ;i<n ;i++)
		{
			for(j=0 ;j<m ;j++)
			{
				vis[i][j] = 0;
				cin >> ch;
				if(ch == '.')
				{
					maze[i][j] = 1;
				}
				else if(ch == '#')
				{
					maze[i][j] = 0;
				}
				else
				{
					sx = i;
					sy = j;
					maze[i][j] = 1;
				}
			}
		}
	}
	return 0;
}

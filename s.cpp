#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring> 
#include <string>
using namespace std;
struct node{
	int num,id;
	bool friend operator < (node a,node b)
	{
		if( a.num!=b.num)
			return a.num<b.num;
		else
			return a.id>b.id;
	}
};
int main()
{
	ios::sync_with_stdio(false);
	int n,k,num;
	node t;
	while( ~scanf("%d",&n) )
	{
		int cnt = 0;
		string s;
		priority_queue<node> q[4];
		while(n--)
		{
			cin>>s;
			if(s=="IN")
			{
				cin>>num>>k;
				t.num = num; t.id = ++cnt;
				q[k].push(t);
			}
			else
			{
				cin>>num;
				if(!q[num].empty())
				{
					t = q[num].top();
					q[num].pop();
					printf("%d\n",t.id);
				}
				else
					printf("EMPTY\n");
			}
		}
	}
	return 0;
}

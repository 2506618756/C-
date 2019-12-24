#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring> 
#include <string>
using namespace std;
struct node{
    int num,id;
    bool friend operator < ( node a,node b )
    {
        if( a.num!=b.num )
            return a.num < b.num;
        else
            return a.id > b.id;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    int n,num,k;
    string s;
    while( ~scanf("%d",&n) )
    {
        int cnt = 0;
        node t;
        priority_queue<node> q[4];
        while(n--)
        {
            cin>>s;
            if( s=="IN" )
            {
                cin>>k>>num;
                t.id = ++cnt;
                t.num = num;
                q[k].push(t);
            }
            else
            {
                cin>>k;
                if(!q[k].empty())
                {
                    t = q[k].top();
                    q[k].pop();
                    printf("%d\n",t.id);
                }
                else
                    printf("EMPTY\n");
            }
        }
    }
    return 0;
}

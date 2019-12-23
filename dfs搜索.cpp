#include <iostream>
#include <string.h>
using namespace std;
int a[4];
int visted[20];
int temp[10000];
int test[10];
void dfs( int num )
{
    if( num==4 )
    {
        int x = test[0]*1000+test[1]*100+test[2]*10+test[3];
        temp[x]++;
        return ;
    }
    for( int i=0; i<4; i++ )
    {
        if( visted[i]==0 )
        {
            test[num] = a[i];
            visted[i] = 1;
            dfs(num+1);
            visted[i] = 0;
        }
    }
}
void print()
{
    int x=-1;
    int flag = 0;
    for( int i=1000; i<10000; i++ )
    {
        if(temp[i]>0)
        {
            if(i/1000==0) continue;
            if(x==i/1000)
            {
                cout<<" ";
                cout<<i;
            }
            else
            {
                if(flag==0)
                    flag=1;
                else
                    cout<<endl;
                x = i/1000;
                cout<<i;
            }            
        }
    }
    cout<<endl;
}
int main()
{
    int f=0;
    while( ~scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]) )
    {
        if( !a[0] && !a[1] && !a[2] && !a[3] )
            break;
        memset(visted,0,sizeof(visted));
        memset(temp,0,sizeof(temp));
        memset(test,0,sizeof(test));
        if(f==0) f=1;
        else cout<<endl;
        dfs(0);
        print();
    }
    return 0;
}

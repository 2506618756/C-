#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    int cnt=-1,flag=0;
    char c;
    cin>>c>>s;
    for( int i=0; s[i]!='\0'; i++ )
    {
        if( s[i]==c )
            cnt = i;
    }
    if(cnt!=-1) printf("index = %d\n",cnt);
    else printf("Not Found\n");
    return 0;
}

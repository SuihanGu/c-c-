#include<bits/stdc++.h>
using namespace std;
long long cnt=0,u=1000000007;
int  f(int x,int y)
{
    int c;
    while(x%y!=0)
    {
        c=y;
        y=x%y;
        x=c;

    }
    //cout<<y*y<<endl;
    return y*y;
    
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
           cnt+= f(i,j)%u;
        }
    }
    cout<<cnt%u;
    system("pause");
}

#include<bits/stdc++.h>
using namespace std;
int pre[10020],cnt;
bool vis[10020];
long long dp[2020][2020];
void f()
{
    for(int i=2;i<10020;i++)
    {
        if(!vis[i])
        pre[cnt++]=i;
        for(int j=0;j<cnt&&i*pre[j]<10015;j++)
        {
            vis[i*pre[j]]=1;
            if(i%pre[j]==0)break;
        }
        
    }
    return ;
}
int main()
{
    f();
    for(int i=0;pre[i]<=2019;i++)
    {
        dp[pre[i]][pre[i]]=1;
    }
    for(int i=2;i<=2019;i++)
    {
        for(int j=0;pre[j]<=i;j++)
        {
            for(int k=0;k<j&&pre[k]<=i-pre[j];k++)
            {
                dp[i][pre[j]]+=dp[i-pre[j]][pre[k]];
            }
        }
    }
    long long ans=0;
    for(int i=0;pre[i]<=2019;i++)
    {
        ans+=dp[2019][pre[i]];
    }
    cout<<ans<<endl;
    system("pause");
}
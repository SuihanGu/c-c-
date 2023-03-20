#include<bits/stdc++.h>
using namespace std;
long long dp[105][105],a[105];
int dfs(int l,int r)
{
    if(dp[l][r]!=-1)
    {
        return dp[l][r];
    }
    if(r<=l)
    {
        return 0;
    }
    long long ans=0x3f3f3f3f3f;
    for(int i=l;i<=r;i++)
    {
        ans=min(ans,dfs(l,i-1)+dfs(i+1,r)+(r-l)*a[i]);//动态规划加分治
    }
    return dp[l][r]=ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        memset(dp,-1,sizeof(dp));
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        printf("%d\n",dfs(1,n));
    }
    system("pause");
    return 0;
}
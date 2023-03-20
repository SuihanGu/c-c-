#include<bits/stdc++.h>
using namespace std;
int dp[506][506];
int main()
{
    int n,k;
    cin>>n>>k;
    int mod = 123456;
    
    for(int i=1;i<=n;i++)
    {
        dp[i][1]=2;
    }
    for(int i=3;i<=n;i++)
    {
        for(int j=2;j<=k;j++)
        {
            dp[i][j]=dp[i-1][j]*j+dp[i-1][j-1]*2+dp[i-1][j-2]*(i-j);//找规律
            dp[i][j]%=mod;
        }
    }
    cout<<dp[n][k];
    system("pause");
}
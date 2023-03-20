#include<bits/stdc++.h>
using namespace std;
int dp[1004][1004];
int main()
{
    string s,t;
    int cnt = 0;
    int maxx=0;
    cin>>s>>t;
    if(s[0]!=t[0])
    {
        dp[0][0]=1;
    }
    for(int i=1;i<t.size();i++)
    {
        if(s[i]==t[i])
        dp[i][i]=dp[i-1][i-1];

        else
        {
            dp[i][i]=dp[i-1][i-1]+1;
        }
        
        for(int j=1;j<t.size();j++)
        {
            for(int i=j+1;i<s.size();i++)
            {
                if(s[i]==t[j])
                {
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    dp[i][j]=min(dp[i-1][j],dp[i-1][j-1]+1);
                }
                
            }
        }
    }
    cout<<dp[s.size()-1][t.size()-1];
    system("pause");
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e4+3;
const int M = 998244353;
 
int main(){
    int n;
    scanf("%d", &n);
    int a[n+2];
    for(int i=1;i<=n;i++)
        scanf("%d", &a[i]);
    a[0] = a[n+1] = 1;
    long dp[n+2][203][3], s1[203], s2[203];
    dp[0][1][1] = 1;
    for(int i=1;i<=200;i++)
        s1[i] = s2[i] = 1;
    for(int i=1;i<=n+1;i++){
        int l=1, r=200;
        if(a[i])
            l = r = a[i];
        for(int j=l;j<=r;j++){
            dp[i][j][0] = (s2[200]-s2[j])%M;
            dp[i][j][1] = (dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][2])%M;
            dp[i][j][2] = s1[j-1]%M;
        }
        for(int j=1;j<=200;j++){
            s1[j] = s1[j-1] + dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
            s2[j] = s2[j-1] + dp[i][j][0] + dp[i][j][1];
        }
    }
    printf("%ld\n", (dp[n+1][1][0]+dp[n+1][1][1])%M);
    system("pause");
    return 0;
}
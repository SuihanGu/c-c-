#include<bits/stdc++.h>
using namespace std;
#define ll long long
int f[105];
int main()
{
    int i;
    for(int i=2;i<=100;i++)
    {
        int t=i;
        for(int j=2;j<=t;j++)
        {
            while(t%j==0)
            {
                t=t/j;
                f[j]++;
            }
        }
    }
    ll ans=1;
    for(int i=1;i<=100;i++)
    {
        ans*=f[i]+1;
    }
    cout<<ans;
    system("pause");
}
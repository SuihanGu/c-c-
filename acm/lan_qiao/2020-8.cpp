#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans=0,sum=0;
struct node{
    int z,s1,s2;
}s[1000];
int cmp(node a,node b)
{
    if(a.s2!=b.s2)return a.s2<b.s2;
    else
    {
        return a.s1<b.s1;
    }
    
}
int main()
{
    int n,x,y;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y>>s[i].z;
        s[i].s1=x+y;
        s[i].s2=x+y+s[i].z;
    }
    sort(s,s+n,cmp);
    for(int i=0;i<n;i++)
    {
        ans+=s[i].s1;
        sum+=ans;
        ans+=s[i].z;
    }
    cout<<sum;
    system("pause");
}

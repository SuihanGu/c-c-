#include<bits/stdc++.h>
using namespace std;
int n,m;
string s,a[10005],b[10005],c[10005];
int main()
{
    int cnt=0;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='A'&&s[i]<='Z')
        {
            a[++cnt]+=s[i];
            i++;
            while(s[i]>='a'&&s[i]<='z')
            {
                a[cnt]+=s[i];
                i++;
            }
            i--;
        }
    }
    int sum=1;
    int p[10005];
    b[1]=a[1];
    p[1]=sum;
    for(int i=2;i<=cnt;i++)
    {
        if(a[i]>b[sum])
        {
            b[++sum]=a[i];
            p[i]=sum;
        }
        else
        {
            m=lower_bound(b+1,b+1+sum,a[i])-b;
            b[m]=a[i];
            p[i]=m;
        }
        
    }
    int t=sum;
    for(int i=cnt;i>=0;i--)
    {
        if(t<0)break;
        if(p[i]==t)
        {
            c[t]=a[i];
            t--;
        }
    }
    for(int i=1;i<=sum;i++)
    cout<<c[i];
    system("pause");
}
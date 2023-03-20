#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int a[100000];

int main()
{
    int n,k;
    cin>>n>>k;
    memset(a,-1,sizeof(a));
    a[0]=0;
    q.push(0);
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        if(a[(p+1)%n]==-1)
        {
            a[(p+1)%n]=a[p]+1;
            q.push((p+1)%n);
        }
        if(a[(p+k)%n]==-1)
        {
            a[(p+k)%n]=a[p]+1;
            q.push((p+k)%n);
        }
    }
    int maxx=0;
    for(int i=0;i<n;i++)
    {
        maxx=max(maxx,a[i]);
    }
    cout<<maxx;
    system("pause");
}
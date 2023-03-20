#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+20;
int ans[17];
char s[12];
struct node{
    int l,r;
    int a[17];
}tr[N<<2];
bool pd(int x,int y)
{
    if(x>y)
    return 1;
    return 0;
}
void pushup(int m)
{
    for(int i=1;i<=8;i++)
    {
        tr[m].a[i]=tr[m<<1].a[i];
    }
    for(int i=9;i<=16;i++)
    {
        tr[m].a[i]=tr[m<<1|1].a[i-8];
    }
    sort(tr[m].a+1,tr[m].a+17,pd);
    return;
}
void build(int m,int l,int r)
{
    tr[m].l=l;
    tr[m].r=r;
    if(l==r)
    {
        memset(tr[m].a,0,sizeof(tr[m].a));
        return ;
    }
    int mid=(l+r)>>1;
    build(m<<1,l,mid);
    build(m<<1|1,mid+1,r);
    pushup(m);
    return ;
}
void updata(int m,int x,int y)
{
    if(tr[m].l==x&&tr[m].r==x)
    {
        tr[m].a[1]=y;
        return ;
    }
    int mid = (tr[m].l+tr[m].r)>>1;
    if(x<=mid)
    updata(m<<1,x,y);
    else
    {
        updata(m<<1|1,x,y);
    }
    pushup(m);
    return ;

    
}
void query(int m,int l,int r)
{
    if(tr[m].l==l&&tr[m].r==r)
    {
        for(int i=9;i<=16;i++)
        {
            ans[i]=tr[m].a[i-8];

        }
        sort(ans+1,ans+17,pd);
        return ;
    }
    int mid=(tr[m].l+tr[m].r)>>1;
    if(r<=mid)
    query(m<<1,l,r);
    else if(l>mid)
    {
        query(m<<1|1,mid+1,r);
    }
    else
    {
        query(m<<1,l,mid);
        query(m<<1|1,mid+1,r);
    }
    return ;
}
int main()
{
    int n,k,x,y;
    cin>>n>>k;
    build(1,1,n);
    for(int i=0;i<k;i++)
    {
        scanf("%s%d%d",s,&x,&y);
        if(s[0]=='C')
        {
            updata(1,x,y);
        }
        else
        {
            for(int j=1;j<=8;j++)
            {
                ans[j]=0;
            }
            query(1,x,y);
            printf("%d\n",ans[8]);
        }
        
    }
    system("pause");
}

#include<iostream>
using namespace std;
int a[100][2],b[24]={0},p=0,n;
int f(int i,int l)
{
    
    if(l>p)p=l;
    if(i<n)
    {
        int g=0;
        for(int j=a[i][0];j<a[i][1];j++)
        if(b[j]!=0)g=1;
        if(g==0)
        {
            for(int j=a[i][0];j<a[i][1];j++)
            b[j]+=1;
            f(i+1,l+1);
            for(int j=a[i][0];j<a[i][1];j++)
            b[j]-=1;
        }
        f(i+1,l);
    }
}
int main ()
{

    while(cin>>n&&n!=0)
    {
        for(int i=0;i<n;i++)
        {
            cin>>a[i][0]>>a[i][1];
        }
        for(int i=0;i<=24;i++)
        b[i]=0;
        p=0;
        for(int i=0;i<n;i++)
        f(i,0);
        cout<<p<<endl;
    }
    system("pause");
}
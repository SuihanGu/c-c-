#include<iostream>
using namespace std;
int a[10001],l=0,n;
int f(int p,int u)
{
    if(u>l)l=u;
    if(p<n)
    {
        u=u+a[p];
        f(p+1,u);
    }
}
int main ()
{
    while(cin>>n&&n!=0)
    {
        l=0;
        for(int i=0;i<n;i++)
        cin>>a[i];
        for(int i=0;i<n;i++)
        f(i,0);
        cout<<l<<endl;
    }
    system("pause");
}
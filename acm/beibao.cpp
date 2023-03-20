#include<iostream>
using namespace std;
int a[20],b[20],n,w,p=0;
int f(int w1,int h1,int i)
{
    if(w1>w||i>n)
    return 0;
    if(i==n-1)
    {
        if(h1>p)
            p=h1;
    }

    f(w1,h1,i+1);
    f(w1+a[i+1],h1+b[i+1],i+1);
}
int main()
{
    cin>>n>>w;
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<n;i++)
    cin>>b[i];
    for(int i=0;i<n;i++)
    f(a[i],b[i],i);
    cout<<p<<endl;
    system("pause");
}
#include<iostream>
using namespace std;
int main()
{
    int n,k,a[10000],p=0,x=-1;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<k;i++)
    {
        p=0;x=-1;
        for(int j=0;j<n;j++)
        {
            if(a[j]>x)
            x=a[j],p=j+1;
        }
        cout<<p<<" ";
        a[p-1]=-1;
    }
    cout<<endl;
    system("pause");
}
#include<iostream>
using namespace std;
int main ()
{
    int n;
    while(cin>>n)
    {
        int a[6000],b[10]={0};
        for(int i=0;i<n;i++)
        {cin>>a[i];b[a[i]]++;}
        for(int i=0;i<10;i++)
        if(b[i]>=(n+1)/2)
        cout<<i<<endl;
    }
    system("pause");
}
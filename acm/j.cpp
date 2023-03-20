#include<iostream>
using namespace std;
int main ()
{
    int n,m;
    cin>>n>>m;
    int g=0;
    for(int i=n;i<=m;i++)
    {
        if(i%6==0&&i%7!=0)
        g++;
    }
    cout<<g<<endl;
    system("pause");
}
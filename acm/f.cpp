#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int p;
        cin>>p;
        int s[202]={0};
        int a,b;
        for(int u=0;u<p;u++)
        {
            cin>>a>>b;
            for(int y=a;y<=b;y++)
                s[y]++;
        }
        int h=0;
        for(int j=0;j<=200;j++)
        if(s[j]>h)
        h=s[j];
        cout<<h*5<<endl;
    }
    system("pause");
}
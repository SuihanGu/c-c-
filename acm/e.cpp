#include<iostream>
#include<string.h>
using namespace std;
int main ()
{
    int n,p;
    char s[1009][10],k[5]={'g','r','b','p','o'};
    while(cin>>n&&n!=0)
    {
        p=0;int m[5]={0},y=0;
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
            for(int j=0;j<5;j++)
            if(s[i][0]==k[j])
            m[j]++;
        }
        for(int j=0;j<5;j++)
        if(m[j]>p)
        p=m[j],y=j;
        if(k[y]=='g')cout<<"green"<<endl;
        if(k[y]=='r')cout<<"red"<<endl;
        if(k[y]=='o')cout<<"orange"<<endl;
        if(k[y]=='p')cout<<"pink"<<endl;


    }
    system("pause");
}
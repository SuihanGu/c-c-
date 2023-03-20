#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int a,b,p=0;
    cin>>a>>b;
    float q,w,e;
    for(int i=0;i<a;i++)
    {
        cin>>q>>w;
        e=sqrt(q*q+w*w);
        if(e<=b)p++;
    }
    cout<<p<<endl;
    system("pause");
}
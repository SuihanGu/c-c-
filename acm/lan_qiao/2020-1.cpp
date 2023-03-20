#include<bits/stdc++.h>
using namespace std;
int main()
{
    int cnt=0;
    for(int i=1;i<=2020;i++)
    {
        int f=0;
        int y=i;
        while(y>0)
        {
            int u=y%10;
            if(u==2&&f==0)
            {
                cnt++;
                f=1;
            }
            y/=10;
        }
    }
    cout<<cnt;
    
    system("pause");
}
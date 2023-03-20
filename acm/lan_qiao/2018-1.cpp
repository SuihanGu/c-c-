#include<bits/stdc++.h>
using namespace std;
int main()
{
    int cnt=9999;
    for(int k=0;k<2;k++)
    for(int i=1;i<=34;i++)
    {
        for(int j=1;j<=10;j++)
        {
            
            if(k*100+i*5+21*j==200)
            {
                cnt = min(cnt,k+11*j+i);
            }
        }
    }
    cout<<cnt;
    system("pause");
}
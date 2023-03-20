#include<bits/stdc++.h>
using namespace std;
int main()
{
    
    for(int u=1000;;u++)
    {
        int cnt = 0;
        for(int j=1;j<=u;j++)
        {
            if(u%j==0)
            cnt++;

        }
        if(cnt==100)
        {
            cout<<u;
            system("pause");
            return 0;
        }
    }
}
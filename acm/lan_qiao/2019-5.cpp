#include<bits/stdc++.h>
using namespace std;
int a[8][8],cnt=0;
int dis[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void dfs(int x,int y,int s)
{
    if(s>12)
    return;
    for(int i=0;i<4;i++) 
    {
        int tx = x+dis[i][0];
        int ty = y+dis[i][1];
        
        if(tx<0||ty<0||tx>7||ty>7)continue;
        
        if(tx==0&&ty==0&&s+1>2&&s+1<=12)//路线不能重复所以两步不可能实现
        {
                cnt++;
                
        }
        if(a[tx][ty])
        continue;
        
            a[tx][ty]=1;
            dfs(tx,ty,s+1);
            a[tx][ty]=0;
        
    }
}
int main()
{
    memset(a,0,sizeof(a));
    a[0][0]=1;
    dfs(0,0,0);
    //a[0][0]=0;
    cout<<cnt<<endl;
    system("pause");
    return 0;
}
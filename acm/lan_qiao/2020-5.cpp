#include<bits/stdc++.h>
using namespace std;
int dis[4][2]={0,-1,0,1,1,0,-1,0};
int a[5][5],vis[5][5];
int ans=0;
void dfs(int i,int j,int t)
{
    if(t==16)
    {
            ans++;
            return ;
    }
    for(int k=0;k<4;k++)
    {
        int tx=i+dis[k][0];
        int ty=j+dis[k][1];
        if(tx>=0&&tx<4&&ty>=0&&ty<4&&vis[tx][ty]==0)
        {
            vis[tx][ty]=1;
            dfs(tx,ty,t+1);
            vis[tx][ty]=0;
        }
        else
        {
            continue;
        }
        
    }
}
int main()
{
    for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
    {
        memset(vis,0,sizeof(vis));
        vis[i][j]=1;
        dfs(i,j,1);
    }
    cout<<ans;
    system("pause");
}
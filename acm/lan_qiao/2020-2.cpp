#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dis[4][2]={0,-1,-1,0,0,1,1,0};
int a[10005][10005],vis[10005][10005];//连续定义，内存空间是连续的，所以当下标为负数时也能计算

ll ans=0;
struct point{
    int x,y,t;
};
void bfs()
{
    queue<point> q;
    point z,s;
    z.x=0,z.y=0,z.t=0;
    q.push(z);
    z.x=2020,z.y=11,z.t=0;
    q.push(z);
    z.x=11,z.y=14,z.t=0;
    q.push(z);
    z.x=2000,z.y=2000,z.t=0;
    q.push(z);
    vis[0][0]=vis[2020][11]=vis[11][14]=vis[2000][2000]=1;
    while(!q.empty())
    {
        z=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            s.x=z.x+dis[i][0];
            s.y=z.y+dis[i][1];
            s.t=z.t+1;
            //if(s.x>=0&&s.y>=0)
            if(vis[s.x][s.y]==0&&s.t<=2020)
            {
                vis[s.x][s.y]=1;
                ans++;
                q.push(s);
            }

        }
        
    }
    cout<<ans+4;
}
int main()
{
    bfs();
    system("pause");
    return 0;
}
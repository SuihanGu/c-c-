#include<bits/stdc++.h>
using namespace std;
double dis[10007][10007];
double dp[10007][10007];
int flag[10007];
const int inf=0x3f3f3f3f;
int n,m;
double mm=0;
int dsf(int k,double u)
{
	if(k==n)
	{
	mm=max(mm,u);
	return 0;
	}
	
	for(int i=1;i<=n;i++)
	{
		if(dis[k][i]!=0&&flag[k]==0)
		{
			flag[i]=1;
			dsf(i,u*dis[k][i]);
			flag[i]=0;
		}
		else
		continue;
	}
}

int main()
{
	int t;
	
	cin>>t;
	while(t--)
	{
		mm=0;
		cin>>n>>m;
		for(int i=0;i<m;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			double p=c*0.01;
			dis[a][b]=dis[b][a]=p;
		}
		flag[1]=1;
		dsf(1,1);
		cout<<mm;
	}
}
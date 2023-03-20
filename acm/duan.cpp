#include<bits/stdc++.h>
using namespace std;
int qiu(int n)
{
	int a=n;
	while(!(a>=1&&a<=9))
	{
		int c=0,b=a;
		while(b)
		{
			c=c+b%10;
			b=b/10;
		}
		a=c;
	}
	return a;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int k,n,i;
        cin>>n>>k;
        if(k==1)
        {
        	cout<<qiu(n)<<endl;
		}
		else
		{
			int m[10],c[20];
			memset(c,0,sizeof(c));
			memset(m,0,sizeof(m));
			long a[10];
			memset(a,0,sizeof(a));
			int b=n,j=0,t,k,te;
			while(b)
			{
				m[j]=b%10;
				b=b/10;
				j++;
			}
			t=j;
			k=t*t;
			for(i=0;i<j;i++)
			{
				a[i]=n*m[i];
			}
			te=0;
			for(i=0;i<k;i++)
			{
				for(j=0;j<=i;j++)
				{
					c[i]=(int)(a[j]/pow(10,i-j))%10;
				}
				if(te)
				{
					c[i]=c[i]+te;
					te=0;
				}
				if(c[i]>9)
				{
					te=c[i]/10;
					c[i]=c[i]%10;
				}
			}
			b=0;
			for(i=0;i<k;i++)
			{
				b=b+c[i];
			}
			cout<<qiu(b)<<endl;
		}
 }
}

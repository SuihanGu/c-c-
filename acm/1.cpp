#include<bits/stdc++.h>
using namespace std;
double p,q,l;
int a[100009];
int main()
{
    
    int n,x;
    while(cin>>n>>x)
    {
        int p,q;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];

        }
        int max=0;
        for(int i=0;i<n-1;i++)
        {
            if(a[i+1]-a[i]>0)
            {
                max+=a[i+1]-a[i];
            }
        }
    }

    system("pause");
}
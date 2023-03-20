#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3;
int ju(int x)
{
    map<char,int>vis;
    vis[s1[x]]++;
    vis[s1[x+4]]++;
    vis[s1[x+8]]++;
    vis[s2[x]]++;
    vis[s2[x+4]]++;
    vis[s3[x]]++;
    if(vis['G']==3&&vis['R']==2&&vis['Y']==1)
    return 1;
    return 0;

}

int main()
{
   int t;
   cin>>t;
   while(t--) 
   {
        cin>>s1>>s2>>s3;
        int f=1;
        for(int i=0;i<4;i++)
        {
            if(!ju(i)){
                f=0;
                break;
            }
        }
        if(f)
        cout<<"Yes"<<endl;
        else
        {
            cout<<"No"<<endl;
        }
        
   }
   system("pause");
   return 0;
}
//找规律
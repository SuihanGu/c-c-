#include<bits/stdc++.h>
using namespace std;
//char a[210]="tocyjkdzcieoiodfpbgcncsrjbhmugdnojjddhllnofawllbhfiadgdcdjstemphmnjihecoapdjjrprrqnhgccevdarufmliqijicfauachlifhafpdccfseflcdgjncadfclvfmadvrnaaahahndsikzssoywakgnfjjaihtniptwoulxbaeqkqhfwl";
char a[8]="lanqiao";
const int inf=0x3f3f3f3f;
typedef long long ll;
int n,m,ans;

#define mk make_pair
map<string,int> vis;
int main()
{
    int i,j,k;
    queue<pair <string,int>>q;
    for(i=0;i<7;i++)
    {
        string s="";
        s+=a[i];
        if(vis[s]==0)//去重
        {
            vis[s]=1;
            q.push(mk(s,i));
            ans++;
        }
    }
    while(!q.empty())
    {
        string s=q.front().first;
        int pos=q.front().second;
        q.pop();
        for(int i=pos+1;i<7;i++)//子序列
        {
            if(a[i]>a[pos]&&vis[s+a[i]]==0)
            {
                cout<<s+a[i]<<endl;
                vis[s+a[i]]=1;
                q.push(mk(s+a[i],i));
                ans++;
            }
        }
    }
    cout<<ans;
    system("pause");
}
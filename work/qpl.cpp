#include<bits/stdc++.h>
using namespace std;
void perm(int a[],int s,int n)//全排列函数递归
{
    if(s==n-1)//解决规模最小的子问题：只有一个元素的序列的全排列
    {
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
        cout<<endl;
    }
    else//否则按照递推式划分子问题
    {
        for(int i=s;i<n;i++)
        {
            swap(a[s],a[i]);//做交换
            perm(a,s+1,n);//递归
            swap(a[s],a[i]);
        }
    }
    return ;
    
}
int main()
{
    int n;
    int a[100];
    cin>>n;//输入为序列长度
    for(int i=0;i<n;i++)
    {
        cin>>a[i];//输入数组
    }
    perm(a,0,n);
    system("pause");
}
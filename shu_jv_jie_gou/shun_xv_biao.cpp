#include<bits/stdc++.h>
using namespace std;
#define MaxSize 50
typedef struct 
{
    int data[MaxSize];
    int length;
}SqList;
#define InitSize 100
typedef
{
    int *data;
    int MaxSize,length;
}SqList;
//插入,平均移动次数n/2
bool ListInsert(SqList &L,int i,int e)
{
    if(i<1||i>L.length+1)
    return false;
    if(L.length>=MaxSize)
    return false;
    for(int j=L.length;j>=i;j--)
    L.data[j]=L.data[j-1];
    L.data[i-1]=e;
    L.length++;
    return true;
}
//删除,平均次数（n-1）/2
bool ListDelete(SqList &L,int i,int &e)
{
     if(i<1||i>L.length)
    return false;
    e=L.data[i-1];
    for(int j=i;j<L.length;j++)
    {
        L.data[j-1]=L.data[j];
        L.length--;
        return true;
    }
}
//按值查找
int LocateElem(SqList L,int e)
{
    int i;
    for(i=0;i<L.length;i++)
    {
        if(L.data[i]==e)
        {
            return i+1;
        }

    }
    return 0;
}
int main()
{

}
#include <iostream> 
using namespace std;
char strToChar[100];
int total;
bool duplicate(char charList[],int k,int i)//第i个元素是否在前面的元素[k...i-1]中出现过
{
    if(i>k){
        for(int j=k;j<i;j++){
            if(charList[j] == charList[i])
                return false;
        }
    }
    return true;
}

void swapList(char charList[],int k,int i)//将两个元素交换位置
{
    char temp;
    temp=charList[k];
    charList[k]=charList[i];
    charList[i]=temp;
}
void perm(char charList[],int k,int m){
    if(k==m){
        for(int i=0;i<=m;i++){
            cout<<charList[i];
        }
        cout<<endl;
        return;
    }
 
    for(int i=k;i<=m;i++){
        if(duplicate(charList,k,i)){
            swapList(charList,k,i);
            perm(charList,k+1,m);
            swapList(charList,k,i);
        }
    }
} 
int main()
{
    int n;
    cin>>n;
 
    for(int i=0;i<n;i++){
       cin>>strToChar[i];
    }
    cout<<endl;
    perm(strToChar,0,n-1);
    cout<<endl;
    system("pause");
    return 0;
}
 
 
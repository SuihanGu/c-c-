#include<bits/stdc++.h>
using namespace std;
 
unsigned long long x,y;
int main()
{
    for(int i = 2020;i<5000;i++)
    {
       for(int j=i+1;j<5000;j++)
       {
           if(i*i-2019*2019==j*j-i*i)
           {cout<<i+j;
           system("pause");
           return 0;
           }
       }
    }
}
#include<iostream>
#include<stdio.h>
int max=0,n;
void f(int h,int a[],int m)
{
    if(max<m)
    {
        max=m;
    }
    int p=h+1;
     if(p<=n)
     f(p,a,m*a[p]);

}
int main ()
{
    int a[20];
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        f(i,a,a[i]);
    }
    printf("%d\n",max);
    system("pause");
}
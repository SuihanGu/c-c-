#include<iostream>
using namespace std;
#include<stdlib.h>

//————————定义链栈的结点结构————————
typedef struct PNode
{
	float coef;              //系数 
	long long expn;                //指数 
	struct PNode *next;      //指针域 
}PNode,*Polynomial;

//————————多项式的创建————————
void CreatPolyn(Polynomial &P,int n)
{
	int i; 
	Polynomial s,pre,q;
	P=new PNode;              
	P->next=NULL;             //建立一个带头结点的单链表 
	for(i=1;i<=n;++i)         //依次输入n个非零项 
	{
		s=new PNode;  
		     //生成新结点 
		cin>>s->coef>>s->expn;      //输入系数和指数 
		pre=P;      //保存q的前驱，初始值为头结点 
		q=P->next;      //初始化q，指向首元结点 
		while(q&&q->expn<s->expn)       //通过比较找到第一个大于输入项指数的项*q 
		{
			pre=q;
			q=q->next;
		}
		s->next=q;      //将输入项s插入到q和其前驱结点pre之间 
		pre->next=s;
	}
	
 } 
 
//————————输出多项式————————
void prinPolyn(Polynomial P)
{
	Polynomial p=P->next;
	while(p)
	{
       if(p->coef!=0){
		cout<<"("<<p->coef<<"x^"<<p->expn<<")";
		if(p->next&&p->next->coef!=0)
		{
			cout<<"+";
		}
	   }
		p=p->next;
	}
 } 
 
//————————同指数项合并————————
void ComPolyn(Polynomial &P)
{
	Polynomial p1=P,p2;
    p1=P->next;
    p2=p1->next;
    while(p2)
    {
    	if(p1->expn==p2->expn)
    	{
    		p1->coef+=p2->coef;
            p2->coef=0;
        	p2=p2->next;
		}
		else
		{
			p1=p1->next;
			p2=p2->next;
		}
		
		
	}
 } 
 
 
 int main()
 {
 	int m,n; 
	PNode *Pa;
    cout<<"多项式Pa的项数：";
	cin>>m;
	cout<<"创建多项式Pa：";
	CreatPolyn(Pa,m);
	cout<<"Pa=";
	prinPolyn(Pa);
	cout<<endl; 
	cout<<endl<<"多项式合并结果为："<<endl;
	ComPolyn(Pa);
	prinPolyn(Pa);
	cout<<endl; 
    system("pause");
	return 0;	
 }
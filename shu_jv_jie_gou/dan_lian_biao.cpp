#include <bits/stdc++.h>
using namespace std;
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;
//ͷ�巨
LinkList List_HeadInsert(LinkList &L){
    LNode *s;int x;
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    scanf("%d",&x);
    while(x!=9999)
    {
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        s->next=L->next;
        L->next=s;
        scanf("%d",&x);
    }
    return L;
}
//β��
LinkList List_TailInsert(LinkList &L)
{
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s,*r=L;
    scanf("%d",&x);
    while(x!=9999)
    {
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        r->next=s;
        r=s;
        scanf("%d",&x);
    }
    r->next=NULL;
    return L;
}

//����Ų��ҽ��ֵ
LNode *GetElem(LinkList L,int i)
{
    int j=1;
    LNode *p=L->next;
    if(i==0)
        return L;  
    if(i<1)
        return NULL;
    while(p&&j<i)
    {
        p=p->next;
        j++;
    }
    return p;
}
//��ֵ���ұ�ڵ�
LNode *localeElem(LinkList L,int e)
{
    LNode *p=L->next;
    while(p!=NULL&&p->data!=e)
        p=p->next;
    return p;
}
 
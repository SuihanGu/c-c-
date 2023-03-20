#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INSEASIBLE -1
#define OVERFLOW -2
int count=0,i=0;

typedef int Status; 
typedef char ElemType;
typedef struct BiTNode{
ElemType data;
struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void PreOrderTraverse(BiTree T)
{
	if(T){	
		printf("%c ",T->data);
		PreOrderTraverse(T->lchild);	
		PreOrderTraverse(T->rchild); 
	}
}

void InOrderTraverse(BiTree T)
{
	if(T)
	{
		InOrderTraverse(T->lchild);
		printf("%c ",T->data);
		InOrderTraverse(T->rchild);
	}
	
} 

void PostOrderTraverse(BiTree T) 
{
	if(T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        printf("%c ",T->data);
    }
	
	
} 

void CountNode(BiTree &T)
{
	if(T)
	{
		count++;
		CountNode(T->lchild);
		CountNode(T->rchild);
	}
} 

Status CreateBiTree(BiTree &T)

{
	char ch;	
	scanf("%c",&ch);
	if(ch=='#') T=NULL;
	else{	
		if(!(T=(BiTNode *)malloc(sizeof(BiTNode)))) exit(OVERFLOW);	
		T->data=ch;		
		CreateBiTree(T->lchild);		
		CreateBiTree(T->rchild);		
	}
	return OK;
}

void CountLeaf(BiTree &T)
{
	if(T!=NULL)
	{
		if(T->lchild==NULL&&T->rchild==NULL)
		{
			i++;
			return;
		}
		CountLeaf(T->lchild);
		CountLeaf(T->rchild);
	}
} 

int depth(BiTree &T)
{
	int l,d;
	if(T==NULL)
	{
		return 0;
	}
	else {
		l=depth(T->lchild);
		d=depth(T->rchild);
		if(l>d)return l+1;
		else return d+1;
	}	
} 
void Midorder(BiTree T)
{
	BiTNode *p[1000];
	int top=0;
	do{
		while(T!=NULL)
		{
			p[top++]=T;
			T=T->lchild;
		}
		if(top)
		{
			T=p[--top];
			printf("%c",T->data);
			T=T->rchild;
		}
	}while(top||T!=NULL);
}
int main()

{
	BiTree T=NULL;
	printf("开始建树，请输入二叉树各个节点的值(按先序次序输入):\n"); 
    CreateBiTree(T);	
	printf("\n以下是该树的先序遍历序列:\n");	
	PreOrderTraverse(T);
	printf("\n以下是该树的中序遍历序列:\n");
	InOrderTraverse(T);
    printf("\n以下是该树的后序遍历序列:\n");
    PostOrderTraverse(T);
	printf("\n以下是该树的非递归中序遍历序列:\n");
	Midorder(T);
	printf("\n");
	CountNode(T);
	printf("二叉树总结点数:%d\n",count);
	CountLeaf(T);
	printf("叶子节点的个数:%d\n",i);
	printf("二叉树的深度:%d\n",depth(T)); 
	Midorder(T);
    system("pause");
}
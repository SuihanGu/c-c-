#include<stdio.h>
#include<stdlib.h>
// 链栈的存储结构
typedef struct StackNode
{
    int data;
    struct StackNode *next;
}StackNode, *LinkStack;
// 初始化
int InitStack(LinkStack &S) 
{
	S = NULL;   // 将栈顶指针置空
	return 1;
}
// 入栈
void Push(LinkStack &S, int e)
{
	//元素e入栈
	StackNode *p;
	p = new StackNode;  // 生成新节点
	
	p->data = e;        // 将新节点数据域置为e
	p->next = S;        // 将新节点插入栈顶
	S = p;             // 修改栈顶指针     
}
 
// 出栈
void Pop(LinkStack &S, int &e)
{
	e = S->data;    //将栈顶元素赋值给e
	StackNode *p;
	p = S;         // 临时保存栈顶元素空间，准备释放
	S = S->next;    // 修改栈顶指针
	free(p);    // 释放原栈顶元素空间
}
// 取栈顶元素
int GetTop(LinkStack S)
{
	//返回S的栈顶元素,不修改栈顶指针
	if (S != NULL)  // 栈非空
		return S->data;  // 返回栈顶元素的值,栈顶指针不变
}
void TraveStack(LinkStack S) //显示
{
	StackNode *p;
	p = S;
	while (p) 
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
 
int main() 
{
	LinkStack S;
 
	if (InitStack(S)) 
	{
		printf("链栈初始化成功!\n");
	}
	else 
	{
		printf("链栈初始化失败!\n");
	}
 
	// 入栈
	int n;
	printf("请输入栈的元素个数:");
	scanf("%d",&n);
	for (int i = 0; i < n;)
	{
		int e;
		printf("请输入第%d个入栈的元素:",++i);
		scanf("%d", &e);
		Push(S, e);
	}
	printf("遍历栈:\n");
	TraveStack(S);
 
	// 出栈（取出两个元素）
	for (int i = 0; i < 2;)
	{
		int a;
		Pop(S, a);
		printf("第%d个出栈的元素:%d\n", ++i, a);
	}
	printf("遍历栈:\n");
	TraveStack(S);
	
	printf("栈顶元素是:%d\n", GetTop(S));
	
	system("pause");
	
	return 0;
}

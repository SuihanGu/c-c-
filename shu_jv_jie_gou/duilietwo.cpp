#include<stdio.h>

#include<stdlib.h>

//用#define 宏定义来定义符号常量和函数结果状态代码

#define TRUE 1

#define FALSE 0

#define OK 1

#define ERROR 0

#define INSEASIBLE -1

#define OVERFLOW -2

#define MAXQSIZE 10	//循环队列的最大长度

//用 typedef 给类型起别名

typedef int Status; //Status 是函数的类型，其值是函数结果状态代码 
typedef int ElemType; //本例中顺序栈中存储 int 型数据

//———————循环队列	队列的顺序存储表示———————

typedef struct{

    ElemType *base;

    int front;	//请观察循环队列的指针

    int rear;

}SqQueue;
//构造一个空队列 Q
Status InitQueue(SqQueue &Q)
{
    Q.base=(ElemType *)malloc(MAXQSIZE*sizeof(ElemType));
    if(!Q.base) exit(OVERFLOW);
    Q.front=Q.rear=0;
    return OK;
}
//求队列长度
int QueueLength(SqQueue Q)
{
    return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
}
//入队
Status EnQueue(SqQueue &Q,ElemType e)
{
    if((Q.rear+1)%MAXQSIZE==Q.front) return ERROR;//请理解队列满的判断方法
    Q.base[Q.rear]=e;
    Q.rear=(Q.rear+1)%MAXQSIZE;//请理解循环队列的指针后移
    return OK;
}
//出队
Status DeQueue(SqQueue &Q,ElemType &e)
{
    if(Q.rear==Q.front) return ERROR;//请理解队列空的判断方法
    e=Q.base[Q.front];
    Q.front=(Q.front+1)%MAXQSIZE;//请理解循环队列的指针后移
    return OK;
}
//队列元素的显示
void DispQueue(SqQueue Q)
{
    int i=Q.front;
    printf("\n 当前队列中的数据是：\n");
    while(i!=Q.rear)	//请理解循环条件
    {
        printf("%d ,",Q.base[i]);
        i=(i+1)%MAXQSIZE;//请理解循环队列的指针后移;
    }
    printf("\n 数据显示完毕！\n\n");
}

int main()
{
    SqQueue Q;
    InitQueue(Q);
    EnQueue(Q,10);
    EnQueue(Q,20);
    EnQueue(Q,30);
    EnQueue(Q,40);
    printf("入队后：\n");
    DispQueue(Q);
    printf("当前队列中元素个数：%d \n",QueueLength(Q));
    ElemType e;
    DeQueue(Q,e);
    DeQueue(Q,e);
    printf("出队后：\n");
    DispQueue(Q);
    printf("当前队列中元素个数：%d \n",QueueLength(Q));
    system("pause");
}

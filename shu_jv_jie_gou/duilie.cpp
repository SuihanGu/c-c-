#include<stdio.h>
#include<stdlib.h>
//用#define 宏定义来定义符号常量和//函数结果状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INSEASIBLE -1
#define OVERFLOW -2
//用 typedef 给类型起别名
typedef int Status; //Status 是函数的类型，其值是函数结果状态代码 
typedef int ElemType; //本例中链队列中存储 int 型数据
//———————单链队列——队列的链式存储结构———————
typedef struct QNode{
    ElemType data;
    struct QNode *next;
}QNode,*QueuePtr;
typedef struct{
QueuePtr front;
QueuePtr rear;
}LinkQueue;
//构造一个空队列
Status InitQueue(LinkQueue &Q)
{
    Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
    if(!Q.front) exit(OVERFLOW);
    Q.front->next=NULL;
    return OK;
}
//销毁队列
Status DestroyQueue(LinkQueue &Q)
{
    while(Q.front)
    {
        Q.rear=Q.front->next;
        free(Q.front);
        Q.front=Q.rear;
    }
    return OK;
}
//入队 将新元素 e 插入到队尾 成为新的队尾元素 
Status EnQueue(LinkQueue &Q,ElemType e) {
    QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
    if(!p) exit(OVERFLOW);
    p->data=e; p->next=NULL;
    Q.rear->next=p;
    Q.rear=p;
    return OK;
}
//出队	删除队列 Q 的队头元素	用 e 返回其值
Status DeQueue(LinkQueue &Q,ElemType &e)
{
    if(Q.front==Q.rear) return ERROR;
    QueuePtr p=Q.front->next;
    e=p->data;
    Q.front->next=p->next;
    if(Q.rear==p) Q.rear=Q.front;
    free(p);
    return OK;
}
//链队列 Q 的显示函数，将队列中从队头到队尾每个元素都显示出来
void QueueDisp(LinkQueue Q)
{
    QueuePtr p=Q.front->next;
    printf("\n 当前链队列 Q 中的数据是：\n");
    while(p)
    {
        printf("%d --> ",p->data);
        p=p->next;
    }
    printf("\n 链队列数据显示完毕！\n\n");
}

int main()

{
    LinkQueue Q;
    InitQueue(Q);
    EnQueue(Q,10);
    EnQueue(Q,20);
    EnQueue(Q,30);
    EnQueue(Q,40);
    EnQueue(Q,50);
    printf("入队后：\n");
    QueueDisp(Q);
    ElemType	e;
    DeQueue(Q , e);
    printf("出队后：\n");
    QueueDisp(Q);
    printf("被删除的元素是：%d\n",	e);
    system("pause");
}

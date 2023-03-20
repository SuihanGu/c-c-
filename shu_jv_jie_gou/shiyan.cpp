#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//鐢?#define 瀹忓畾涔夋潵瀹氫箟绗﹀彿甯搁噺鍜?//鍑芥暟缁撴灉鐘舵€佷唬鐮?
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INSEASIBLE -1
#define OVERFLOW -2
//鐢? typedef 缁欑被鍨嬭捣鍒�鍚�
typedef int Status; //Status 鏄�鍑芥暟鐨勭被鍨嬶紝鍏跺€兼槸鍑芥暟缁撴灉鐘舵€佷唬鐮? 
typedef int ElemType; //鏈�渚嬩腑閾鹃槦鍒椾腑瀛樺�? int 鍨嬫暟鎹?
//鈥斺€斺€斺€斺€斺€斺€斿崟閾鹃槦鍒椻€斺€旈槦鍒楃殑閾惧紡瀛樺偍缁撴瀯鈥斺€斺€斺€斺€斺€斺€?
typedef struct QNode{
    ElemType data;
    struct QNode *next;
}QNode,*QueuePtr;
typedef struct{
QueuePtr front;
QueuePtr rear;
}LinkQueue;
//鏋勯€犱竴涓�绌洪槦鍒�
//鈥斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€?//
#define STACK_INIT_SIZE 100 //椤哄簭鏍堝瓨鍌ㄧ┖闂寸殑鍒濆�嬪垎閰嶉�? 
#define STACKINCREMENT 10 //椤哄簭鏍堝瓨鍌ㄧ┖闂寸殑鍒嗛厤澧為噺
typedef int Status; //Status 鏄�鍑芥暟鐨勭被鍨嬶紝鍏跺€兼槸鍑芥暟缁撴灉鐘舵€佷唬鐮?
typedef int ElemType; //鏈�渚嬩腑椤哄簭鏍堜腑瀛樺�? int 鍨嬫暟鎹?
//鈥斺€斺€斺€斺€斺€斺€旀爤鐨勯『搴忓瓨鍌ㄨ〃绀衡€斺€斺€斺€斺€斺€斺€? 
typedef struct{
    ElemType *base;
    ElemType *top;
    int stacksize;
}SqStack;
typedef struct{
    char *base;
    char *top;
    int stacksize;
}SqStack16;
//鏋勯€犱竴涓�绌烘�? S

Status InitStack_Sq(SqStack &S)
{
    S.base=(ElemType *)malloc(STACK_INIT_SIZE*sizeof(ElemType));
    if(!S.base) exit(OVERFLOW);
    S.top=S.base;
    S.stacksize=STACK_INIT_SIZE;
    return OK;
}

//鑾峰緱椤哄簭鏍堜腑鐨勬爤椤跺厓绱狅紝鐢? e 杩斿洖

Status GetTop(SqStack S,ElemType &e)
{
    if(S.base==S.top) return ERROR; //璇锋€濊€冭�ヨ��鍙ョ殑浣滅�?
    e=*(S.top-1);
    return OK;
}

//鍏ユ爤	鎻掑叆鏂板厓绱? e

Status Push(SqStack &S,ElemType e)
{//鍒ゆ柇褰撳墠瀛樺偍绌洪棿鏄�鍚﹀凡婊★紝濡傛灉宸叉弧锛屽�炲姞鍒嗛厤 
    if(S.top-S.base>=S.stacksize)
    {

        S.base =(ElemType *)realloc (S.base,(S.stacksize+STACKINCREMENT)*sizeof(ElemType));

        if(!S.base ) exit(OVERFLOW); S.top=S.base; S.stacksize+=STACKINCREMENT;
    }
    *S.top++=e;
    return OK;
}
//鍑烘爤锛岀敤 e 杩斿洖鏍堥《鍏冪礌鍊?
Status Pop(SqStack &S,ElemType &e)
{
    if(S.base==S.top) return ERROR;
    e=*--S.top;
    return OK;
}

//椤哄簭鏍堟樉绀哄嚱鏁帮紝浠庢爤搴曞埌鏍堥《姣忎釜鍏冪礌閫愪釜鏄剧ず鍑烘潵 
void StackDisp_Sq(SqStack S) 
{

    ElemType *p;
    printf("\n 褰撳墠鏍堜腑鐨勬暟鎹�鏄�锛歕n");
    p=S.base;
    while(p<S.top)
    {
        printf("%d ,",*p); p++;
    }
    printf("\n 鏁版嵁鏄剧ず瀹屾瘯锛乗n\n");
}
//鍒ゆ柇椤哄簭鏍? S 鏄�鍚︿负绌恒€傝嫢 S 涓虹┖锛屽垯杩斿洖 TRUE锛屽惁鍒欙紝杩斿洖 FALSE
Status StackEmpty( SqStack S)
{
  
    if(S.top==S.base)
    return TRUE;
    return FALSE;

}
//鈥斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€斺€?//
Status InitQueue(LinkQueue &Q)
{
    Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
    if(!Q.front) exit(OVERFLOW);
    Q.front->next=NULL;
    return OK;
}
//閿€姣侀槦鍒?
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
//鍏ラ槦 灏嗘柊鍏冪礌 e 鎻掑叆鍒伴槦灏? 鎴愪负鏂扮殑闃熷熬鍏冪礌 
Status EnQueue(LinkQueue &Q,ElemType e) {
    QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
    if(!p) exit(OVERFLOW);
    p->data=e; p->next=NULL;
    Q.rear->next=p;
    Q.rear=p;
    return OK;
}
//鍑洪槦	鍒犻櫎闃熷垪 Q 鐨勯槦澶村厓绱?	鐢? e 杩斿洖鍏跺€?
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
//閾鹃槦鍒? Q 鐨勬樉绀哄嚱鏁帮紝灏嗛槦鍒椾腑浠庨槦澶村埌闃熷熬姣忎釜鍏冪礌閮芥樉绀哄嚭鏉?
void QueueDisp(LinkQueue Q)
{
    QueuePtr p=Q.front->next;
    printf("\n 褰撳墠閾鹃槦鍒? Q 涓�鐨勬暟鎹�鏄�锛歕n");
    while(p)
    {
        printf("%d --> ",p->data);
        p=p->next;
    }
    printf("\n 閾鹃槦鍒楁暟鎹�鏄剧ず瀹屾瘯锛乗n\n");
}

int main()

{
    int ret;
    SqStack S;
    InitStack_Sq(S);
    LinkQueue Q;
    InitQueue(Q);
    srand((unsigned int)time(NULL));
    for(int i=0;i<10;i++)
    {
        ret = rand() % 100;//闅忔満鐢熸垚鏁?
        EnQueue(Q,ret);
    }
    printf("鍏ラ槦鍚庯細\n");
    QueueDisp(Q);

    QueuePtr p=Q.front->next;
    printf("\n 褰撳墠閾鹃槦鍒? Q 涓�鐨勬暟鎹�鏄�锛歕n");
    while(p)
    {
        Push(S,p->data);
        p=p->next;
    }
    InitQueue(Q);
    while(S.top!=S.base)
    {
        int &e=*--S.top;
        EnQueue(Q,e);
    }
    printf("鍏ラ槦鍚庯細\n");
    QueueDisp(Q);
    system("pause");
}
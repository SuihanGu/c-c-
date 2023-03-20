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
typedef int Status;
typedef int ElemType;

//Status 是函数的类型，其值是函数结果状态代码
typedef	int VRType; 
//VRType 是顶点关系类型。对于无向图，用 0 或 1 表示相邻否 
//对于带权图，则为权值类型。本例中权值为 int 型
typedef	int	VertexType;	
// VertexType 是顶点信息的类型。本例中顶点信息为 int 型
typedef struct Qnode
{
	ElemType data;
	struct Qnode *next;
}Qnode, *Qptr;     //定义节点

typedef struct{
	int adjvex;
	int lowcost;
}closedges[1000];     
typedef struct LINKQUEUE
{
	Qptr front;
	Qptr rear;
}LinkQueue; 

//-------图的邻接矩阵存储表示- ------
#define INFINITY 10000	//本例中 10000 代表无穷大
#define MAX_VERTEX_NUM 20
typedef enum{DG,DN,UDG,UDN} GraphKind;


typedef struct ArcCell{
	VRType adj;
	// VRType *Info;
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct{
	VertexType vexs[MAX_VERTEX_NUM];
	AdjMatrix	arcs;
	int	vexnum,arcnum;
	GraphKind	kind;
}MGraph;
Status CreateUDG(MGraph &G)
{
	printf("\n 请输入图中顶点个数和边的个数：\n");
	scanf("%d%d",&G.vexnum,&G.arcnum);
	int i,j,k,w;
	printf("\n 请依次输入图中各个顶点的信息：\n");
	for(i=0;i<G.vexnum;i++)
	scanf("%d",&G.vexs[i]);
	for(i=0;i<G.vexnum;i++)
		for(j=0;j<G.vexnum;j++)
			G.arcs[i][j].adj=INFINITY;
	printf("\n 请依次输入图中各个边的信息：顶点1 顶点2 权值\n");
	for(k=0;k<G.arcnum;k++)
	{
		scanf("%d%d%d",&i,&j,&w);
		G.arcs[i][j].adj=w;
		G.arcs[j][i].adj=w;
		//printf("%d %d\n",G.arcs[i][j].adj,G.arcs[j][i].adj);
	}
	
	return OK;
}
Status CreateGraph(MGraph &G)
{
	CreateUDG(G);
	return OK;
}
void print(MGraph G)
{
	int i,j;
	printf("\n 无向图中顶点个数=%d 个 ，边的个数=%d 条：\n",G.vexnum,G.arcnum);
	printf("\n 顶点信息如下：\n");
	for(i=0;i<G.vexnum;i++)
	{
		printf("%d\n",G.vexs[i]);
	}
	printf("\n 邻接矩阵如下：\n");
	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.vexnum;j++)
		{
			printf("%10d",G.arcs[i][j]);
		}
		printf("\n");
	}
}
//找 v 的第一个邻接点。若存在返回邻接点所在下标；若不存在，返回-1 
int FirstAdjVex(MGraph G, VertexType v) {
	int i;
	for(i=0;i<G.vexnum;i++)
	{
		if(G.arcs[v][i].adj==1) return i;	
	}	
	return -1;
}
//找 v 的下一个邻接点（相对于顶点 w）。若存在返回邻接点所在下标；若不存在，返回-1 
int NextAdjVex(MGraph G, VertexType v, VertexType w) {
	int i;	
	for(i=w+1;i<G.vexnum;i++)	
	{	
		if(G.arcs[v][i].adj==1) return i;	
	}	
	return -1;
}

bool visited[MAX_VERTEX_NUM]; 
//对图 G 作深度优先遍历
void DFS(MGraph G, int v)
{
	int w;
	visited[v]=TRUE;
	printf(" %d",v);
	for(w=FirstAdjVex(G,v); w>=0; w=NextAdjVex(G,v,w))
	if(!visited[w]) DFS(G,w);
}
//从第 v 个顶点出发递归地深度优先遍历图 G
void DFSTraverse(MGraph G)
{
	int v;
	for(v=0;v<G.vexnum;v++)
	visited[v]=FALSE;
	for(v=0;v<G.vexnum;v++)
	if(!visited[v]) DFS(G,v);
}
void InitQueue(LinkQueue *q) //队列初始化
{
	//定义头结点，队首队尾都指向头结点
	Qptr firstnode = (Qptr)malloc(sizeof(Qnode));
	q->front = q->rear = firstnode;
	if (!q->front)
	{
		exit(0);
	}
	q->front->next = NULL;
}
//入队列
void PushQueue(LinkQueue *q, ElemType e) 
{
	//在队尾插入元素
	Qptr p = (Qptr)malloc(sizeof(Qnode));
	if (!p)
	{
		exit(0);
	}
	p->data = e;
	p->next = NULL;
	q->rear->next = p;
	q->rear = p;
}
//出队列
void DetQueue(LinkQueue *q, ElemType &e)
{
	//出队列在队首进行
	if (q->front == q->rear)
	{
		printf("队列中无元素！\n");
		exit(0);
	}
	Qptr p = q->front->next;
	e = p->data;
	q->front->next = p->next;
	if (q->rear == p)
	{
		q->rear = q->front;
	}
	free(p);
}
//检验是否为空
int QueueEmpty(LinkQueue *q)
{
	if (q->front == q->rear)
		return 0;
	else
		return 1;
}
//广度优先非递归遍历图 G。使用辅助队列 Q 和访问标志数组 
void BFSTraverse( MGraph G ){
	int k;
	LinkQueue Q;
	InitQueue(&Q);
	for (int i = 0; i < G.vexnum; i++)
	{
		visited[i] = 0; //初始化标记数组
	}
	for (int i = 0; i < G.vexnum; i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			printf("%d ", G.vexs[i]);
			PushQueue(&Q, i);
		}
		while (QueueEmpty(&Q))
		{
			DetQueue(&Q, k);
			for (int j = 0; j < G.vexnum; j++)
			{
				if (G.arcs[k][j].adj == 1 && !visited[j])
				{
					visited[j] = 1;
					printf("%d ", G.vexs[j]);
					PushQueue(&Q, j);
				}
			}
		}
	}
	

}

//邻接矩阵顶点定位
int LocateVex(MGraph G,char v){
	int m;
	for(m=1;m<=G.vexnum;m++)
		if(G.vexs[m]==v)
			return m;
	return ERROR;
	return OK;
}

int Minimun(MGraph G,closedges m){
	int i,j,min=INFINITY;
	for(i=1;i<=G.vexnum;i++){
		if(m[i].lowcost){
			if(m[i].lowcost<min){
				min=m[i].lowcost;
				j=i;
			}
		}
	}
	return j;
}

//用普里姆算法从第 u 个顶点出发构造网 G 的最小生成树 T，输出 T 的各条边 
void MiniSpanTree_PRIM(MGraph G, VertexType u)
{
	int i,j,k;
	closedges closedge;
	printf("最小生成树：\n");
	k=LocateVex(G,u);
	for(j=1;j<=G.vexnum;j++){         //辅助数组初始化
		if(j!=k){
			closedge[j].adjvex=u;
			closedge[j].lowcost=G.arcs[k][j].adj;  
		}
	}
	closedge[k].lowcost=0;
	for(i=2;i<=G.vexnum;i++){
		k=Minimun(G,closedge);
		printf("%d-%d ",closedge[k].adjvex,G.vexs[k]);
		closedge[k].lowcost=0;
		for(j=1;j<=G.vexnum;j++)
			if(G.arcs[k][j].adj<closedge[j].lowcost){        //新顶点并入 U 后重新选择最小边
				closedge[j].adjvex=G.vexs[k];
				closedge[j].lowcost=G.arcs[k][j].adj;
			}
	}

}

int  main()

{
	MGraph G;	
	CreateGraph(G); //创建无向图的邻接矩阵	
	print(G); //显示邻接矩阵	
	printf("\n 下面是深度优先遍历结果：\n");	
	DFSTraverse(G);	
	printf("\n");
	printf("\n 下面是广度优先遍历结果：\n");
	BFSTraverse(G);
	printf("\n");

	MiniSpanTree_PRIM(G,1);
	system("pause");
}
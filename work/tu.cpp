#include<stdio.h>
#include<stdlib.h>
//��#define �궨����������ų�����//�������״̬����
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INSEASIBLE -1
#define OVERFLOW -2
//�� typedef �����������
typedef int Status;
typedef int ElemType;

//Status �Ǻ��������ͣ���ֵ�Ǻ������״̬����
typedef	int VRType; 
//VRType �Ƕ����ϵ���͡���������ͼ���� 0 �� 1 ��ʾ���ڷ� 
//���ڴ�Ȩͼ����ΪȨֵ���͡�������ȨֵΪ int ��
typedef	int	VertexType;	
// VertexType �Ƕ�����Ϣ�����͡������ж�����ϢΪ int ��
typedef struct Qnode
{
	ElemType data;
	struct Qnode *next;
}Qnode, *Qptr;     //����ڵ�

typedef struct{
	int adjvex;
	int lowcost;
}closedges[1000];     
typedef struct LINKQUEUE
{
	Qptr front;
	Qptr rear;
}LinkQueue; 

//-------ͼ���ڽӾ���洢��ʾ- ------
#define INFINITY 10000	//������ 10000 ���������
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
	printf("\n ������ͼ�ж�������ͱߵĸ�����\n");
	scanf("%d%d",&G.vexnum,&G.arcnum);
	int i,j,k,w;
	printf("\n ����������ͼ�и����������Ϣ��\n");
	for(i=0;i<G.vexnum;i++)
	scanf("%d",&G.vexs[i]);
	for(i=0;i<G.vexnum;i++)
		for(j=0;j<G.vexnum;j++)
			G.arcs[i][j].adj=INFINITY;
	printf("\n ����������ͼ�и����ߵ���Ϣ������1 ����2 Ȩֵ\n");
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
	printf("\n ����ͼ�ж������=%d �� ���ߵĸ���=%d ����\n",G.vexnum,G.arcnum);
	printf("\n ������Ϣ���£�\n");
	for(i=0;i<G.vexnum;i++)
	{
		printf("%d\n",G.vexs[i]);
	}
	printf("\n �ڽӾ������£�\n");
	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.vexnum;j++)
		{
			printf("%10d",G.arcs[i][j]);
		}
		printf("\n");
	}
}
//�� v �ĵ�һ���ڽӵ㡣�����ڷ����ڽӵ������±ꣻ�������ڣ�����-1 
int FirstAdjVex(MGraph G, VertexType v) {
	int i;
	for(i=0;i<G.vexnum;i++)
	{
		if(G.arcs[v][i].adj==1) return i;	
	}	
	return -1;
}
//�� v ����һ���ڽӵ㣨����ڶ��� w���������ڷ����ڽӵ������±ꣻ�������ڣ�����-1 
int NextAdjVex(MGraph G, VertexType v, VertexType w) {
	int i;	
	for(i=w+1;i<G.vexnum;i++)	
	{	
		if(G.arcs[v][i].adj==1) return i;	
	}	
	return -1;
}

bool visited[MAX_VERTEX_NUM]; 
//��ͼ G ��������ȱ���
void DFS(MGraph G, int v)
{
	int w;
	visited[v]=TRUE;
	printf(" %d",v);
	for(w=FirstAdjVex(G,v); w>=0; w=NextAdjVex(G,v,w))
	if(!visited[w]) DFS(G,w);
}
//�ӵ� v ����������ݹ��������ȱ���ͼ G
void DFSTraverse(MGraph G)
{
	int v;
	for(v=0;v<G.vexnum;v++)
	visited[v]=FALSE;
	for(v=0;v<G.vexnum;v++)
	if(!visited[v]) DFS(G,v);
}
void InitQueue(LinkQueue *q) //���г�ʼ��
{
	//����ͷ��㣬���׶�β��ָ��ͷ���
	Qptr firstnode = (Qptr)malloc(sizeof(Qnode));
	q->front = q->rear = firstnode;
	if (!q->front)
	{
		exit(0);
	}
	q->front->next = NULL;
}
//�����
void PushQueue(LinkQueue *q, ElemType e) 
{
	//�ڶ�β����Ԫ��
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
//������
void DetQueue(LinkQueue *q, ElemType &e)
{
	//�������ڶ��׽���
	if (q->front == q->rear)
	{
		printf("��������Ԫ�أ�\n");
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
//�����Ƿ�Ϊ��
int QueueEmpty(LinkQueue *q)
{
	if (q->front == q->rear)
		return 0;
	else
		return 1;
}
//������ȷǵݹ����ͼ G��ʹ�ø������� Q �ͷ��ʱ�־���� 
void BFSTraverse( MGraph G ){
	int k;
	LinkQueue Q;
	InitQueue(&Q);
	for (int i = 0; i < G.vexnum; i++)
	{
		visited[i] = 0; //��ʼ���������
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

//�ڽӾ��󶥵㶨λ
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

//������ķ�㷨�ӵ� u ��������������� G ����С������ T����� T �ĸ����� 
void MiniSpanTree_PRIM(MGraph G, VertexType u)
{
	int i,j,k;
	closedges closedge;
	printf("��С��������\n");
	k=LocateVex(G,u);
	for(j=1;j<=G.vexnum;j++){         //���������ʼ��
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
			if(G.arcs[k][j].adj<closedge[j].lowcost){        //�¶��㲢�� U ������ѡ����С��
				closedge[j].adjvex=G.vexs[k];
				closedge[j].lowcost=G.arcs[k][j].adj;
			}
	}

}

int  main()

{
	MGraph G;	
	CreateGraph(G); //��������ͼ���ڽӾ���	
	print(G); //��ʾ�ڽӾ���	
	printf("\n ������������ȱ��������\n");	
	DFSTraverse(G);	
	printf("\n");
	printf("\n �����ǹ�����ȱ��������\n");
	BFSTraverse(G);
	printf("\n");

	MiniSpanTree_PRIM(G,1);
	system("pause");
}
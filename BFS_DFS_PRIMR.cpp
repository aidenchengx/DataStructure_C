#include <stdio.h>
#include <malloc.h>

int visited[50];

typedef struct QNode{
	int data;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;
void InitQueue(LinkQueue &Q){
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
	Q.front->next=NULL;
}
void EnQueue(LinkQueue &Q,int e){
	QueuePtr p;
	p=(QueuePtr)malloc(sizeof(QNode));
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
} 

void DeQueue(LinkQueue &Q,int &e){
	QueuePtr p;
	if(Q.front==Q.rear) return;
	p=Q.front->next;
	e=p->data;
	Q.front->next=p->next;
	if (Q.rear==p) Q.rear=Q.front;
	free(p);
	return;
}

int QueueEmpty(LinkQueue Q){
	if (Q.front==Q.rear) return 1;
	else return 0;
}
typedef struct ArcCell{
	int adj;
}ArcCell,AdjMatrix[50][50];
typedef struct Graph{
	char vexs[50];
	AdjMatrix arcs;
	int vexnum,arcnum;//顶点数弧数
	int kind;//图的种类 
}Graph; 

void DFS(Graph G,int v){
	int w;
	printf("%c",G.vexs[v]);
	visited[v]=1;
	for(w=0;w<G.vexnum;w++)
	   if (G.arcs[v][w].adj&&(!visited[w])) DFS(G,w);
}

void DFSTraverse(Graph G){
	int v;
	for(v=0;v<G.vexnum;v++) visited[v]=0;
	for(v=0;v<G.vexnum;v++)
	if(!visited[v]) DFS(G,v);
}

void CreateDN(Graph &G){
	int i,j,w,k;
	char v1,v2,ch,c;
	printf("是否是有向图？输入Y/N\n");
	scanf("%c",&ch);
	fflush(stdin);
	if(ch=='Y') G.kind=1;	 
	printf("输入总顶点数以及弧/边数\n");
	scanf("%d %d",&G.vexnum,&G.arcnum);
	printf("输入顶点向量内容\n");
	fflush(stdin);
	for(i=0;i<G.vexnum;i++) {
		c=getchar();
		if(c==' ') i--;
		else G.vexs[i]=c;
	}
	for(i=0;i<G.vexnum;i++)
	  for(j=0;j<G.vexnum;j++)
	   G.arcs[i][j].adj=0;
    printf("输入这些向量连接到的顶点以及该边权值\n");
    fflush(stdin);
    for(k=0;k<G.arcnum;k++){
    	fflush(stdin);
	scanf("%c %c %d",&v1,&v2,&w);
	if(v1==v2) printf("Wrong input!");
	  for(i=0;i<G.vexnum;i++)
	    if(G.vexs[i]==v1) break;
	  for(j=0;j<G.vexnum;j++)
	    if(G.vexs[j]==v2) break; 
	G.arcs[i][j].adj=w;
	if(!G.kind) G.arcs[j][i].adj=w;
}
for(i=0;i<G.vexnum;i++)
 {printf("%c ",G.vexs[i]);
 for(j=0;j<G.vexnum;j++)
   printf("%d ",G.arcs[i][j].adj);
 printf("\n");
 
}}

void BFSTraverse(Graph G,LinkQueue &Q){
	int v,w,u;
	for (v=0;v<G.vexnum;v++) visited[v]=0;
	InitQueue(Q);
	for (v=0;v<G.vexnum;v++) if(!visited[v]){
		visited[v]=1;
		printf("%c",G.vexs[v]);
		EnQueue(Q,v);
		while(!QueueEmpty(Q)){
			DeQueue(Q,u);
		//	printf("%d \n",u);
			for(w=0;w<G.vexnum;w++)
			if(G.arcs[u][w].adj&&(!visited[w])) 
			{
				visited[w]=1;
				printf("%c",G.vexs[w]);
				EnQueue(Q,w);
			}
		}
	}
} 

void MiniTree(Graph G){
int j,i,min=0,k,t,s;
struct{char adjvex;
int lowcost;
}closedge[50];
 //min=G.arcs[0][1].adj;

 for(j=1;j<G.vexnum;j++)
  {if  (G.arcs[0][j].adj==0) continue;
else if(min==0) {k=j;min=G.arcs[0][j].adj;}
else if(G.arcs[0][j].adj<min){k=j;min=G.arcs[0][j].adj;
}}

 printf("k=%d",k);
 printf("%c ",G.vexs[0]);
 for(j=0;j<G.vexnum;j++)
 if(j!=k) {closedge[j].adjvex=G.vexs[0];closedge[j].lowcost=G.arcs[k][j].adj;}
  printf("%c %c ",closedge[k].adjvex,G.vexs[k]);
 closedge[k].lowcost=0;
 for(i=1;i<G.vexnum;i++)
 {s=k;
 min=0;
 for(t=0;t<G.vexnum;t++)
 {if(closedge[t].lowcost==0) continue;
 else if  (G.arcs[s][t].adj==0) continue;
else if(min==0) {k=j;min=G.arcs[s][j].adj;}
else if(G.arcs[s][j].adj<min){k=j;min=G.arcs[s][j].adj;
 }}
 printf("%c %c",closedge[k].adjvex,G.vexs[k]);
 closedge[k].lowcost=0;
 for(j=0;j<G.vexnum;j++)
 if(G.arcs[k][j].adj<closedge[j].lowcost)
   closedge[j].adjvex=G.vexs[k];
   closedge[j].lowcost=G.arcs[k][j].adj;
 }
}
int main()
{{}
Graph Gr;
LinkQueue Q;
CreateDN(Gr);
printf("DFS:");
DFSTraverse(Gr);
printf("\nBFS:"); 
BFSTraverse(Gr,Q);

MiniTree(Gr);
}

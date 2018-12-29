#include <stdio.h>
#include <malloc.h>
#define INT_MAX 100000
typedef struct ArcCell{
	int adj;
	//char *info;
}ArcCell,AdjMatrix[50][50];
typedef struct Graph{
	char vexs[50];
	AdjMatrix arcs;
	int vexnum,arcnum;//顶点数弧数
	int kind;//图的种类 
}Graph; 
void CreateDN(Graph &G){
	int i,j,w,k;
	char v1,v2,ch,c;
	G.kind=0;
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
	   G.arcs[i][j].adj=INT_MAX;
    printf("输入这些向量连接到的顶点及该边权值\n");
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
   //if(IncInfo) Input(*G.arcs[i][j].info)
 printf("\n");
 
}}
void Dijkstra(Graph G,int v0,int D[100],int P[][100]){
	int S[100]={0};
	int i,j,s,w,k=0,min,t;
	for(i=0;i<G.vexnum;i++) 
	  {D[i]=G.arcs[v0][i].adj;
	     if(D[i]<INT_MAX){
	     P[i][0]=v0;P[i][1]=i;P[i][2]=-1;
		 }
	   else D[i]=D[i];
      }
    S[v0]=1;
    D[v0]=0;
    fflush(stdin);
    for(i=1;i<G.vexnum;i++){
    	min=INT_MAX;
    	for(j=0;j<G.vexnum;j++)
    	if (!S[j]&&D[j]<min) {s=j;min=D[j];
		}
	S[s]=1;
	/*	printf("数组P的状态：");
		 for(k=0;P[s][k]!=-1;k++)
	  printf("%c ",G.vexs[P[s][k]]);
	  	printf("\n数组D的状态："); 
		  for(t=0;t<G.vexnum;t++)
	 printf("%d\n",D[t]); 
	 	printf("\n数组S的状态："); 
	 	for(t=0;t<G.vexnum;t++)
	 printf("%d\n",S[t]); 
	//  printf("%d ",k);
	  printf("\n"); 
	  getchar();*/
	for(j=0;j<G.vexnum;j++)
	   if(!S[j]&&(D[s]+G.arcs[s][j].adj<D[j])){
	 	 D[j]=D[s]+G.arcs[s][j].adj;
	     for(w=0;P[s][w]!=-1;w++) P[j][w]=P[s][w];
	     P[j][w]=j;P[j][w+1]=-1;
	 }
	}
	for(i=1;i<G.vexnum;i++)
	{if(D[i]>=INT_MAX) {printf("没有路径");continue;
	}
	printf("%c->%c  %d ",G.vexs[v0],G.vexs[i],D[i]); 
	   for(w=0;P[i][w]!=-1;w++)
	   printf("%c ",G.vexs[P[i][w]]);
	   printf("\n");}
	
	}
	
int main(){
	int D[100],S[100][100];
fflush(stdin);
Graph Gr,Gs;
/*CreateDN(Gr);
int adjvex[Gr.vexnum];
printf("Prim:\n"); 
Prim(Gr,0,adjvex);
printf("Kruskal:\n");
Krusal(Gr);*/
CreateDN(Gs);
Dijkstra(Gs,0,D,S);
} 

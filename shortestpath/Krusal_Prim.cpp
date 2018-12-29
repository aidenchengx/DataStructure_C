#include <stdio.h>
#include <malloc.h>
#include <climits>
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
void Prim(Graph G,int v0,int adjvex[]){							//v0是起始点 
  int lowcost[50];
  int i,j,k,t;
  for(j=0;j<G.vexnum;j++)
    if(j!=v0){
    	if(G.arcs[v0][j].adj)lowcost[j]=G.arcs[v0][j].adj;		//初始化对应节点的 lowcost 
    	else lowcost[j]=INT_MAX;
    	adjvex[j]=v0;
	}
	lowcost[v0]=0;
	for(i=1;i<G.vexnum;i++){
	
	{k=-1;
	for(j=0;j<G.vexnum;j++)
	  {if(!lowcost[j]) continue;								//节点已经在U集合中 ，防止成环 
	   if(k<0) k=j;
	   if(lowcost[j]<lowcost[k]) k=j;							//如果有一个边lowcost小于当前值 
	  }
	}
	 printf("(%c,%c),%d\n",G.vexs[adjvex[k]],G.vexs[k],lowcost[k])
	;
	lowcost[k]=0;
	for(j=0;j<G.vexnum;j++){									//对于新加入的节点 调整lowcost 
		if(G.arcs[k][j].adj<lowcost[j])
		{adjvex[j]=k;											//更新点信息 
		lowcost[j]=G.arcs[k][j].adj;
		}
	}
	}
}

void Krusal(Graph G){
    int i,j,k,t=-1,s,p=0,v0,v1;
    int T[G.vexnum];              //表示该结点目前所属的集合编号 
 struct node{ 
    int arcs;
    int adj;
    int weight;
 }node[10000];
   

    for(i=0;i<G.vexnum;i++)
      for(j=i+1;j<G.vexnum;j++)
        if(G.arcs[i][j].adj<INT_MAX) {
		    t++;
        	node[t].arcs=i;
        	node[t].adj=j;
        	node[t].weight=G.arcs[i][j].adj;
		}

	for(i=0;i<G.vexnum;i++) T[i]=0;
	for(i=1;i<G.vexnum;i++)
	  {s=0;
	   for(j=0;j<=t;j++) if(node[j].weight<node[s].weight) s=j;
	   v0=node[s].arcs;
	   v1=node[s].adj;
       if(!T[v0]&&!T[v1])
	        {T[v0]=++p;T[v1]=p;printf("(%c,%c),%d\n",G.vexs[v0],G.vexs[v1],node[s].weight);
			 node[s].weight=INT_MAX;}  //两个未被纳入集合的点形成路径 
	   else if(!T[v0]||!T[v1])
	        {printf("(%c,%c),%d\n",G.vexs[v0],G.vexs[v1],node[s].weight);
	         if(!T[v0]) T[v0]=T[v1] ;else T[v1]=T[v0];      
			 node[s].weight=INT_MAX;              
	        }                          //集合并入新的单节点 
       else if(T[v0]==T[v1]) 
	        {node[s].weight=INT_MAX;i--;} //同一集合节点并选中则重新筛选 
	   else if(T[v0]!=T[v1]) 
	        {printf("(%c,%c),%d\n",G.vexs[v0],G.vexs[v1],node[s].weight); 
	         for(j=0;j<G.vexnum;j++) if(T[j]==T[v1]) T[j]=T[v0];
	         node[s].weight=INT_MAX;
	        }                            //不同集合节点，不同集合合并成同一集合 
}} 



int main(){
	int D[100],S[100][100];
fflush(stdin);
Graph Gr,Gs;
CreateDN(Gr);
int adjvex[Gr.vexnum];
printf("Prim:\n"); 
Prim(Gr,0,adjvex);
printf("Kruskal:\n");
Krusal(Gr);

} 

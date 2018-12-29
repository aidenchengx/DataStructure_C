#include <stdio.h>
#include <malloc.h>
#define status int
#define OK 1
#define ERROR 0
#include <math.h>
typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild;
	int ask;                                //用于记录后序遍历访问次数 
}BiTNode,*BiTree;                           //树的定义 

status CreateBiTree(BiTree &T){
	char ch;
	scanf("%c",&ch);
	if(ch=='#') {T=NULL;return OK;}
	T=(BiTree)malloc(sizeof(BiTNode));
	T->data=ch;
	T->ask=0;
	CreateBiTree(T->lchild);
	CreateBiTree(T->rchild);
	return OK;
}                                           //树的构造 

typedef struct Stack{
	BiTree* top;
	BiTree* base;
	int stacksize;
}Stack;                                     //栈的定义 

status CreateStack(Stack &S){
	BiTree bt;
    S.base=(BiTree*)malloc(100*sizeof(BiTree)); 
	if(!S.base) return ERROR;
	S.top=S.base;
	return OK;
}                                          //栈的构造

typedef struct QNode{
	BiTree data;
	struct QNode *next; 
}QNode,*QueuePtr;

typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;                               //队列的定义及构造 

status InitQueue(LinkQueue &Q){
	Q.front=(QueuePtr)malloc(sizeof(QNode));
	Q.rear=Q.front;
	Q.rear->next=NULL;
}

status EnQueue(LinkQueue &Q,BiTree bt){
	QueuePtr q;
	q=(QueuePtr)malloc(sizeof(QNode));
	q->data=bt;
	q->next=NULL;
	Q.rear->next=q;
	Q.rear=q;
}

status DeQueue(LinkQueue &Q,BiTree &bt){
	QueuePtr q,r;
	if(Q.front==Q.rear) return ERROR;
	q=Q.front->next;
	bt=q->data;
    Q.front->next=q->next;
    if(Q.rear==q) Q.rear=Q.front; 
	free(q);
	return OK;
}

int QueueEmpty(LinkQueue Q){
	if(Q.rear==Q.front) return 1;
	return 0;
}

status DestroyQueue(LinkQueue &Q){
	while(Q.front){
		Q.rear=Q.front->next;
		free(Q.front);
		Q.front=Q.rear;
	}
	return OK;
}

status Pop(Stack &S,BiTree &bt){
	if(S.top==S.base) return ERROR;
	else{bt=*--S.top;
   	} 
	return OK;
}
status Push(Stack &S,BiTree bt){
	if(S.top-S.base>=S.stacksize) return ERROR;
	*(S.top++)=bt;
	return OK;
}

int StackEmpty(Stack S){
	if(S.base==S.top) return 1;
	else return 0;
}
status DestroyStack(Stack &S){
	free(S.base);
	return OK;
}

void PreOrder(BiTree T){
	if(T==NULL) {
	return;
	}
    printf("%c ",T->data);
    PreOrder(T->lchild);
    PreOrder(T->rchild);
}                             //先序遍历 

void InOrder(BiTree T){
	if(T==NULL){
	return;}
	InOrder(T->lchild);
	printf("%c ",T->data);
	InOrder(T->rchild); 
}                            //中序遍历 

void PostOrder(BiTree T){
	if(T==NULL){
	return;
	}
	PostOrder(T->lchild);
	PostOrder(T->rchild);
	printf("%c ",T->data);
}                          //后序遍历 

void levelTraversal(BiTree T){
	LinkQueue Q;
	BiTree bt;
	if(T==NULL) return ;
	InitQueue(Q);
	EnQueue(Q,T);
	while(!QueueEmpty(Q)){
		DeQueue(Q,bt);
		printf("%c ",bt->data);
		if(bt->lchild!=NULL) EnQueue(Q,bt->lchild);
		if(bt->rchild!=NULL) EnQueue(Q,bt->rchild);
	}
	DestroyQueue(Q);
}                                //层序遍历 

void preOrder(BiTree T){
	BiTree bt=T;
	Stack S;
	CreateStack(S);
	if(!bt) return;
	Push(S,bt);
    while(!StackEmpty(S)){
	  Pop(S,bt);
      while(bt){
    	printf("%c ",bt->data);
    	if (bt->rchild) Push(S,bt->rchild);
        bt=bt->lchild;
	    }
	}
  DestroyStack(S);
};                                         //非递归先序遍历 

void inOrder(BiTree T){
	BiTree bt=T;
	Stack S;
	CreateStack(S);
	while(bt||!StackEmpty(S)){
		if(bt){
		Push(S,bt);
		bt=bt->lchild;}
else{ Pop(S,bt);
	  printf("%c ",bt->data);
	  bt=bt->rchild;}
	  }
	DestroyStack(S);
}                                              //非递归中序遍历 

void postOrder(BiTree T){
	BiTree bt=T,bt0;
	Stack S;
	CreateStack(S);
	while(bt||!StackEmpty(S)){
    if(bt) {
	        if(bt->ask==0)
			    {Push(S,bt);
	            bt->ask++;
	            bt=bt->lchild;
				}
	        else if(bt->ask==1)
	            {Push(S,bt);
	            bt->ask++;
	            bt=bt->rchild; 
	            }
	        else{
	            printf("%c ",bt->data);
	            if(!Pop(S,bt)) bt=NULL;
	            }
			continue;
			}
	if(!bt) {
	      Pop(S,bt);
		  }
	}
	DestroyStack(S); 
}                                            //非递归后序遍历 


int depth(BiTree T){
	if(!T) return 0;
	int xl,xr,max;
    xl=depth(T->lchild);
    xr=depth(T->rchild);
    if(xl>xr) max=xl;
    else max=xr;
	return	max+1;
	}                                //求树的深度
	
int CountNodes(BiTree T){
	if(!T) return 0;
	int k;
	return CountNodes(T->lchild)+CountNodes(T->rchild)+1;
} 

int GetNumBiTree(BiTree T,int K){
	int l1,l2;
	if(T==NULL) return 0;
	if(K==1) return 1;
	return 	GetNumBiTree(T->lchild,K-1)+GetNumBiTree(T->rchild,K-1);
}

int Sign(BiTree T,int K,int a[],int &e){
	int l1,l2;
	if(T==NULL) {e+=(int)pow(2,K-1);return 0;}
	if(K==1) {a[e++]=1;return 1;}
	return 	Sign(T->lchild,K-1,a,e)+Sign(T->rchild,K-1,a,e);
}

int JudgeCompleteBiTree(BiTree T){
	if(!T) return 0;
	int d=depth(T),q=0,s=1,i=1,r,p,min,max,j;
	if(d==1) return 1;
	for(i=1;i<=d-1;i++){
		r=GetNumBiTree(T,i);
		p=(int)pow(2,i-1);
        if(r!=p) break;
	}
    if(i!=d) return 0;	
	p=(int)pow(2,i-1);
	j=GetNumBiTree(T,i);
    int a[p];
    for(i=0;i<p;i++) a[i]=0;
    Sign(T,d,a,q);
    for(i=0;i<p;i++) if(!a[i]) break;
    if(i==j) return 1;
    else return 0;
}
int main(){
	BiTree T,T2;
    CreateBiTree(T);
	int K,d;
	printf("\n先序遍历：");
	PreOrder(T);
	printf("\n中序遍历：");
	InOrder(T);
	printf("\n后序遍历：");
	PostOrder(T);
	printf("\n层序遍历：");
    levelTraversal(T);
    printf("\n非递归先序遍历：");
    preOrder(T);
    printf("\n非递归中序遍历：");
    inOrder(T);
    printf("\n非递归后序遍历：");
    postOrder(T);
    printf("\n树的深度为：");
    printf("%d ",d=depth(T));
    printf("\n树的结点数为：");
    printf("%d ",CountNodes(T));
    for(int i=1;i<=d;i++)
   {printf("\n树第%d层的结点数为：",i);
    printf("%d ",GetNumBiTree(T,i));}
    if(JudgeCompleteBiTree(T)) printf("\n该树是完全二叉树\n");
    else printf("\n该树不是完全二叉树\n");
    printf("继续输入第二棵树判断\n");
    fflush(stdin);
    CreateBiTree(T2);
    if(JudgeCompleteBiTree(T2)) printf("\n该树是完全二叉树\n");
    else printf("\n该树不是完全二叉树");
	}













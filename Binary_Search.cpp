#include<malloc.h>
#include<stdio.h>
typedef struct BiTNode{
	int data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
int a[12]={19,7,16,28,36,23,9,5,14,58,2,30};
//int CreateBiTree(BiTree &T){}
int InsertBiTree(BiTree &T,int e){
	BiTNode *p,*q,*rear;int r;
	p=(BiTree)malloc(sizeof(BiTNode));
	p->data=e;
	p->lchild=NULL;
	p->rchild=NULL;
	if(!T){T=p;return 1;
	}
	rear=q=T;
	while(q){rear=q;
	//printf("%d ",q->data);
	if(e>q->data) {q=q->rchild;r=0;}
	else {q=q->lchild;r=1;}
	
	}
	if(r==0) rear->rchild=p;
	else if(r==1) rear->lchild=p;
}	
int PrintElement(int e){
	printf("%d ",e);
	return 1;
}
int MiddleOrderTraverse(BiTree T,int (*Visit)(int e)){

	if(T){ 
	if(MiddleOrderTraverse(T->lchild,Visit))
    if(Visit(T->data)) 
	if(MiddleOrderTraverse(T->rchild,Visit)) return 1;
	return 0;
}else return 1;
}
int ASLcaculate(BiTree T){
	int i,count=0,s=1;
	float ASL;
	BiTNode *p;
	
	for (i=0;i<=11;i++){
	p=T;s=1;
	while(p->data!=a[i]){
	count++;	s++;
	if(a[i]>p->data) p=p->rchild;
	else if(a[i]<p->data) p=p->lchild;	
//	printf()
	}
	count++;
//	printf("%d ",count);
	//printf("%d ",s);
	
	}ASL=float(count)/12;
	printf("\nASL=%f",ASL);
}
int main(){
	int i;
	BiTree T;
	for(i=0;i<12;i++)
	InsertBiTree(T,a[i]);
    MiddleOrderTraverse(T,PrintElement)
;
ASLcaculate(T);}

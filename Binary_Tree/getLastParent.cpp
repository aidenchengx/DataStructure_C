#define status int
#define OK 1
#define ERROR 0
#define True 1
#define False 0
typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;                           //树的定义 

status CreateBiTree(BiTree &T){
	char ch;
	scanf("%c",&ch);
	if(ch=='#') {T=NULL;return OK;}
	T=(BiTree)malloc(sizeof(BiTNode));
	T->data=ch;
    CreateBiTree(T->lchild);
	CreateBiTree(T->rchild);
	return OK;
}                                           //树的构造 

bool IsInTree(BiTree T,BiTree R){
	if(!T) return False;
	if(T==R) return True;
	if(IsInTree(T->lchild,R)) return True;
	if (IsInTree(T->rchild,R)) return True;
	return False;
}

BiTree GetLastParent(BiTree pRoot,BiTree P1,BiTree P2){
	BiTree k;
    if(!IsInTree(pRoot,P1)||!IsInTree(pRoot,P2)) return NULL;	
	if(pRoot==P1||pRoot==P2) return pRoot;
	k=GetLastParent(pRoot->lchild,P1,P2);
	if(!k) k=GetLastParent(pRoot->rchild,P1,P2);
	if(!k) k=pRoot;
	return k;
}

void Treversal(BiTree T,BiTree &P,char ch){	
    if(T==NULL){
	return;}
	Treversal(T->lchild,P,ch);
    if(T->data==ch) {P=T;}
	Treversal(T->rchild,P,ch); 
}

int main(){
	BiTree T,R1=NULL,R2=NULL,P1=NULL,P2=NULL,Q;
	char ch;
	CreateBiTree(T);
	printf("请输入这个结点和子树根节点 示例1,2\n");
	fflush(stdin);
	ch=getchar(); 
	Treversal(T,R1,ch);
	ch=getchar(); 
	ch=getchar(); 
	Treversal(T,R2,ch);
	if(!R1||!R2) printf("你输入的结点不全存在于该树中\n"); 
	if(IsInTree(R2,R1))printf("结点%c存在于%c子树中\n",R1->data,R2->data);
	 else printf("结点%c不存在于%c子树中\n",R1->data,R2->data);
	printf("请输入两个结点 示例1,2\n");
	fflush(stdin);
	ch=getchar();
	Treversal(T,P1,ch);
	ch=getchar();
	ch=getchar();
	Treversal(T,P2,ch);
    Q=GetLastParent(T,P1,P2);
	if(Q)printf("最低公共父节点%c",Q->data);
	else printf("这两个结点不都存在于该树中！！");
}

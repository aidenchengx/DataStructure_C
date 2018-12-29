#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <iostream>
typedef char *str,st,*str1;
int num,k=1,t=1;//t表示电文字母种类数 num表示电文字符总数 
typedef struct character{
	char ch;
	int count;
}*cha,chanode;
typedef struct Tree{
	int weight;
	int parent,lchild,rchild;
}HTNode,*HuffmanTree;
typedef char **HuffmanCode;
//cha用来记录对应字母的出现次数，HuffmanTree用来记录生成树，HuffmanCode用来记录对应节点序号的编码
 
void Getch(str &S){
	//str &s;
	num=0;
	char c;int i=1,t=1;
	printf("请输入电文\n"); 
	fflush(stdin);
	S=(str)malloc(100*sizeof(st));
	while(1){
		scanf("%c",&c);
		S[i]=c;
		i++;
	//	printf("%c",c);
		if(c=='\n') {break;}
	}//printf("1");
	num=i-2;
	fflush(stdin);
	return;
}

void print(cha C,int n){
	int i;
//	printf("%d",n);
	for(i=1;i<=n;i++)printf("%c %d\n",C[i].ch,C[i].count);
	
}
void print1(HuffmanTree HT,int t){
	int i;
	for(i=1;i<=t;i++)
	printf("%d,%d,%d,%d\n",HT[i].parent,HT[i].weight,HT[i].lchild,HT[i].rchild);
}

void choose(HuffmanTree HT,int k,int &k1,int &k2){
	int i;
	k1=0;k2=0;
	for(i=1;i<=k;i++){ 
		if(HT[i].parent!=0) continue;
		if(k1==0) {k1=i;continue;
		}
		else if(HT[i].weight<HT[k1].weight) k1=i;} //printf("print1");
	for(i=1;i<=k;i++){
		//printf("i=%d\n",i);
		if(HT[i].parent!=0) continue;
		if(i==k1) continue;
	    if(k2==0){k2=i;continue;}
		else if (HT[i].weight<HT[k2].weight) k2=i;}
        
}
void CreateHuffmanTree(HuffmanTree &HT,HuffmanCode &HC,cha C,int n){
	HuffmanTree p;
	
	int k1=0,k2=0,start,c,f;
	int m,i;
	if(n<=1) return ;
	m=2*n-1;                   //n种字母需要2n-1个结点 
	HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode)); //开空间 
		for(i=1;i<=t;i++){
		HT[i].parent=0;//printf("++");
		HT[i].weight=C[i].count;
		HT[i].lchild=0;
		HT[i].rchild=0;
	}
   //print1(HT,t);
	for(i=n+1;i<=m;i++){
		choose(HT,i-1,k1,k2);
	//	printf("k1=%d,k2=%d\n",k1,k2);
		HT[k1].parent=i;
		HT[k2].parent=i;
		HT[i].parent=0;
		HT[i].lchild=k1;
		HT[i].rchild=k2;
		HT[i].weight=HT[k1].weight+HT[k2].weight;
	//	print1(HT,i);
	};printf("树已生成！");

}
void HuffmanCoding(HuffmanTree HT,HuffmanCode &HC,cha C,int n){
	char* cd;
	int start,f,c,i;
	HC=(HuffmanCode)malloc((n+1)*sizeof(char *));//分配n个字母的头指针向量 0号不用 
	cd=(char*)malloc(n*sizeof(char)); //分配编码的工作空间 
	cd[n-1]='\0';
	for(i=1;i<=n;i++){
		start=n-1;//printf("++");
		for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent)
		 { if(HT[f].lchild==c) cd[--start]='0';
		  else cd[--start]='1';}
		  HC[i]=(char*)malloc((n-start)*sizeof(char));//printf("++");
		  strcpy(HC[i],&cd[start]);//printf("++");
	}
	free(cd);
    for(i=1;i<=n;i++) {printf("%c:",C[i]);puts(HC[i]);}
}


void Statistic(str S,cha &C,HuffmanTree &HT){
	int i,j;
	C=(cha)malloc(num*sizeof(chanode));
	C[1].ch=S[1];
	C[1].count=1;
	for (i=2;i<=num;i++){	
	  for (j=1;j<=t;j++){
	   if (S[i]==C[j].ch) {C[j].count++;break;}
	   }	   
	   if(j==t+1){
		//printf("!");
		t++;
	C[t].ch=S[i];
	C[t].count=1;
	}
	}	printf("数据统计完成！");

	//printf("t=%d",t);

};
void translate(str S,str1 &S1,cha C,HuffmanCode HC,int n){
   int i,j,m=1,co=1;
   str1 p; 
   S1=(str1)malloc(num*sizeof(st));
   for(i=1;i<=num;i++){
   	for(j=1;j<=n;j++)
   	if(S[i]==C[j].ch) {fputs(HC[j],stdout);
	m=0;
    while(1){
    if(HC[j][m]=='\0') {//printf("++");
	break; }
    //printf("()c=%d()",HC[j][m]);
   	S1[co]=HC[j][m];
   	co++;
	m++;
//	printf("m=%d",m);
   }
   }
   }
   S1[co]='\0';
   printf("\n");
  // for(i=1;i<=co;i++) printf("%c",S1[i]);
}

void print2(str1 S1,cha C,HuffmanTree HT,int n){
	int i=1,j=1,c=2*n-1;
	while(1)
     {if(S1[i]=='\0') {printf("\n");break;}
    // printf("%c %d\n",S1[i],i);
	 if(S1[i]=='0') c=HT[c].lchild;
      else c=HT[c].rchild;
     // printf("c=%d\n",c);
      if (HT[c].lchild==0&&HT[c].rchild==0) {printf("%c",C[c].ch);c=2*n-1;}
      i++;
	 }
//	 printf("\n");
}
int main(){
int a; 
char *str,*str1;
character *cha;
Tree *HuffmanTree;
char **HuffmanCode;
ep:printf("1:输入电文\n2:统计数据\n3:打印数据\n4:创建哈弗曼树\n5:打印树\n6:哈弗曼编码\n7:翻译\n8:还原电文\n9:退出\n");
fflush(stdin);
scanf("%d",&a);
//str[0]=0;

switch(a){
	case 1:Getch(str);break;
	case 2:Statistic(str,cha,HuffmanTree);break;
	case 3:print(cha,t);break;
    case 4:CreateHuffmanTree(HuffmanTree,HuffmanCode,cha,t);break;
    case 5:print1(HuffmanTree,2*t-1);break;
    case 6:HuffmanCoding(HuffmanTree,HuffmanCode,cha,t);break; 
    case 7:translate(str,str1,cha,HuffmanCode,t);break;
    case 8:print2(str1,cha,HuffmanTree,t);break;
    case 9:exit(0);break;
}
goto ep;
}

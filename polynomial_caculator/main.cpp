#include <stdio.h>
#include <malloc.h>
#include <math.h>
typedef struct poly{
	float xishu;
	float cishu;
	struct poly *next;
}poly,*Linklist;
poly *a[51];
typedef char cha;
typedef int num;
typedef struct{
	num *base;
	num *top;
	int height;
	int size;
}SqStack1;
typedef struct {
	cha *base;
	cha *top;
	int height;
	int size;
}SqStack2;
int InitStack1(SqStack1 &S)
{   S.base=(num*)malloc(100*sizeof(num));
    S.top=S.base;
    S.size=100;
}
int InitStack2(SqStack2 &S)
{   S.base=(cha*)malloc(100*sizeof(cha));
    S.top=S.base;
    S.size=100;
}
int GetTop1(SqStack1 &S){
	num e;
	if (S.top==S.base) return 0;
	e=*(S.top-1);
	return e;
}
cha GetTop2(SqStack2 &S){
	cha e;
	if (S.top==S.base) return 0;
	e=*(S.top-1);
	return e;
}
int Push1(SqStack1 &S,num e){
	if(S.top-S.base>=100){};
	*S.top++=e;
	return 1;
}
int Push2(SqStack2 &S,cha e){
	if(S.top-S.base>=100){};
	*S.top++=e;
	return 1;
}
int Pop1(SqStack1 &S,num &e){
	if(S.top==S.base) return 0;
	e=*--S.top;
	return 1;
}
int Pop2(SqStack2 &S,cha &e){
	if(S.top==S.base) return 0;
	e=*--S.top;
	return 1;
}
int DestroyStack1(SqStack1 &S){
	free(S.base);
	S.top=NULL;
	S.size=0;
  //  S.height=0;
	return 1;
    
}


void initlist(Linklist &L){

	int i;
	L=(Linklist)malloc(sizeof(poly));
    L->next=NULL;
}


void check0(int no3){
	poly *t,*rear,*p;
	 // printf("++");
		   {t=a[no3]->next;
	    rear=a[no3];
	       while(t){
		    if((fabs(t->xishu))<=0.001) {rear->next=t->next;p=rear->next;t=t->next;free(p);continue;}
		    else rear=rear->next;
		   t=t->next;
	       }
	       if(a[no3]->next==NULL) {p=(Linklist)malloc(sizeof(poly));p->xishu=0;p->cishu=0;p->next=NULL;a[no3]->next=p;}
	}//检查有无系数为0的结点 
	//printf("check0\n");
	} 

int add(Linklist &L,float xi,float ci){
    poly *rear,*head,*q,*t;
	q=head=L;
//	 printf("--");
    while(q->next)  {
    	if(q->next->cishu==ci)
		  {q->next->xishu+=xi;
    	    return(0);}
        if(q->next->cishu>ci){
        rear=q;
	    q=(Linklist)malloc(sizeof(poly));
        q->xishu=xi;q->cishu=ci;q->next=rear->next;
        rear->next=q;
		return(0);
		}
    	q=q->next;
		  }//endwhile
	if (q->next==NULL) 
	 {  rear=q;
	    q=(Linklist)malloc(sizeof(poly));
        q->xishu=xi;q->cishu=ci;q->next=NULL;
        rear->next=q;
		return(0);}
     }
	  


void create(Linklist &L,int no){
	float  x,c;
//	poly *a[10];
	int t;
	initlist(L);
	printf("请输入系数 次数 以及存储单位 注：系数为0时视为结束输入\n");
    scanf("%f %f",&x,&c);
    	initlist(L);	a[no]=L; 
    //printf("%f,%f",x,c);
    while(1){
    	add(L,x,c);
    	//printf("%f-%f",)
    	scanf("%f",&x);
    	if (x==0) break;
    	scanf("%f",&c);
	}

}

void print(Linklist L){
	int i;
	poly *q=L;//poly *t;
 for (i=0;i<=10;i++){
   q=a[i];//t=q->next;
   if (q==NULL) {printf("%d:NULL!\n",i);continue;}
   printf("%d:",i);
	while (q->next){
		q=q->next;
		if(q!=a[i]->next){if(q->xishu>0) printf("+%0.2f",q->xishu);
		else printf("%0.2f",q->xishu);
		}
		else printf("%0.2f",q->xishu);
//	printf("%0.2f",q->xishu);
		if(q->cishu==0) ;
		else if(q->cishu==1) printf("x");
		else if(q->cishu>0) printf("x^%0.1f",q->cishu);
		else if(q->cishu<0) printf("x^(%0.1f)",q->cishu);
		//q=q->next;
		//if(q->next==NULL) break;
		//printf("+");
	}
	printf("\n");
}
/* for (i=21;i<=30;i++){
   q=a[i];//t=q->next;
   if (q==NULL) {printf("%d:NULL!\n",i);continue;}
   printf("%d:",i);
	while (q->next){
		q=q->next;
		if(q!=a[i]->next){if(q->xishu>0) printf("+%0.2f",q->xishu);
		else printf("%0.2f",q->xishu);
		}
		else printf("%0.2f",q->xishu);
//	printf("%0.2f",q->xishu);
		if(q->cishu==0) ;
		else if(q->cishu==1) printf("x");
		else if(q->cishu>0) printf("x^%0.1f",q->cishu);
		else if(q->cishu<0) printf("x^(%0.1f)",q->cishu);
		//q=q->next;
		//if(q->next==NULL) break;
		//printf("+");
	}
	printf("\n");
}*/
}


int copy(int no,int no1){
	if (a[no]==NULL) {printf("%d %d",no,no1);printf("该多项式为空！!\n");return(0);
	}
	if(no==no1) return(0);
	initlist(a[no1]);
	poly *p=a[no],*q,*rear;
	rear=q=a[no1];
	p=a[no];
	while (p->next)
        {q=(Linklist)malloc(sizeof(poly));
         p=p->next;
           q->xishu=p->xishu;
           q->cishu=p->cishu;
        q->next=p->next;
        rear->next=q;
        rear=rear->next;
    //printf("%f %f",q->xishu,q->cishu);
    //p=p->next;
        }
    return(1);
};


int destroy(int no){
	poly *p,*q;
	if(!(p=a[no])) return(1);
	//p=q;
	while(p){
	   q=p;
	   p=p->next;
	   free(q);	
	}
	a[no]=NULL;
	return(1);
};

void destruct(){
	int i;
	for(i=0;i<=9;i++)
	destroy(i);
}

int xiangjia1(int no1,int no2,int no3){	
    if((a[no1]==NULL)||(a[no2]==NULL)) {printf("该多项式为空！");return(-1);}
	poly *p=a[no1]->next,*q=a[no2]->next,*rear,*t;
	int x=-1;

    {if (no1==no3||no2==no3) {x=no3;no3=10;}
	 destroy(no3);//异地存储 
	initlist(a[no3]);
	rear=t=a[no3];
	   while(p&&q){
	   	if (p->cishu<q->cishu){
	   		t=(Linklist)malloc(sizeof(poly));
			t->xishu=p->xishu;
	   		t->cishu=p->cishu;
	   		rear->next=t;
	   		rear=rear->next;
	   		p=p->next;
		    }
		else if(p->cishu==q->cishu){
           	t=(Linklist)malloc(sizeof(poly));
			t->cishu=p->cishu;
	   		t->xishu=p->xishu+q->xishu;
	   		rear->next=t;
	   		rear=rear->next;
	   		p=p->next;q=q->next;
		
			}
		else if(p->cishu>q->cishu)
		   {t=(Linklist)malloc(sizeof(poly));
			t->xishu=q->xishu;
	   		t->cishu=q->cishu;
	   		rear->next=t;
	   		rear=rear->next;
	   		q=q->next;}
	    }
		while(p){
		   t=(Linklist)malloc(sizeof(poly));
		   t->xishu=p->xishu;
		   t->cishu=p->cishu;
		   rear->next=t;
		   rear=rear->next;
		   p=p->next;
		} 
		while(q){
		   t=(Linklist)malloc(sizeof(poly));
		   t->xishu=q->xishu;
		   t->cishu=q->cishu;
		   rear->next=t;
		   rear=rear->next;
		   q=q->next;
		} 
	rear->next=NULL;} 
	//printf("YES");
   {t=a[no3]->next;
	rear=a[no3];
	     while(t)
		 {  if(t->xishu==0) {rear->next=t->next;p=rear->next;t=t->next;free(p);continue;}
		    else rear=rear->next;
		    //printf("+");
		    t=t->next;  }
		    //printf("-");
	if(a[no3]->next==NULL)  {p=(Linklist)malloc(sizeof(poly));p->xishu=0;p->cishu=0;p->next=NULL;a[no3]->next=p;}
	}//检查有无系数为0的结点
	//printf("*"); 
    if(no1==x){copy(10,no1);destroy(10);}
	if(no2==x) {copy(10,no2);destroy(10);}
	return(1);
}
int dec(int no1,int no2,int no3){
	if((a[no1]==NULL)||(a[no2]==NULL)) {printf("该多项式为空！");return(-1);}
	poly *p=a[no1]->next,*q=a[no2]->next,*rear,*t;
	int x=-1;

    {if (no1==no3||no2==no3) {x=no3;no3=10;}
	 destroy(no3);//异地存储 
	initlist(a[no3]);
	rear=t=a[no3];
	   while(p&&q){
	   	if (p->cishu<q->cishu){
	   		t=(Linklist)malloc(sizeof(poly));
			t->xishu=p->xishu;
	   		t->cishu=p->cishu;
	   		rear->next=t;
	   		rear=rear->next;
	   		p=p->next;
		    }
		else if(p->cishu==q->cishu){
           	t=(Linklist)malloc(sizeof(poly));
			t->cishu=p->cishu;
	   		t->xishu=p->xishu-q->xishu;
	   		rear->next=t;
	   		rear=rear->next;
	   		p=p->next;q=q->next;
		
			}
		else if(p->cishu>q->cishu)
		   {t=(Linklist)malloc(sizeof(poly));
			t->xishu=-q->xishu;
	   		t->cishu=q->cishu;
	   		rear->next=t;
	   		rear=rear->next;
	   		q=q->next;}
	    }
		while(p){
		   t=(Linklist)malloc(sizeof(poly));
		   t->xishu=p->xishu;
		   t->cishu=p->cishu;
		   rear->next=t;
		   rear=rear->next;
		   p=p->next;
		} 
		while(q){
		   t=(Linklist)malloc(sizeof(poly));
		   t->xishu=-q->xishu;
		   t->cishu=q->cishu;
		   rear->next=t;
		   rear=rear->next;
		   q=q->next;
		} 
	rear->next=NULL;} 
//printf("YES");	
	   {t=a[no3]->next;
	    rear=a[no3];
	       while(t){
		    if(t->xishu==0) {rear->next=t->next;p=rear->next;t=t->next;free(p);continue;}
		    else rear=rear->next;
		   t=t->next;
	       }
	       if(a[no3]->next==NULL)  {p=(Linklist)malloc(sizeof(poly));p->xishu=0;p->cishu=0;p->next=NULL;a[no3]->next=p;}
	}//检查有无系数为0的结点 
    
	if(no1==x){copy(10,no1);destroy(10);}
	 if(no2==x) {copy(10,no2);destroy(10);}
	return(1);
	
}

int xiangcheng(int no1,int no2,int no3){
	poly *p=a[no1],*q=a[no2],*r,*t,*s;
	int i=0; 
	if(p==NULL||q==NULL){printf("该多项式为空！");return 0;
	}
	copy(no1,17);
	copy(no2,18);
	while(p->next!=NULL){
		p=p->next;
		q=a[18]; 
		while(q->next!=NULL)
		{q=q->next;
		 q->xishu*=p->xishu;
		 q->cishu+=p->cishu;
       	//	 xiangjia1(17,18,19); 
		}
		if(i==0){copy(18,19);i++;
		}
		else {xiangjia1(18,19,19);}
		copy(no2,18);
	}
	copy(19,no3);
	destroy(17);
	destroy(18);
	destroy(19);
}
int xiangchu(int no1,int no2,int no3,int no4){
//	struct poly*Linklist;
	poly *p=a[no1],*q=a[no2],*r,*t,*s,*rear,*m,*rearp,*rearq,*head;
	float c1,c2,x1,x2; 
	int r1,r2;
	if(p==NULL||q==NULL) {printf("该多项式为空！");return 0;
	}
	while(p->next!=NULL){
		p=p->next;
	}
	//printf("p=%f\n",p->cishu);
	while(q->next!=NULL){
		q=q->next;
	}
	//printf("n1"); 
	if(p->cishu>=q->cishu)
		{r1=no1;r2=no2;r=a[no1];c1=p->cishu;c2=q->cishu;x2=q->xishu;x1=p->xishu;}
    else if(p->cishu<q->cishu) 
	   {printf("分子最高次项小于分母最高次项商为0！")
	   ;copy(no1,no4);
	   return 0;}    

    //printf("x1=%0.2f,x2=%0.2f",x1,x2);
	initlist(a[11]);
	initlist(a[12]);
	initlist(a[no3]);
	initlist(a[no4]);
	copy(r2,12);
	copy(r1,11);
	
	t=a[12];
	rear=head=a[no3];
	while(c1>=c2){

		t=a[12];
        r=a[12];
		while(t->next!=NULL){
			t=t->next;
			t->cishu=(c1-c2)+(t->cishu);
			t->xishu=(t->xishu)*(x1/x2); 

		}
        dec(11,12,11);	
		check0(11);
        copy(r2,12);
		s=(Linklist)malloc(sizeof(poly));
		s->cishu=c1-c2;
		s->xishu=x1/x2;
		s->next=head->next;
		head->next=s;
		//rear=rear->next;
		q=a[11];
		if (q==NULL){printf("没有余数！");a[no4]=NULL;destroy(12);return 1;}
		if (c1==c2) {copy(11,no4);destroy(12);return 1;}
	  	while(q->next!=NULL) q=q->next;
		 c1=q->cishu;
		 x1=q->xishu;
		// printf("aa");
	} 
	if(a[11]!=NULL) copy(11,no4);
	if(no3!=11) destroy(11);
	destroy(12);
} 

int common(int no1,int no2,int no3,int no4){
	poly *r,*p=a[no1],*q=a[no2],*t,*t1;
	int no0;
	if(p==NULL||q==NULL) {printf("该多项式为空！");return 0;
	}
	while(p->next!=NULL) p=p->next;
	while(q->next!=NULL) q=q->next;
	if(p->cishu<q->cishu){no0=no1;no1=no2;no2=no0;
	}
	copy(no1,13);
	copy(no2,14);
	xiangchu(13,14,15,16);
	while(a[16]!=NULL){
	//	printf("ok");
		copy(14,13);
		copy(16,14);
		//initlist(a[15]);
		//initlist(a[16]);
		xiangchu(13,14,15,16);
	//	return 1;

		}
	t=a[14];
	while(t->next!=NULL) t=t->next;
	if (t->xishu<0&&t->cishu!=0)
	{t1=a[14];
	while(t1->next!=NULL) {t1=t1->next;t1->xishu*=-1;}
	}
	else if(t->cishu==0){t1=a[14];while(t1->next!=NULL) {t1=t1->next;t1->xishu*=1/(t->xishu);}
	}
    copy(14,no3);
    xiangcheng(no1,no2,51);
    xiangchu(51,14,no4,52); 
	destroy(13);
	destroy(14);
	destroy(15);
	destroy(16);
	destroy(51);
	destroy(52);
}
int Precede(char ch1,char ch2){
	switch (ch1){
	case	'+':{switch(ch2){
			case'+':return 1;
			case'-':return 1;
			case'*':return -1;
			case'/':return -1;
			case'(':return -1;
			case')':return 1;
			case'#':return 1;}break;}
	case	'-':{switch(ch2){
			case'+':return 1;
			case'-':return 1;
			case'*':return -1;
			case'/':return -1;
			case'(':return -1;
		case	')':return 1;
		case	'#':return 1;}break;}
	case	'*':{switch(ch2){
		case	'+':return 1;
			case'-':return 1;
			case'*':return 1;
			case'/':return 1;
			case'(':return -1;
			case')':return 1;
			case'#':return 1;}break;}	
	case	'/':{switch(ch2){
			case'+':return 1;
			case'-':return 1;
			case'*':return 1;
			case'/':return 1;
			case'(':return -1;
			case')':return 1;
			case'#':return 1;}break;}	
	case'(':{switch(ch2){
			case'+':return -1;
		    case'-':return -1;
			case'*':return -1;
			case'/':return -1;
			case'(':return -1;
			case')':return 0;
			case'#':return 1;}break;
			}
	case ')':{switch(ch2){
			case'+':return 1;
			case'-':return 1;
			case'*':return 1;
			case'/':return 1;
			case'(':return 0;
			case')':return 1;
			case'#':return 1;}break;}
	case	'#':{switch(ch2){
			case'+':return -1;
			case'-':return -1;
			case'*':return -1;
			case'/':return -1;
			case'(':return -1;
			case')':return 0;
			case'#':return 0;}break;
		}}
		}	//运算优先关系 
			
	

int mix(){
	poly *q;
	int i;
	char c,th;
	char x;
	int b1,b2;
	int z=23;
	//initlist(a[21]);
	//initlist(a[23]);
	SqStack1 S1;
	SqStack2 S2; 
	num e1;
	cha e2; 
	fflush(stdin);
	printf("输入表达式 数字代表多项式下标#代表输入完成");
	InitStack2(S2);
	Push2(S2,'#');
 	InitStack1(S1);
	c=getchar();
	while(c!='#'||GetTop2(S2)!='#'){
		if(c>='0'&&c<='9') {e1=c-48;
		Push1(S1,e1);
		//printf("e1=%d ",e1);
		c=getchar();
		}
		else 
		switch(Precede(GetTop2(S2),c)){
			case -1:Push2(S2,c);c=getchar();break;
			case 0:Pop2(S2,x);c=getchar();break;
			case 1:Pop2(S2,th);Pop1(S1,b1);Pop1(S1,b2);
		//	printf("%c",th);
			      switch(th){
				  case '+':{
					copy(b1,21);
					copy(b2,22);
					xiangjia1(21,22,z); 
					Push1(S1,z);z++;
					destroy(21);
					destroy(22);
					break;}
				    case '-':{
					copy(b1,21);
					copy(b2,22);
					dec(22,21,z);
					
					Push1(S1,z);
					z++;
					destroy(21);
					destroy(22);
					break;
				  }
				    case '*':{
					copy(b1,21);
					copy(b2,22);
	                xiangcheng(21,22,z);
				    
					Push1(S1,z);z++;
			
					destroy(21);
					destroy(22);
					break;
				  }
				    case '/':{
					copy(b1,21);
					copy(b2,22);	//printf("cuowu");
					xiangchu(22,21,z,50);
					Push1(S1,z);					
					if(a[z]==NULL){printf("0");fflush(stdin);return 0;}
					z++;
					destroy(21);
					destroy(22);
					destroy(50);
					
				    break;
				  }
				  default:{printf("Wrong Input!");
					return 0;
				  }
		}//switchth
	}//switchc
  }//endwhile
   z=z-1;
   q=a[z];//t=q->next;
	while (q->next){
		q=q->next;
		if(q!=a[z]->next){if(q->xishu>0) printf("+%0.2f",q->xishu);
		else printf("%0.2f",q->xishu);
		}
		else printf("%0.2f",q->xishu);
		if(q->cishu==0) ;
		else if(q->cishu==1) printf("x");
		else if(q->cishu>0) printf("x^%0.1f",q->cishu);
		else if(q->cishu<0) printf("x^(%0.1f)",q->cishu);
    }
    for(i=21;i<=z;i++)
    destroy(i);
    return 1;
}


int work(float x){
	poly *q=NULL;
	int k=0;
	float s=0;
	//printf("\n");
	//scanf("%d",&k); 
	while(k>=0&&k<=9){
	q=a[k];
//	if(q==NULL){printf("....");return 0; 
//	}
	if(!q) {k++;continue;}
	    while(q->next){
		   q=q->next;
		   s+=q->xishu*pow(x,q->cishu);
	    }
	printf("当x=%f时 第%d个式子的值为%0.2f\n",x,k,s);
	k++;
	s=0;
}printf("....");return 1;
//return(1);
}

int rec(int no,int p){
	float xi,ci;
	poly *q,*rear,*t;
	q=rear=a[no];t=NULL;
	if(q==NULL){printf("该多项式为空！");return(-1); }
	
	if(p==1)
	   {scanf("%f %f",&xi,&ci);
	    if (xi==0){return 0; }
		while(q->next!=NULL){
			q=q->next;
			if(q->cishu==ci) {printf("已经存在这一次数！");return 0;}
			if((rear!=a[no])&&(ci<q->cishu)&&(rear->cishu<ci)){
				t=(Linklist)malloc(sizeof(poly));
				t->cishu=ci;t->xishu=xi;
				rear->next=t;t->next=q;
			    return(1);
			}
			if((rear==a[no])&&(ci<q->cishu))
			{	t=(Linklist)malloc(sizeof(poly));
				t->cishu=ci;t->xishu=xi;
				rear->next=t;t->next=q;
			    return(1);
			}
		   rear=rear->next;	
		}//endwhile 
	   t=(Linklist)malloc(sizeof(poly));
	   t->cishu=ci;t->xishu=xi;
	   rear->next=t;t->next=NULL;
    }//endif
    else if(p==2){scanf("%f",&ci);
  while(q->next!=NULL){
	      
          q=q->next;
    	  if(ci==q->cishu)
    	   {rear->next=q->next;
             free(q);			
			 return 1; 
		   }   //endifci
		 rear=rear->next;
		}      //endwhile
      printf("没有这一次项！！");
	  return 0;	
	}         //endifp==2 
	else if(p==3){
		scanf("%f",&ci);
		printf("请你输入修改后的非0系数");
		scanf("%f",&xi);
		q=a[no]; 
		while(q->next!=NULL){
			q=q->next;
			if(ci==q->cishu){
				q->xishu=xi;
				return 1;}
		 }
	  printf("没有这一项！！");
	}//endifp==3

}
int revise(int no){
	int y;
	printf("您想要\n1：新增一个次数项 2：删去一个次数项 3：修改一个此数项的系数 4：结束本次操作");
	scanf("%d",&y);
qq:	switch(y){
		case(1):{
			printf("输入你要新增的系数、次数");
		  rec(no,1); 
		}break;
		case(2):{
            printf("输入你要删去的次数项");
          rec(no,2);
		}break;
		case(3):{
			printf("输入你要修改的次数");
		  rec(no,3);
		}break;
		case(4):break;
	goto qq;
	}//endswitch
	
}
int main()
   {int a,no,no1,no2,no3,no4,y;
   float x;
   char ch;
   struct poly *Linklist;
   ep:printf("请输入功能序号\n0 退出\n1 创建多项式\n2 显示多项式\n3 复制多项式\n4 求和\n5 求差\n6 求值\n7 销毁多项式\n8 清空多项式\n9 修改多项式\n10 求商\n11 求公因式和公倍式\n12 求积\n13 四则运算\n");
   scanf("%d",&a);
 //  printf("%d ",a);
   switch (a)
   {case 0:return(0);
   case 1:{printf("请输入存储位置");scanf("%d",&no);create(Linklist,no);}break;
   case 2:print(Linklist);break;
   case 3:{printf("请输入你想复制的多项式");scanf("%d",&no);printf("请输入你想放置的空间");scanf("%d",&no1);copy(no,no1);}break;
   case 4:{printf("您想让哪两个多项式相加呢？");scanf("%d %d",&no1,&no2);printf("你准备把他们放在哪个存储空间？");scanf("%d",&no3);
          xiangjia1(no1,no2,no3);}break; 
   case 5:{printf("您想让哪两个多项式相减呢？");scanf("%d %d",&no1,&no2);printf("你准备把差分别放在哪个存储空间？");scanf("%d",&no3);
   dec(no1,no2,no3);}break;
   case 6:{printf("请输入X的值");scanf("%f",&x);work(x); 
	
   }break;
   case 7:{printf("请输入你想删除的多项式");scanf("%d",&no);destroy(no);}break;
   case 8:{printf("确定要清空所有多项式吗？Y/N\n");fflush(stdin);scanf("%c",&ch);if(ch=='Y') destruct();
		  }break;
   case 9:{printf("你要对第几个多项式进行修改？");scanf("%d",&no);
   revise(no);
	break;
   }
   case 10:{printf("你想让哪两个式子相除？");scanf("%d %d",&no1,&no2);printf("你准备把商和余数分别放在哪个存储空间？");scanf("%d %d",&no3,&no4);
	xiangchu(no1,no2,no3,no4);break;}
   case 11:{printf("你想求哪两个式子的公因式和公倍式？");scanf("%d %d",&no1,&no2);printf("你准备把最大公因式和最小公倍式分别放在哪个存储空间？") ;scanf("%d %d",&no3,&no4);
    common(no1,no2,no3,no4);break;}
   case 12:{printf("你想求哪两个式子的乘积？");scanf("%d %d",&no1,&no2);printf("你准备把他们的乘积放在？");scanf("%d",&no3); 
    xiangcheng(no1,no2,no3);	break;
   }
   case 13:mix();
	break;
   }
   
   
   goto ep;
}

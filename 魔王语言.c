#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define Stack_Init_Size 100
#define STACKINCREMENT 10
#define   Elemtype  char
#define  OK 1
typedef struct{
    char *base;
    char *top;//ջ��ָ�� 
    int stacksize;//ջ�Ĵ�С 
} Sqstack;
int init(Sqstack *s){//����ջ 
	s->base=(char*)malloc(Stack_Init_Size*sizeof(char));
	if(!s->base){
		printf("����ռ�ʧ��\n");
		return;
	}
	s->top=s->base;
	s->stacksize=Stack_Init_Size;
	return 1;
}
char  Pop(Sqstack *s,char *e){//ɾ��ջ��Ԫ�ز���e�洢��ֵ 
    if(s->top==s->base)
        return 0; 
    --s->top;
    *e=*s->top;
    return *e;
}
int Push(Sqstack *s,char e){//����ջ��Ԫ��
	if(s->top-s->base>=s->stacksize){
		s->base=(Elemtype*)realloc(s->base,(s->stacksize+STACKINCREMENT)*sizeof(Elemtype));
		if(!s->base){
			printf("����洢�ռ�ʧ��\n");
			return ;
		}
		s->top=s->base+s->stacksize;
		s->stacksize+=STACKINCREMENT;
	} 
	*(s->top)=e;
	s->top++;
	return OK;
}
char  GetTop(Sqstack *s,char *e){
	--s->top;
	e=s->top;
	return *e;
}
int main(){
	Sqstack s;
	init(&s);//����ջ 
	char a[100],b[100],c[100],f[100],d[100];
	char c1,c2,c3;
	printf("���������һ��\n");
	scanf("%c->%s",&c1,a) ;//B->tAdA
	getchar();
	scanf("%c->%s",&c2,b);//A->sae
	getchar();
	int len_a=strlen(a);
	int len_b=strlen(b);
	int f_len=0;
	int i,j;
	for(i=0;i<len_a;i++) {
		if(a[i]==c2)
		    for(j=0;j<len_b;j++){
		    	f[f_len++]=b[j];
			}
		else if(a[i]!=c2)
		    f[f_len++]=a[i];
	}
//	printf("������ħ������\n");//B(ehnxgz)B 
	gets(c);
	int len_c=strlen(c);
	for(i=len_c-1;i>0;i--){//��ջ 
		Push(&s,c[i]);
}
	char e;
	int flag=0;
	int d_len=0;
	//printf("����������Ϊ\n");//���ж�ջԪ�صĲ��� 
	for(i=0;i<len_c;i++){
		//GetTop(&s,&e);
		Pop(&s,&e); 
		if(flag==1){
			d[d_len++]=e;
		}
		if(e==c1&&flag==0)
		    printf("%s",f);
		else if(e==c2&&flag==0)
		    printf("%s",b);
		else if(e=='('&&flag==0){
			c3=c[i+1];
			flag=1;	
		}
		else if(e==')'){
			flag=0;
			for( j=d_len-1;j>0;j--){//ȥ��'(',')'�����ַ� 
				if(j)
					printf("%c%c",c3,d[j]);
			    else
			        printf("%c",d[j]);
			}
		}
		else if(flag!=1)
		    printf("%c",e);
	}
	putchar('\n');
	return 0;
}


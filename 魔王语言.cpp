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
    char *top;//栈顶指针 
    int stacksize;//栈的大小 
} Sqstack;
int init(Sqstack *s){//建立栈 
	s->base=(char*)malloc(Stack_Init_Size*sizeof(char));
	if(!s->base){
		printf("申请空间失败\n");
		exit(0);
	}
	s->top=s->base;
	s->stacksize=Stack_Init_Size;
	return 1;
}
char  Pop(Sqstack *s,char *e){//删除栈顶元素并用e存储其值 
    if(s->top==s->base)
        return 0; 
	--s->top;
    *e=*s->top;
    
    return *e;
}
int Push (Sqstack *S, char c)
{ //入栈?
	char *p;
	if (S->top - S->base >= S->stacksize)
	{
		p = (char *)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof (char)) ;
		if (!p) exit(0);
		S->base = p;
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	* (S->top )= c;
	S->top++;
	return 1;
}
char  GetTop(Sqstack *s,char e){
	e=*(s->top);
	return e;
}
int main(){
	Sqstack s;
	init(&s);
	Push(&s,'a');
	char e;
	Pop(&s,&e);
	printf("%c\n",e);
}

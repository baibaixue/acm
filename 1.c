#include<stdio.h>
int main(){
	char a,b,c,t;
	scanf("%c %c %c%*c",&a,&b,&c);//输入三个字符 
	if(a>b){
		t=a;a=b;b=t;//将三个字符排序 
	}if(b>c){
		t=b;b=c;c=t;
	}
	printf("%c %c %c",a,b,c);//输出 
	return 0;
}

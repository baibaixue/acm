#include<stdio.h>
int main(){
	char a,b,c,t;
	scanf("%c %c %c%*c",&a,&b,&c);//���������ַ� 
	if(a>b){
		t=a;a=b;b=t;//�������ַ����� 
	}if(b>c){
		t=b;b=c;c=t;
	}
	printf("%c %c %c",a,b,c);//��� 
	return 0;
}

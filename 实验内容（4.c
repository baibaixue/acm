//10��29�գ���ѩ���ж�m�Ƿ���a��b֮�� 
#include<stdio.h>
int main(){
	int m,a,b;
	int x;
	scanf("%d%d%d",&m,&a,&b); //����ʵ�� 3 7 5 
	if(a>b){
		x=(m<a)&&(m>b);
	} else{
		x=(m<b)&&(m>a);
	}
	printf("%d",x);//��� 7 
	return 0; 
} 

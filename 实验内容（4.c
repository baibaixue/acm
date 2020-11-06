//10月29日，白雪，判断m是否在a，b之间 
#include<stdio.h>
int main(){
	int m,a,b;
	int x;
	scanf("%d%d%d",&m,&a,&b); //测试实例 3 7 5 
	if(a>b){
		x=(m<a)&&(m>b);
	} else{
		x=(m<b)&&(m>a);
	}
	printf("%d",x);//结果 7 
	return 0; 
} 

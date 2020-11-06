//10月29日，白雪，身份验证
#include<stdio.h>
int main(){
	int x;
	scanf("%d",&x);//测试数据3333 
	switch(x){
		case 0000:printf("特许用户\n");break;
		case 1111:printf("授权用户\n");break;
		case 1234:printf("普通用户\n");break;
		default:
			printf("非法用户\n");//结果非法用户 
	}
	return 0;
} 

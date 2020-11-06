//10月29号，白雪，计算多项式的值
#include<stdio.h>
#include<math.h>
int main(){
	int i,j,n,s;
	double x,res=0;
	printf("please input x,n:\n");
	scanf("%lf%d",&x,&n);//测试数据 3 5 
	for(j=1;j<=n;j++){//从第一项到第n项 
		s=1;
		for(i=1;i<=j+1;i++){
			s*=i;//求（n+1)的阶乘 
		}
		res+=pow(x,(double)j)/s;//x的项数次方除以阶乘 
	}
	printf("%.3f\n",res);//输出数据 5.138 
	return 0;
} 

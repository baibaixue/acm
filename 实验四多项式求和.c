//10��29�ţ���ѩ���������ʽ��ֵ
#include<stdio.h>
#include<math.h>
int main(){
	int i,j,n,s;
	double x,res=0;
	printf("please input x,n:\n");
	scanf("%lf%d",&x,&n);//�������� 3 5 
	for(j=1;j<=n;j++){//�ӵ�һ���n�� 
		s=1;
		for(i=1;i<=j+1;i++){
			s*=i;//��n+1)�Ľ׳� 
		}
		res+=pow(x,(double)j)/s;//x�������η����Խ׳� 
	}
	printf("%.3f\n",res);//������� 5.138 
	return 0;
} 

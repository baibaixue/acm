#include<stdio.h>
int main(){
	int d,h,m;
	int sum;
	printf("please input days,hours and minutes.\n");//��ʾ��� 
	scanf("%d%d%d",&d,&h,&m);//���� 
	sum=d*24*60+h*60+m;//���� 
	printf("%d",sum);//��� 
	return 0;
}

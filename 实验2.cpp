#include<stdio.h> 
int main(){
	int a;//����һ�����ͱ���
	printf("please input an int:");//��ʾ��� 
	scanf("%d",&a);//��ֵ
	printf("%d\n",a);//��ӡ 
	double b;//����һ��ʵ�ͱ��� 
	printf("please input a double:");//��ʾ��� 
	scanf("%lf",&b);//��ֵ
	printf("%.2f\n",b);//������λС�����
	char n,m;//���������ַ�����
	printf("please input two chars:");//��ʾ���
	scanf("%c %c",&n,&m);//��ֵ 
	printf("%d\n",n+m);//��������ʽ���
	printf("%c\n",n+m);//���ַ���ʽ���
	return 0; 
	 
}

#include<stdio.h>
int main(){
	double e,m;
	printf("please input english score:");
	scanf("%lf",&e);//����Ӣ��ɼ� 
	printf("please input math score:");
	scanf("%lf",&m);//������ѧ�ɼ� 
	printf("averange score:%.2f\n",(e+m)/2.0);//���ƽ���ɼ� 
	return 0;
} 
